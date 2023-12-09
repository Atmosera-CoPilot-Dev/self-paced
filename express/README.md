# Express

## Part 1 - Install and set up Express

In this lab, you'll start by creating a new Express application in the (empty) `before` directory. Open a command prompt or terminal and change to that directory.

Create a new `package.json` file by running `npm init`. Feel free to answer the questions or just hit ENTER for each one.

You're going to use the `express` module so run `npm install -S express` to download `express` into your app's `node_modules` folder. The `-S` option (short for `--save`) adds `express` as a dependency in yoru `package.json`.

Create a file called `app.js` and create your application object by loading the `express` module and invoking it like a function:

```
var express = require('express');

var app = express();
```

Create a route for `/` on your app that just sends a simple string to the client:

```
app.get('/', function(req, res) {
    res.send('Hello!');
});
```

Tell the app to listen on a port. You'd usually allow the `PORT` environmental variable to control the actual part, but use a default port if that's not defined.

```
var port = process.env.PORT || 1337;

app.listen(port, function() {
    console.log('http://127.0.0.1:%d/', port);
});

```

Run the app with `node app` and try visiting the URL in your favorite browser. Did you see your message?

Create a directory called `public` and put a file named `index.html` in that folder containing any content you want.

Use the `static` middleware to serve the files in that directory. Calculating the full path can be done with the help of the `__dirname` variable. You can also use `path.join` to join `__dirname` with the name of your `public` directory, but you'll have to import the module.

```
var path = require('path');

app.use(express.static(path.join(__dirname, 'public')));
```

If you restart your app and try visiting the same URL you visited before, you'll probably see the same message. Comment out that route and try again.

The page isn't very pretty, so let's add some Bootstrap CSS to it. Install Bootstrap with `npm install -S bootstrap`. Then look in your `node_modules/bootstrap/dist` directory to see where the files you need to server were saved.

Add another usage of the `static` middleware to server the Bootstrap files in that directory. You can pick whatever "virtual" directory you want as the directory clients see. Using `/bootstrap` seems appropriate so try that:

```
app.use('/bootstrap', express.static(path.join(__dirname, 'node_modules/bootstrap/dist')));
```

Add a link to `bootstrap.css` to `public/index.html` using the new "virtual" directory:

```
    <link rel="stylesheet" href="/bootstrap/css/bootstrap.css">
```

Notice how the client can't see that the actual directory is inside `node_modules`.

Restart the app and view it again in your browser. The typography should have changed subtley. You can add padding around your content by wrapping it in a `<div class="container">` element.

