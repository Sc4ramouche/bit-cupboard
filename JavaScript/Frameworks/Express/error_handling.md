# error handling

Express comes with a default error handler so it's not necessary to write your own to get started.

## catching errors

Errors that occur in synchronous code inside route handlers and middleware require no extra work. For errors returned from asynchronous functions invoked by route handlers and middleware, you must pass them to the `next()` function, where Express will catch and process them:

```JS
app.get('/', (req, res, next) => {
    fs.readFile('/file-does-not-exist', (err, data) => {
        if (err) next(err);
        else res.send(data);
    });
});
```

If you pass anything to the `next()` function (except the string `'route'`), Express regards the current request as being an error and will skip any remaining non-error handling routing and middleware functions.

Above example could be simplified:

```JS
app.get('/', (req, res, next) => {
    fs.writeFile('/file-does-not-exist', 'data', next);
}, (req, res) => {
    res.send('OK');
});
```

Here `next` provided as the callback for `fs.writeFile`, which is called with or without errors. If there is no error the second handler is executed, otherwise Express catches and processes the error.

With asynchronous code same rules apply: catch an error and pass them to Express (check `/examples` folder):

```JS
app.get('/', (req, res, next) => {
    setTimeout(() => {
        try {
            throw new Error('BROKEN');
        } catch (err) {
            next(err);
        }
    }, 1000);
});
```

If you omit `try...catch`, Express would not catch the error since it is not part of the synchronous handler code. You could also use promises to avoid overhead of `try...catch` block or when using function that return promises:

```JS
app.get('/promises', (req, res, next) => {
    Promise.resolve()
        .then(() => {
            throw new Error('BROKEN, but now with Promise!');
        })
        .catch(next); // Errors will be passed to Express
});
```

Another way is using chain of handlers, this helps reducing the asynchronous code to something trivial:

```JS
app.get('/chain', [
    (req, res, next) => {
        // in case of error control flow will be passed to Express
        fs.readFile('middleware.js', 'utf-8', (err, data) => {
            res.locals.data = data;
            next(err);
        });
    },
    (req, res) => {
        res.locals.data = res.locals.data.split(',')[1];
        res.send(res.locals.data);
    }
]);
```

If `readFile` causes an error, then it passes the error to Express, otherwise you quickly return to the world of synchronous error handling in the next handler in chain. Then, the example above tries to process the data. If it fails then the synchronous error handler will catch it. If you had done this processing inside the `readFile` callback then the application might exit and the Express error handlers would not run.

## the default error handler

Express comes with a built-in error handler which is added at the end of the middleware function stack. If you pass an error to `next` and you do not handle it in a custom error handler, it will be handled by the built-in handler – the error will be written to the client with the stack trace.

If you call `next()` with an error after you have started writing the response (for example, if you encounter an error while streaming the response to the client) the Express default error handler closes the connection and fails the request.

When you add a custom error handler, you must delegate to the default handler when the headers have already been sent:

```JS
const errorHandler = (err, req, res, next) => {
    if (res.headersSent) {
        return next(err);
    }
    res.status(500);
    res.render('error', {error: err});
}
```

Default error handler could be triggered if you call `next()` with an error more than once, even if occurred in custom handler.

## writing error handlers

Error handlers are the same as usual middleware, but with slightly different signature: they always has to have **4** arguments: `(err, req, res, next). Example:

```JS
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});
```

**Important**: you should define error-handling middleware last, after other `app.use()` and routes calls.

Responses from within could be in any format, such as HTML error page, a simple message or a JSON string.

When you're **not** calling `next` in an error-handling function, you are responsible for writing and ending the response. Otherwise the response will "hang" and will not be eligible for garbage collection.
