# Express App

Follow the instructions provided to install and set up an Express app. Use Copilot to assist you in generating the proper scaffolding and code to complete the exercise.

Feel free to experiment by adding additional features to the completed application. Here are some suggestions:
- Create a unit test usining either TDD or BDD with your favorite testing framework.
- Render dynamic HTML using `ejs`
- Implement a RESTful API

## Install and set up Express 

In this exercise, you'll start by creating a new Express application
in the `starter` directory. Open a command prompt or terminal and
change to that directory.

Create a new `package.json`. Feel free to answer the questions or just hit ENTER for each one.

You\'re going to use the `express` module so run
`npm install -S express` to download `express` into your app\'s
`node_modules` folder. The `-S` option (short for `--save`) adds
`express` as a dependency in yoru `package.json`.

Create a file called `app.js` and implement the code using the following instructions to hand-off to Copilot. :

- Import the 'path' module. This module provides utilities for working with file and directory paths.

- Import the 'express' module. Express is a minimal and flexible Node.js web application framework.

- Import the 'morgan' module. Morgan is a HTTP request logger middleware for Node.js.

- Create an instance of Express application.


- Check if the application environment is 'development'.  If it is, use the 'morgan' middleware with 'dev' format.  'dev' format is concise output colored by response status for development use.

- Serve static files located under 'node_modules/bootstrap/dist' directory. These files will be served at '/bootstrap' path.

- Serve static files located under 'public' directory. These files will be served at '/' path.

- Get the port number from environment variables or use 1337 as a default.

- Start the server and listen on the specified port.