Finally, add some logging to your app with the `morgan` middleware. Install it with `npm i -S morgan`, then `require()` it, then `app.use()` it. You can read about its options [here](https://github.com/expressjs/morgan), but passing in `'dev'` usually shows what most developers want to see. You can conditionally enable that logging by checking the app's `env` setting. The default is `development`:

```
var morgan = require('morgan');

if (app.get('env') === 'development') {
    app.use(morgan('dev'));
}
```

To change your enviroment, set the `NODE_ENV` environmental variable before restarting your app.

## Part 2 - Render dynamic HTML

In this part, you'll stop using the static `index.html` file in the `public` folder and start generating dynamic HTML.

You can choose from dozens of different template engines that work with Express, but `ejs` (or Embedded JavaScript) probably has the most familiar syntax for most developers.

Install the `ejs` module with `npm i -S ejs`.

Tell Express about your view engine by setting the `view engine` property. You should also set the `view` property with the full path to the directory that will contain your views. Don't use the same `public` directory you used before. Instead, make a new directory named `views` and use that.

```
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
```

Create `index.ejs` in the `views` directory. You can just copy the `public/index.html` to start.

Uncomment or re-add the `/` route from part 1 and change the `res.send()` call to `res.render()` with the name of the view:

```
app.get('/', function(req, res) {
    res.render('index');
});
```

Restart the app and test it.

To verify that you really are using the Embedded JavaScript view engine, embed some JavaScript in `index.ejs` with something like this:

```
        <p>This page was rendered at: <%= new Date() %>.</p>
```

Let's make this app a simple TODO-list app by rendering some dynamic TODO-list items. Add an `items` variable to `app.js` pointing to an array of objects with `id` and `value` properties. In a real app, you'd put this in a database. This variable will act as our database for this lab. That means that you'll lose any data you add to it when you restart the app.

The data may look like this:

```
var items = [
    { id: 1, value: 'item one' },
    { id: 2, value: 'item two' },
    { id: 3, value: 'item three' }
];
```

Pass that data to the view when you render it:

```
    res.render('index', { items: items });
```

The property named `items` will be visible inside the view. Loop over that array and render an unordeded list in your HTML:

```
        <ul>
            <% items.forEach(function(item) { %>
                <li><%= item.value %></li>
            <% }); %>
        </ul>
```

Next, allow your users to add to the list of items. Add a form to the HTML like this:

```
        <form action="/add" method="post" class="form-inline">
            <div class="form-group">
                <input name="value" type="text" class="form-control">
                <input type="submit" value="Add" class="btn btn-default">
            </div>
        </form>
```

Notice the form data will be posted to `/add`. You'll need to add a route to your app to accept that data. The new item's value will be accessible via `req.body.value`, but that won't work just yet. You'll be pushing your new item into the `items` array and then redirecting the user back to the same page to "refresh" the view.

```
app.post('/add', function(req, res) {
    items.push({
        id: items.length,
        value: req.body.value
    });

    res.redirect('/');
});
```

If you test that, your value is always undefined. That's because Express doesn't know how to parse form data in requests, but the `body-parser` middleware can. Install that with `npm i -S body-parser`. Then import it and use it before your `/add` callback function:

```
app.post('/add', bodyParser.urlencoded(), function(req, res) {
```

Restart and test your app.

## Part 3 - Implement a RESTful API

Finally, this part will have you change your app to be a "single-page application" by intercepting the form submit event and posting the value to the server via an Ajax request.

The API will use a new `/api/items` URL. Sending a GET request to that URL should return the list of items. Sending a POST request should add to the list of items. This will require two Express routes:

```
app.get('/api/items', function(req, res) {
    // ...
});

app.post('/api/items', function(req, res) {
    // ...
});
```

The `get` route just sends JSON to the client:

```
app.get('/api/items', function(req, res) {
    res.json(items);
});
```

The `post` route will be receiving JSON-encoded data so you'll need to use the `body-parser` middleware to do that:

```
app.post('/api/items', bodyParser.json(), function(req, res) {
```

Then add the item posted to the `post` route and then sending it's JSON back to the client:

```
app.post('/api/items', bodyParser.json(), function(req, res) {
    var item = {
        id: items.length,
        value: req.body.value
    };

    items.push(item);

    res.json(item);
});
```

That's all you need to do on the server, but the client needs to be updated with some JavaScript to make the Ajax requests. To make that easier, use jQuery. Install it by running `npm i -S jquery`. The files you need to serve to your clients are in `node_modules/jquery/dist` (very much like Bootstrap).

To expose jQuery to the clients, you'll need to add another usage of the `static` middleware:

```
app.use('/jquery', express.static(path.join(__dirname, 'node_modules/jquery/dist')));
```

Replace the list and form in your `views/index.ejs` file to include some `id` attributes that will be used by the client-side JavaScript:

```
        <ul id="theList">
        </ul>

        <form id="theForm" action="/add" method="post" class="form-inline">
            <div class="form-group">
                <input id="theValue" name="value" type="text" class="form-control">
                <input type="submit" value="Add" class="btn btn-default">
            </div>
        </form>
```

Since this lab isn't about client-side JavaScript or jQuery, just take the following code and put it in `public/script.js`:

```
$(function() {
    getItems().then(function(items) {
        items.forEach(renderItem);
    });

    $('#theForm').submit(function(e) {
        e.preventDefault();

        postItem({
            value: $('#theValue').val()
        })
        .then(renderItem)
        .then(resetForm);
    });

    function getItems() {
        return $.get('/api/items');
    }

    function postItem(item) {
        return $.ajax('/api/items', {
            method: 'POST',
            contentType: 'application/json',
            data: JSON.stringify(item),
            dataType: 'json'
        });
    }

    function renderItem(item) {
        $('#theList').append($('<li>').text(item.value));
    }

    function resetForm() {
        $('#theValue').val('').focus();
    }
});
```

Be sure to include both jQuery and your new script into your `index.ejs` view like this:

```
    <script src="/jquery/jquery.js"></script>

    <script src="/script.js"></script>
```

Restart and test. If JavaScript is enabled in your browser, you should see requests to `/api/items` in your console. If you disable JavaScript, the old  code from part 2 should still work.
