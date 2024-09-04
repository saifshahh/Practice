import json

data = {
    "Name": "Saif",
    "File": "JSON"
}

with open("practice.json", 'r+') as f:
    json.dump(data, f)

    f.seek(0)
    content = json.load(f)
    print(content)
