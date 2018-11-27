# HTTP

## request initial line

`method URI HTTP/version` - that's how template for initial line of HTTP request looks like.

### method

Usually represents operation needed to perform with provided URI

### URI

URI - Uniform Resource Identifier. Represents resource that we want to interact with by sending HTTP request. If we are not interested in any resource, but in server itself we can specify it like the following: `OPTIONS * HTTP/1.1`

### version

HTTP protocol verison. Two digits separated by dot.

## request example

All HTTP/1.1 requests have to contain at least one particular header - `Host`.

```HTTP
GET / HTTP/1.1
Host: github.com
```

## response initial line

`HTTP/version code status reason_phrase`.

### code

Represented by 3 digits. First one relates to response group. HTTP specification provides semantical codes for most common situations.

### reason phrase

Text to clarify the meaning of the response.

## response

After initial line contains headers and response *body*. Example:

```HTTP
HTTP/1.1 200 OK
Server: nginx/1.2.1
Date: Sat, 08 Mar 2014 22:54:14 GMT
Content-Type: application/octet-stream
Content-Length: 7
Last-Modified: Sat, 08 Mar 2014 22:53:30 GMT
Connection: keep-alive
Accept-Ranges: bytes

Wisdom
```

Response body is separated from the last header with 2 carriage returns (LF's). To determine where response body end HTTP uses value of the `Content-Length` header.

## HTTP 1.0

HTTP version 1.0 closes connection when server responses to the client.

## HTTP 1.1

Add *virtual hosts* to the protocol. It's mandatory header for request. HTTP/1.1 also introduces new concept: `keep-alive`. That's useful because it doesn't require to open new connection everytime if you access the server and want to get several resources from it. With `keep-alive` we are able to use the same opened TCP connection instead of creating new for every request. `connection: keep-alive` is now default behaviout in web, every server will add this header to the response by default. If you want explicitly close connection once you get response you can act like this:

```HTTP
GET / HTTP/1.1
host: google.com
connection: close
```

## HEAD verb

Works exactly like the `GET`, but doesn't request for body.

## HTTP body

How body is actually served? When server sends response with body it state special header: `content-length`. If that header is present server does not close the connection. It will send precise amount of bytes specified in `content-length` and only after that http session is closed (but not necesserely a connection, remember `keep-alive`?).

## Chunks

We can get responses from server in chunks. It's happening when you observe image is loaded from top to bottom. To apply chunking in connection add the following header: `Transfer-Encoding: chunked`. This allows to handle responses partially.

## Query parameters

Can be used with every HTTP verbs. Query parameters string is not infinitely long, so if you a really juicy payload it's better to use `body`.

Example:

```HTTP
POST /url?admin=me&dogs=true HTTP/1.1
```

## Idempotent methods

Semantically we can derive request to two groups: ones that doesn't change with subsequent similar request and ones that actually do change with every subsequent request. Former group is related as *idempotent* methods. Example: usually `GET` request results in the same response every time we send it, but `DELETE` request will unlikely result in the same response. This concept is something similar to *side effects*.

## redirect

Redirect response is related to status code 3xx. In case of redirect server add `Location` header to the response. Browser may handle redirect automatically.

## stateless

HTTP is stateless protocol. Pragmatically that means that every request-response does **not** relate to previous request-response pair. Every request we make like it's our first request.