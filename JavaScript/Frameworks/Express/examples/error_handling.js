const express = require('express');
const fs = require('fs');

const app = express();

console.log('Started!');

app.get('/', (req, res, next) => {
    setTimeout((req, res, end) => {
        try {
            throw new Error('BROKEN');
        } catch (err) {
            next(err);
        }
    }, 1000);
});

app.get('/promises', (req, res, next) => {
    Promise.resolve()
        .then(() => {
            throw new Error('BROKEN, but now with Promise!');
        })
        .catch(next); // Errors will be passed to Express
});

app.get('/chain', [
    (req, res, next) => {
        // in case of error control flow will be passed to Express
        fs.readFile('middleware.js', 'utf-8', (err, data) => {
            res.locals.data = data;
            next(err);
        });
    },
    (req, res) => {
        // if we fail to process the data the synchronous handler will catch it
        res.locals.data = res.locals.data.split(',')[1];
        res.send(res.locals.data);
    }
]);

app.listen(3000);
