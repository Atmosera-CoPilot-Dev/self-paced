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

1) Import the module that provides utilities for working with file and directory paths.

2) Import the 'express' module.

3) Import an HTTP request logger middleware for Node.js.

4) Create an instance of Express application.

5) Check if the application environment is 'development'.  If it is, use the logger middleware with 'dev' format.  'dev' format is concise output colored by response status for development use.

6) Serve static files located under 'node_modules/bootstrap/dist' directory. These files will be served at '/bootstrap' path.

7) Serve static files located under 'public' directory. These files will be served at '/' path.

8) Get the port number from environment variables or else use 1337 as a default.

9) Start the server and listen on the specified port.

10) Add comments for each operation in the app.

11) Create a README.md file that extensivily describes the app.

12) Create a unit test harness using either TDD or BDD style.
