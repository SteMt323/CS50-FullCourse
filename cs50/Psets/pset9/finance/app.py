import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd, integers

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
    user_id = session["user_id"]
    user_history = db.execute('''SELECT id_user, symbol, name, SUM(shares)
                              FROM transactions
                              WHERE id_user = ?
                              GROUP BY symbol
                              HAVING SUM(shares) < 0
                              ORDER BY price DESC''',user_id)

    user_cash = db.execute("SELECT * FROM users WHERE id = ?",user_id)
    current_cash = 0
    for stock in user_history:
        stocks = lookup(stock["symbol"])
        stock["price_s"] = stocks["price"]
        stock["total"] = stocks["price"] * stock["SUM(shares)"]
        current_cash += stock["total"]

    return render_template("index.html", user_history=user_history, user_cash=user_cash, current_cash=current_cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method != "POST": return render_template("buy.html")
    symbol = request.form.get("symbol")
    shares = request.form.get("shares")

    if symbol == "":
        return apology("Missiong symbol",400)
    if shares == "" or shares.isalpha():
        return apology("Missiong shares",400)
    #if not integers(shares):
     #   return apology("Only integers",400)
    if '-' in shares or '.' in shares:
        return apology("Only integers",400)
    stocks = lookup(symbol)
    if not stocks:
        return apology("Symbol is not Valid",400)

    #No sé que sucede aqui, share no soporta la conversion a entero
    #Tampoco almacenandolo a una variable entera lo soporta
    #Y no se puede multiplicar si no es entero.
    #mismo problema sucede donde valido con la funcion integers, busque varias soluciones y no encontre ni una
    stock = float(stocks["price"])

    total = float(shares) * stock
    user_id = session["user_id"]
    user_cash = db.execute("SELECT * FROM users WHERE id = ?", user_id)
    if user_cash[0]["cash"] < total:
        return apology("Can not afford",400)

    db.execute('''INSERT INTO transactions (id_user,symbol,name,shares,price)
               VALUES (?, ?, ?, ?, ?)''', user_id, stocks["symbol"],stocks["name"], shares, stock)

    cash = user_cash[0]["cash"]
    db.execute("Update users SET cash = ? WHERE id = ?", cash - total, user_id)
    flash('Bought!')
    return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_history = db.execute('''SELECT id_user, symbol, shares, price, purchase_date
                              FROM logs
                              WHERE id_user = ?
                              ORDER BY purchase_date''',session["user_id"])

    return render_template("history.html",user_history=user_history)


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
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
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
    if request.method != "POST": return render_template("quote.html")
    symbol = request.form.get("symbol")
    if symbol == "":
        return apology("Input is empty",400)
    stocks = lookup(symbol)
    if not stocks:
        return apology("Symbol is not valid",400)
    return render_template("quoted.html", symbol = stocks)




@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    if request.method != "POST": return render_template("register.html")

    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    rows = db.execute("SELECT * FROM users WHERE username = ?", username)
    if len(rows)>=1:
        return apology("User already exist",400)
    if username == "":
        return apology ("username is empty, please complete the input", 400)

    if password == "" or confirmation == "" or not (password == confirmation):
        return apology("inputs are not valid, complete the inputs", 400)

    hashes = generate_password_hash(password, method='pbkdf2:sha256', salt_length=8)
    db.execute('''INSERT INTO users (username, hash) VALUES(?, ?)''', username, hashes)

    return redirect("/")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_history = db.execute('''SELECT id_user, symbol, SUM(shares)
                              FROM transactions
                              WHERE id_user = ?
                              GROUP BY symbol
                              HAVING SUM(shares)>0''', session["user_id"])

    if request.method != "POST": return render_template("sell.html", user_history=user_history)

    symbol = request.form.get("symbol")
    shares = request.form.get("shares")
    if symbol == "":
        return apology("Invalid symbol", 400)
    if shares == "" or shares.isalpha():
        return apology("Invalid shares", 400)
    if not (integers(shares)) or int(shares) <= 0:
        return apology("Only positive integers", 400)
    stock = lookup(symbol)
    if not stock:
        return apology("Invalid symbol", 400)
    user_cash = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    cash = user_cash[0]["cash"]

    if user_history[0]["SUM(shares)"] < int(shares):
        return apology("Too many shares", 400)
    total = stock['price'] * int(shares)

    if cash < total:
        return apology("Can't afford",400)
    db.execute("UPDATE user SET cash = ? WHERE id = ?",cash+total,session["user_id"])

    db.execute('''INSERT INTO transactions (id_user,symbol,name,shares,price)
               VALUES (?,?,?,?,?)''', session["user_id"], stock["symbol"], stock["name"], shares, stock["price"])
    flash('Sold!')
    return redirect("/")


