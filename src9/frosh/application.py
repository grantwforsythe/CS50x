import os

from cs50 import SQL
# from flask_mail import Mail, Message
from flask import Flask, render_template, request, redirect

app = Flask(__name__)
"""
    There is a lot to configure when setting up emails.

    To set up environment variables in Linux use the export command.

    Ex:

    export MAIL_DEFAULT_SENDER="grantwforsythe@gmail.com"

"""
# app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
# app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
# app.config["MAIL_PORT"] = 587  # gmail
# app.config["MAIL_SERVER"] = "smtp.gmail.com"
# app.config["MAIL_USE_TLS"] = True
# app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
# mail = Mail(app)


db = SQL("sqlite:///froshims.db")

SPORTS = [
        "Dodgeball",
        "Flag Football",
        "Soccer",
        "Volleyball",
        "Ultimate Frisbee"
]


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    if not name:
        render_template("error.html", message="Missing name")

    sport = request.form.get("sport")
    if not sport:
        render_template("error.html", message="Missing sport")

    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)

    # message = Message("You are registered!")

    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    # returns each row as a dictionary
    registrants = db.execute("SELECT * FROM registrants")

    return render_template("registraints.html", registrants=registrants)