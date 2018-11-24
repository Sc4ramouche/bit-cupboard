const http = require('http');
const fs = require('fs');
const chat = require('./chat');

http.createServer((req, res) => {
    switch (req.url) {
        case '/':
            sendFile('index.html', res);
            break;

        case '/subscribe':
            chat.subscribe(req, res);
            break;

        case '/publish':
            let body = '';

            req.
            on('readable', function() {
                let chunk = req.read();
                body += chunk ? chunk : '';

                if (body.length > 1e4) {
                    res.statusCode = 413;
                    res.end('Your message is too big for my little app');
                }
            })
            .on('end', function() {
                try {
                    body = JSON.parse(body);
                } catch (e) {
                    res.statusCode = 400;
                    res.end('Bad Request');
                    return;
                }

                chat.publish(body.message);
                res.setHeader('Access-Control-Allow-Origin', '*');
                res.end('ok');
            });
            
            break;

        default:
            res.statusCode = 404;
            res.end = 'Not found';
    }
}).listen(3000, '127.0.0.1');

