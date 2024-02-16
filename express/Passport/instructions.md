# Passport

Follow the instructions provided to add authentication to an existing Express-based application using Passport. Open your command prompt or terminal and change to the `starter` folder to do your work.p. Use Copilot to assist you in generating d code to complete the exercise.

Feel free to experiment by adding additional features to the completed application.

You'll need four additional modules that aren't already part of the application. Run this command to get them all:

```
npm i -S cookie-parser express-session passport passport-local
```

1) Load those modules near the top of the file.

2) Add code to use them near where the existing usage of the `body-parser` module is located.

The secret you pass to the `express-session` middleware is used to encrypt the cookie with the session ID and can be whatever you want. When deploying, you'd probably want to get its value from an environmental variable and set things up so that all servers in your farm share the same secret.

3) Add a login page to the app by creating a file named `login.ejs` in the `views` directory. That page should have a normal HTML form that posts to `username` and `password` fields to the `/login` URL. 

4) Define a route that renders the view in response to GET requests to `/login`.

5) The form will post to the same URL so define a route for that. Instead of defining your own callback function, use `passport.authenticate()` to handle the request with the `local` strategy. If authentication succeeds, redirect to `/`. Otherwise, redirect back to `/login`:

6) For Passport to actually perform the authentication, you need to configure a new instance of the strategy you get with the `passport-local` module. Since we don't have a real database with usernames and passwords in them, do whatever username/password checking you like:

7) Passport will store the user's ID in an Express session, but you need to help it figure out what the ID actually is and how to turn that ID back into a user object. Do that with the `passport.serializeUser()` and `passport.deserializeUser()` functions.

In a real app, the `deserializeUser` callback would fetch a user object from a database with the given ID. This exercise just uses the username as the ID.

8) To require users to authenticate, you need to redirect them to `/login`, if they're not authenticated yet. Passport adds a `isAuthenticated()` method to request objects that you can use to check this. Create a function called `ensureAuthenticated`. This will be an Express middleware function that checks if the request is authenticated and, if not, redirects.

9) To use that middleware, add it to the routes that need authentication like the route for `/`.

10) You should be able to test this by viewing the app in your browser. To test authenticating, you can open a new "private" window with your browser so they don't reuse cookies. Try visiting `/api/items` without being authenticated. You should be able to see all of the data because the `ensureAuthenticated` middleware was never added to the `/api` routes. 

11) To fix the problem,  add the routes for `get' and `'set' methods.

You can try it now and see that you get redirected, but that's not how Ajax requsets should behave. Ajax requests can't be redirected to a login page the way normal requests can. You really just want to forbid access to those routes if the user isn't logged in.

12) Change the `ensureAuthenticated` function to act a little differently for the Ajax requests. If `req.path` starts with `/api`, send a 403 (Forbidden) status code to the client.

Visiting `/api/items` without being authenticated should now fail, as desired.
