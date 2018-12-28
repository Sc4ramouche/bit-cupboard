const express = require('express');
const app = express();

console.log('Started!');

const logger = (req, res, next) => {
    console.log('LOGGED');
    next();
};

const requestTime = (req, res, next) => {
    req.requestTime = Date.now();
    next();
};

app.use(logger, requestTime);

app.get('/', (req, res) => {
    let responseMessage = 'Hello World!<br>';
    responseMessage += 'at: ' + req.requestTime;
    res.send(responseMessage);
});

app.listen(3000);
