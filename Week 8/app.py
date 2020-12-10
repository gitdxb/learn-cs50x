import os
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached


@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Which stock they own
    stocks = db.execute(
        "SELECT symbol,company_name, SUM(shares), price, total FROM portfolio WHERE user_id= :user_id GROUP BY symbol ORDER BY symbol ASC", user_id=session["user_id"])
    total_cash_earn = 0
    for stock in stocks:
        symbol = stock["symbol"]
        shares = stock["SUM(shares)"]
        quote = lookup(symbol)
        total_shares_value = quote["price"] * shares
        total_cash_earn += total_shares_value
        db.execute("UPDATE portfolio SET price= :price, total= :total_shares_value WHERE user_id= :user_id AND symbol= :symbol",
                   price=quote["price"], total_shares_value=total_shares_value, user_id=session["user_id"], symbol=symbol)
    current_cash_balance = db.execute("SELECT cash FROM users WHERE id=2")
    current_cash_balance = current_cash_balance[0]['cash']
    grand_total = current_cash_balance + total_cash_earn
    return render_template("index.html", stocks=stocks, current_cash_balance=current_cash_balance, total_cash_earn=usd(total_cash_earn), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = lookup(request.form.get("symbol").upper())
        price = float(symbol["price"])
        if not symbol:
            return apology("Need a valid symbol")
        shares = request.form.get("shares")
        if not shares:
            return apology("You didn't put any shares")
        if int(shares) < 0:
            return apology("Invalid number of shares")
        totalBuy = float(shares) * price
        cash = db.execute(
            "SELECT cash FROM users WHERE id= :user_id", user_id=session["user_id"])
        if totalBuy > cash[0]["cash"]:
            return apology("You're out of money!")
        cashBalance = cash[0]["cash"] - totalBuy
        db.execute(
            f"UPDATE users SET cash = {cashBalance}  WHERE id = :user_id", user_id=session["user_id"])
        id = db.execute("SELECT id FROM users WHERE id = :user_id",
                        user_id=session["user_id"])
        db.execute("INSERT INTO portfolio (user_id, symbol,company_name, shares, price, total) VALUES (?, ?, ?, ?, ?, ?)",
                   id[0]["id"], symbol["symbol"], symbol["name"], shares, price, totalBuy)
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
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

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
    if request.method == "POST":
        stockSymbol = lookup(request.form.get("symbol").upper())
        if not stockSymbol:
            return apology("Invalid symbol")
        return render_template("quoted.html", stockSymbol=stockSymbol, usd=usd(stockSymbol["price"]))
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        if not username:
            return apology("No username detected")
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))
        if rows:
            return apology("Username already existed.")
        password = request.form.get("password")
        if not password:
            return apology("Need to enter a password")
        confirmation = request.form.get("confirmation")
        if not confirmation:
            return apology("You need to enter your password again")
        if password != confirmation:
            return apology("Same passwords needed")
        db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                   username=username, hash=generate_password_hash(password))
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "POST":
        stock_to_sell = request.form.get("symbol")
        shares_to_sell = int(request.form.get("shares"))
        if not stock_to_sell:
            return apology("Missing symbol")
        elif not shares_to_sell:
            return apology("Missing number of shares")

        # Query to retrieve the shares from DB
        shares = db.execute("SELECT shares FROM portfolio WHERE user_id = :user_id AND symbol=:symbol",
                            user_id=session['user_id'], symbol=stock_to_sell)
        print("THIS STOCK I GOT IN TOTAL: ",
              shares[0]['shares'], stock_to_sell)
        shares_balance = shares[0]['shares'] - shares_to_sell
        print("WHAT I HAVE LEFT IS: ", shares_balance)
        # If not enough shares to sell, say sorry
        if shares_to_sell > shares[0]['shares']:
            return apology("You don't have enough shares to sell")

        # Update a sell
        db.execute("UPDATE portfolio SET shares=:shares  WHERE user_id=:user_id AND symbol=:symbol",
                   shares=shares_balance, user_id=session["user_id"], symbol=stock_to_sell)

        # Query to get cash balance
        cash = db.execute(
            "SELECT cash FROM users WHERE id= :user_id", user_id=session["user_id"])
        print("CASH BEFORE: ", cash[0]['cash'])
        cash_balance = cash[0]['cash'] * float(shares_to_sell)
        print("CASH AFTER: ", cash_balance)
        db.execute("UPDATE users SET cash = :cash  WHERE id = :user_id",
                   cash=cash_balance, user_id=session["user_id"])
        if shares[0]['shares'] == 0:
            db.execute("DELETE FROM portfolio WHERE user_id=:id AND symbol=:symbol",
                       id=session["user_id"], symbol=stock["symbol"])
        return redirect("/")
    else:
        stocks = db.execute(
            "SELECT symbol,company_name, shares, price, total FROM portfolio WHERE user_id= :user_id GROUP BY symbol ORDER BY symbol ASC", user_id=session["user_id"])
        return render_template("sell.html", stocks=stocks)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
