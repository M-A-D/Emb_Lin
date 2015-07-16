# all the imports
import sqlite3
import os
from flask import Flask, request, session, g, redirect, url_for, \
     abort, render_template, flash
from contextlib import closing

#httpserver
app = Flask(__name__)
app.config.from_object('config')

@app.route('/')
def show_index():
    print os.getcwd()
    if os.path.isfile('static/hint.txt'):
        with open('static/hint.txt', 'rb') as f:
	    hint = f.read().decode('utf-8')
    else:
	hint = ''
    return render_template('index.html', enabled_upload = os.path.isfile('static/enable_upload.txt'), hint = hint )

@app.route('/upload', methods=['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        file = request.files['file']
        if file:
	    if file.filename == 'disable_upload.txt':
		os.remove('static/enable_upload.txt')
	    elif file.filename == 'clear_uploads.txt':
		for f in os.listdir('static'):
		    os.remove(os.path.join('static',f))
	    else:
                file.save(os.path.join('static', file.filename))
            return redirect('/list')
    return render_template('upload.html')

@app.route('/list')
def show_list():
    files = [x for x in os.listdir('static') if x != 'enable_upload.txt' and x != 'hint.txt']
    return render_template('list.html',files=files)

if __name__ == '__main__':
    app.run(host = '0.0.0.0')
