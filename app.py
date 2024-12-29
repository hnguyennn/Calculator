from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('calculator.html')

@app.route('/calculate')
def calculate():
    return render_template('calculate.html')  

@app.route('/help')
def help():
    return render_template('help.html')  

@app.route('/history-log')
def history_log():
    return render_template('history_log.html')  

@app.route('/update-log')
def update_log():
    return render_template('update_log.html')  

if __name__ == "__main__":
    app.run(debug=True)
