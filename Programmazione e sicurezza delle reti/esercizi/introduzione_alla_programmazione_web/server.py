from flask import Flask, Response, request
import json

app = Flask(__name__)

# hint: http://ip-dominio:porta/login
@app.route('/login', methods=['POST'])
def login():
    data = request.form
    username = data.get('username')
    password = data.get('password')
    
    if username == 'admin' and password == 'Test1234.':
        resp = Response("OK", status=200)
        resp.headers['Access-Control-Allow-Origin'] = '*'
        return resp
    else:
        resp = Response("Invalid Credentials", status=403)
        resp.headers['Access-Control-Allow-Origin'] = '*'
        return resp

# hint: http://ip-dominio:porta/studenti
@app.route('/studenti', methods=['GET'])
def student():
    students = [
        {'name': 'Mario', 'surname': 'Rossi'},
        {'name': 'Giuseppe', 'surname': 'Verdi'},
        {'name': 'Marco', 'surname': 'Bianchi'}
    ]
    resp = Response(response=json.dumps(students), mimetype='application/json')
    resp.headers['Access-Control-Allow-Origin'] = '*'

    return resp

if __name__ == "__main__":
    app.run(host='0.0.0.0', debug=True, port=5555)