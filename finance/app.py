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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # use post method
	if request.method == "POST":
        # check user entry symbol and shares
		if not (symbol := request.form.get("symbol")):
            return apology("Wrong or blank symbol")
        elif not (shares := request.form.get("shares")):
            return apology("Wrong or blank shares")

        # Check share type data
        try:
            shares = int(shares)
        except ValueError:
            return apology("Wrong type share must number")

        # Check shares > 0
        elif not (shares > 0):
            return apology("Wrong type share must postive number")

        # db exceute user session
		rows = db.execute("SELECT * FROM users WHERE id = ?;", session["user_id"])

        user_owned_cash = rows[0]["cash"]
        total_prices = query["price"] * shares

        # Check user have money enough
        if user_owned_cash < total_prices:
            return apology("You don't have a cash again")

        # check realtime
        tgldate = datetime.datetime.now()

        # Execute a transaction table
        db.execute("INSERT INTO transactions(user_id, symbol, shares, price, tgldate) VALUES(?, ?, ?, ?, ?);",
                   session["user_id"], query["name"], symbol, shares, query["price"], tgldate)

        # Update user cash
        db.execute("UPDATE users SET cash = ? WHERE id = ?;",
                   (user_owned_cash - total_prices), session["user_id"])

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

    # User reached route via GET (as by clicking a link or via redirect)
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
    # use post method
    if request.method == "POST":

        # check symbol entry
        if not (query := lookup(request.form.get("symbol"))):
            return apology("Wrong symbol")

        return render_template("quote.html", query=query)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
     # use POST method
    if request.method == "POST":

        # check user entry username
        if not request.form.get("username"):
            return apology("username blank")

        # check user entry password
        elif not request.form.get("password") or not request.form.get("confirmation"):
            return apology("must entry your password")

        # check passwords match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match")

        # chek username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        if len(rows) >= 1:
            return apology("username already exists")

        # add user to db
        db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                    username=request.form.get("username"),
                    hash=generate_password_hash(request.form.get("password")))

        # remember session id user
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        session["user_id"] = rows[0]["id"]

        # redirect to home page
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
