import json 
import csv


dati = """
    [
        {"id":1, "aula": "MM2", "giorno": "2024-01-23", "ora":"10:23", "valore": "20.5" },
        {"id":2, "aula": "MM2", "giorno": "2024-01-23", "ora":"10:23", "valore": "20.5" },
        {"id":3, "aula": "MM2", "giorno": "2024-01-23", "ora":"10:23", "valore": "20.5" },
        {"id":4, "aula": "MM2", "giorno": "2024-01-23", "ora":"10:23", "valore": "20.5" },
        {"id":5, "aula": "MM2", "giorno": "2024-01-23", "ora":"10:23", "valore": "20.5" }
    ]
"""

data = []

with open("dati.csv", "r") as csv_file:
    csvreader = csv.reader(csv_file)
    for row in csvreader :
        data.append(row)


json_data = json.dumps(data)

with open('misurazioni.json', 'w') as json_file :
    json_file.write(json_data)