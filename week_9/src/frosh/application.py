from flask import Flask, render_template, request

app = Flask(__name__)

REGISTRAINTS = {}

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

    # store the form data
    REGISTRAINTS[name] = sport

    return render_template("registraints.html", name=name, sport=sport)