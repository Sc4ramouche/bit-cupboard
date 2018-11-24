## long-polling

Long-polling is something like the following workflow: 

1. client sends request to server
2. server leave the connection opened, i.e. it doesn't responds immediately
3. when there is data ready for the client - it will response with that data payload
4. client handles response
5. client sends new request - loop closed

The difference with streaming is in the fact that client doesn't send additional requests to the server. Server just descents information to the client.

There is subtle moment in long-polling technique - the client may connect and then close the connection by himself. We usually don't want to send unnecessary response. It may cause when the user closes the browser for example. Hopefully, we can track down when it happens. Consider we have `subscribe` method on the server, which adds `req` objects server receives to the `clients` array:

```JavaScript
    res.on('close', () => {
        clients.splice(indexOf(res), 1);
    })
```

## working with req object as a stream

You can read `req` as a stream. Let's consider example where we read body of the *POST* request:

```JavaScript
let body = '';
req.
    on('readable', () => {
        body += req.read();
    })
    .on('end', () => {
        body = JSON.parse(body);
        res.end(body.message);
    });
```

## server memory overflow

There may be the case when client is an culprit (that happens) or, conversely, very kind and wants to share all his files he stored for years. To protect yourself from too big files we can check the length of the traversed data:

```JavaScript
let body = '';

req.on('readable', () => {
    body += req.read();

    if (body.length > 1e4) {
        res.statusCode = 413;
        res.end('Your message is too big for my little app');
    }
})
```