var path = require('path');

var express = require('express');
var morgan = require('morgan');
var bodyParser = require('body-parser');

var app = express();

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

if (app.get('env') === 'development') {
    app.use(morgan('dev'));
}

var items = [
    { id: 1, value: 'item one' },
    { id: 2, value: 'item two' },
    { id: 3, value: 'item three' }
];

app.get('/', function(req, res) {
    res.render('index', { items: items });
});

app.post('/add', bodyParser.urlencoded(), function(req, res) {
    items.push({
        id: items.length,
        value: req.body.value
    });

    res.redirect('/');
});

app.use('/bootstrap', express.static(path.join(__dirname, 'node_modules/bootstrap/dist')));

app.use(express.static(path.join(__dirname, 'public')));

var port = process.env.PORT || 1337;

app.listen(port, function() {
    console.log('http://127.0.0.1:%d/', port);
});
