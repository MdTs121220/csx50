import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

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
#start block buy def
#get method post
 if request.method == "POST":

        #check stock
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        #check shares
        elif not request.form.get("shares"):
            return apology("must provide shares")

        #to check shares >0
        elif int(request.form.get("shares")) < 0:
            return apology("must provide a valid number of shares")

        #Check stock exsist
        if not request.form.get("symbol"):
            return apology("must provide an existing symbol")

        #lookup
        symbol = request.form.get("symbol").upper()
        stock = lookup(symbol)
        if stock is None:
            return apology("symbol does not exist")

        #price trx
        shares = int(request.form.get("shares"))
        transactionb = shares * stock['price']

        #check user cash
        user_cash = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        cash = user_cash[0]["cash"]

        #formula subs user cash
        updt_cash = cash - transactionb

        #update user cash
        if updt_cash < 0:
            return apology("you do not have enough cash")

        # Update cash user after the transaction
        db.execute("UPDATE users SET cash=:updt_cash WHERE id=:id", updt_cash=updt_cash, id=session["user_id"]);
        # Update to table
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (:user_id, :symbol, :shares, :price)", user_id=session["user_id"], symbol=stock['symbol'], shares=shares, price=stock['price'])
        flash("Bought!")
        return redirect("/")

    # redirect user
    else:
        return render_template("buy.html")

#end block buy


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
            return apology("You must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("You must provide password", 403)

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
    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
##block route register
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # Ensure password was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide password confirmation")

        # Ensure confirmation password is equal to password
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password dont match")
        try:
            # Add into db
            new_user = db.execute("INSERT INTO users (username, hash) VALUES (?,?)", request.form.get("username"), generate_password_hash(request.form.get("password")))

        except:
            # Check if its unique
            return apology("username is already registered")

        # Remember the user
        session["user_id"] = new_user

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")

##endblock route register



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
