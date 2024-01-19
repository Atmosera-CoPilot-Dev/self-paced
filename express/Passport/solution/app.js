var path = require('path');

var express = require('express');
var morgan = require('morgan');
var bodyParser = require('body-parser');
var cookieParser = require('cookie-parser');
var expressSession = require('express-session');
var passport = require('passport');
var passportLocal = require('passport-local');

var app = express();

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

if (app.get('env') === 'development') {
    app.use(morgan('dev'));
}

app.use(bodyParser());
app.use(cookieParser());
app.use(expressSession({ secret: 'secret' }));
app.use(passport.initialize());
app.use(passport.session());

passport.use(new passportLocal.Strategy(function(username, password, done) {
    if (username === password) {
        done(null, {
            id: username
        });
    } else {
        done(null, null);
    }
}));

passport.serializeUser(function(user, done) {
    done(null, user.id);
});

passport.deserializeUser(function(id, done) {
    done(null, {
        id: id
    });
});

function ensureAuthenticated(req, res, next) {
    if (req.path !== '/login' && !req.isAuthenticated()) {
        if (req.path.indexOf('/api/') === 0) {
            res.send(403);
        } else {
            res.redirect('/login');
        }
    } else {
        next();
    }
}

var items = [
    { id: 1, value: 'item one' },
    { id: 2, value: 'item two' },
    { id: 3, value: 'item three' }
];

app.get('/', ensureAuthenticated, function(req, res) {
    res.render('index', { items: items });
});

app.get('/login', function(req, res) {
    res.render('login');
});

app.post('/login', passport.authenticate('local', {
    successRedirect: '/',
    failureRedirect: '/login'
}));

app.get('/api/items', ensureAuthenticated, function(req, res) {
    res.json(items);
});

app.post('/api/items', ensureAuthenticated, function(req, res) {
    var item = {
        id: items.length,
        value: req.body.value
    };

    items.push(item);

    res.json(item);
});

app.use('/bootstrap', express.static(path.join(__dirname, 'node_modules/bootstrap/dist')));
app.use('/jquery', express.static(path.join(__dirname, 'node_modules/jquery/dist')));

app.use(express.static(path.join(__dirname, 'public')));

var port = process.env.PORT || 1337;

app.listen(port, function() {
    console.log('http://127.0.0.1:%d/', port);
});
