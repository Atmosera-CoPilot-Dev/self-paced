var path = require('path');

var express = require('express');
var morgan = require('morgan');

var app = express();

if (app.get('env') === 'development') {
    app.use(morgan('dev'));
}

app.use('/bootstrap', express.static(path.join(__dirname, 'node_modules/bootstrap/dist')));

app.use(express.static(path.join(__dirname, 'public')));

var port = process.env.PORT || 1337;

app.listen(port, function() {
    console.log('http://127.0.0.1:%d/', port);
});
