from flask import Flask,  make_response, request
import json 
import csv

app = Flask(__name__)

lista_dati = []

def scan():
    with open("dati.csv", "r") as read_obj:
        csvreader = csv.reader(read_obj)
        for row in csvreader :
            id = row[0]
            aula = row[1]
            giorno = row[2]
            ora = row[3]
            valore = row[4]
            test_dict = {
                "id" : id,
                "aula" : aula,
                "giorno" : giorno,
                "ora" : ora,
                "valore" : valore
            }
            lista_dati.append(test_dict)

    dati_json = json.dumps(lista_dati)

    print(dati_json)

    return dati_json


@app.route("/")
def index():
    response = app.response_class(
        response=scan(),
        mimetype='application/json'
    )
    response.headers.add("Access-Control-Allow-Origin", "*")
    return response 


@app.route("/add")
def add():
    response = app.response_class(
    response=0,
    )
    # recupero i dati
    get_aula = request.args.get("aula")
    get_valore = request.args.get("valore")
    # scrivi i dati su un file
    with open("dati.csv", "a") as write_obj:
        linea = "200," + get_aula +  "," + "febbraio" + ","  + "10:55" +  "," + get_valore + "\n"
        write_obj.writelines (linea)
    #     csvwriter = csv.writer(write_obj)
    #     test_add_dict = {
    #         200,
    #         get_aula,
    #         "febbraio",
    #         "10:15",
    #         get_valore
    #     }
    #     csvwriter.writerow(test_add_dict)
    response.headers.add("Access-Control-Allow-Origin", "*")
    return response 
