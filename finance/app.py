import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Query the database for portfolio and cash
    portfolio = db.execute("SELECT symbol, SUM(shares) as shares FROM purchases WHERE user_id = :user_id GROUP BY symbol HAVING SUM(shares) > 0", user_id=session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])[0]["cash"]

    # Create a list of dicts for information stock
    stocks = []
    total = 0
    for row in portfolio:
        symbol = row["symbol"]
        shares = row["shares"]
        quote = lookup(symbol)
        value = quote["price"] * shares
        stocks.append({
            "symbol": symbol,
            "name": quote["name"],
            "shares": shares,
            "price": usd(quote["price"]),
            "value": usd(value)
        })
        total += value

    # Render index.html with the stocks and display total information
    return render_template("index.html", stocks=stocks, cash=usd(cash), total=usd(total+cash))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Check symbol submit
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)

        # Look up price
        quote = lookup(request.form.get("symbol"))
        if not quote:
            return apology("invalid symbol", 403)

        # Check shares submit
        try:
            shares = int(request.form.get("shares"))
            if shares <= 0:
                raise ValueError
        except (TypeError, ValueError):
            return apology("must provide positive integer for shares")

        # Get current ballance
        rows = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])
        if len(rows) != 1:
            return apology("error getting cash balance", 403)
        cash = rows[0]["cash"]

        # Calculate total cost of shares
        total_cost = shares * quote["price"]

        # Check user can afford purchase
        if cash < total_cost:
            return apology("insufficient funds", 403)

        # Record purchase in new table
        db.execute(
            "INSERT INTO purchases (user_id, symbol, price, shares, timestamp) VALUES (:user_id, :symbol, :price, :shares, :timestamp)",
            user_id=session["user_id"],
            symbol=quote["symbol"],
            price=quote["price"],
            shares=shares,
            timestamp=datetime.datetime.now()
        )

        # Update user cash
        db.execute("UPDATE users SET cash = cash - :total_cost WHERE id = :user_id", total_cost=total_cost, user_id=session["user_id"])

        # Redirect to home page
        flash("Shares purchased!")
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")


    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 400)

        quote_data = lookup(symbol)
        if quote_data is None:
            return apology("invalid symbol", 400)

        return render_template("quoted.html", quote_data=quote_data)

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure password confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide password confirmation", 400)

        # Ensure password and confirmation match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords must match", 400)

        # Hash the password
        hash = generate_password_hash(request.form.get("password"))

        # Insert the new user into users
        result = db.execute("INSERT INTO users (username, hash) VALUES(?, ?)",
                            request.form.get("username"), hash)

        # Check if username already exists
        if not result:
            return apology("username already exists", 400)

        # Remember user has login
        session["user_id"] = result

        # Redirect user to home page
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        # Try to get form data
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Ensure symbol and shares were submitted
        if not symbol or not shares:
            return apology("must select stock and specify number of shares to sell", 400)

        # Ensure shares is a positive integer
        try:
            shares = int(shares)
            if shares <= 0:
                raise ValueError
        except ValueError:
            return apology("number of shares must be a positive integer", 400)

        # Query the database for the user's shares of the selected stock
        rows = db.execute("SELECT SUM(shares) as total_shares FROM purchases WHERE user_id = :user_id AND symbol = :symbol GROUP BY symbol", user_id=session["user_id"], symbol=symbol)

        # Ensure the user owns enough shares of the selected stock
        if not rows or rows[0]["total_shares"] < shares:
            return apology(f"you don't own {shares} share{'s' if shares != 1 else ''} of {symbol}", 400)

        # Lookup the current price of the selected stock
        quote = lookup(symbol)

        # Calculate the total value of the sold shares
        value = quote["price"] * shares

        # Subtract the sold shares from the user's portfolio in the database
        db.execute("INSERT INTO purchases (user_id, symbol, shares, price) VALUES (:user_id, :symbol, :shares, :price)", user_id=session["user_id"], symbol=symbol, shares=-shares, price=quote["price"])

        # Add the sold shares' value to the user's cash balance in the database
        db.execute("UPDATE users SET cash = cash + :value WHERE id = :user_id", value=value, user_id=session["user_id"])

        flash(f"Sold {shares} share{'s' if shares != 1 else ''} of {symbol} for {usd(value)}.")

        # Redirect the user to the home page
        return redirect("/")
    else:
        # Get the symbols of the stocks the user owns and that have at least 1 share
        symbols = [row["symbol"] for row in db.execute("SELECT symbol FROM purchases WHERE user_id = :user_id GROUP BY symbol HAVING SUM(shares) > 0", user_id=session["user_id"])]

        return render_template("sell.html", symbols=symbols)
