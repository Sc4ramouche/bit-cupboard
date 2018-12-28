# Middleware

Middleware functions are functions that have access to the request object (`req`), the response object (`res`), and the `next` function in the application's request-response cycle. The `next` function is a function in the Express router which, when invoked, executes the middleware succeeding the current middleware. If the current middleware does not end the request-response cycle, it must call `next()` to pass control to the next middleware function. Otherwise, the request will left hanging.

Consider simple Express app example (source code located at `/examples`):

```JS
const express = require('express');
const app = express();

app.get('/', function (req, res) {
    res.send('Hello World!');
});

app.listen(3000);
```

## logger middleware

Now we could add logger which will print simple log message on every request to the app.

```JS
const logger = (req, res, next) => {
    console.log('LOGGED');
    next();
};
```

Notice how `logger` passes control to the next middleware with `next()` call. To load the middleware function, call `app.use()`, specifying the middleware function:

```JS
app.use(logger);
```

The order of middleware loading is important: middleware functions that are loaded first are also executed first. If `logger` would be loaded after the route to the root path, request never reaches it and the app doesn't print `LOGGED`, because the route handler of the root path terminates the request-response cycle.

## requestTime middleware

We'll create `requestTime` middleware and add a property called `requestTime` to the request object:

```JS
const requestTime = (req, res, next) => {
    req.requestTime = Date.now();
    next();
}
```

Now you can add both middlewares to out app:

```JS
app.use(logger, requestTime);
```

Notice how we add property `requestTime` in the middleware and then use at in the `get()` function.

## configurable middleware

If you need your middleware to be configurable, export a function which accepts an options object or other parameters, which, then returns the middleware implementation based on the input parameters:

```JS
module.exports = function(options) {
    return function(req, res, next) {
        // Implement the middleware function based on the options object
        next();
    }
}
```

So it can be used like this:

```JS
const mw = require('./middleware.js');

app.use(
    mw({
        option: '42',
        anotherOne: '1337'
    })
);
```

# using middleware

An Express application can use the following types of middleware:

-   Application-level middleware
-   Router-level middleware
-   Error-handling middleware
-   Built-in middleware
-   Third-party middleware

## application-level middleware

Bound to an instance of `app` object by using `app.use()` and `app.METHOD()`.

Example that illustrates a middleware sub-stack that handles GET requests to the `/user/:id` path:

```JS
app.get(
    'user/:id',
    (req, res, next) => {
        // if the user ID is 0, skip to the next route
        if (req.params.id === '0') next('route');
        // otherwise pass the control to the next middleware function in this stack
        else next();
    },
    (req, res, next) => {
        // send regular response
        res.send('regular');
    }
);

// handler for the /user/:id path, which sends a special response
app.get('/user/:id', (req, res, next) => {
    res.send('special');
});
```

Here we pass control to the _next route_ in case user id equals to `'0'`. In this case second route handler would never be called otherwise, as the first one ends request-response cycle, so having two identical route handlers won't cause any problems. Here we are using `next('route')` to pass control to the second handler.

## router-level middleware

Router-level middleware works in the same way as application-level middleware, except it is bound to an instance of `express.Router()`.

## error-handling middleware

Error-handling middleware always takes **four** arguments. Even if you don't need to use the `next` object, you must specify it to maintain the signature.

```JS
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});
```

## built-in middleware

Express has the following built-in middleware functions:

-   `express.static` serves static assets such as HTML files, images, and so on.
-   `express.json` parses incoming requests with JSON payloads.
-   `express.urlencoded` parses incoming requests with URL-encoded payloads.

`express.json` and `express.urlencoded` are available with Express **4.16.0+**.

## third-party middleware

Use to add functionality to Express apps. Example:

```JS
const cookieParser = require('cookie-parser');

app.use(cookieParser());
```
