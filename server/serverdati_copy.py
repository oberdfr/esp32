from flask import Flask,  make_response
import json 
import csv

app = Flask(__name__)

dati = """["""

with open("dati.csv", "r") as read_obj:
    csvreader = csv.reader(read_obj)
    for row in csvreader :
        id = row[0]
        aula = row[1]
        giorno = row[2]
        ora = row[3]
        valore = row[4]
        print(id)
        print(aula)
        print(giorno)
        print(ora)
        print(valore)
        test_dict = {
            "id" : id,
            "aula" : aula,
            "giorno" : giorno,
            "ora" : ora,
            "valore" : valore
        }
        test_string = json.dumps(test_dict)
        print(test_string)
        dati += f""",{test_string}"""
    dati += """]"""

print(dati)


@app.route("/")
def index():
    response = app.response_class(
        response=dati,
        mimetype='application/json'
    )
    response.headers.add("Access-Control-Allow-Origin", "*")
    return response
