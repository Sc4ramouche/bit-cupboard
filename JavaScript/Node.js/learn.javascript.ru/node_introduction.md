# [NodeJS Screencast](https://learn.javascript.ru/screencast/nodejs)

## Introduction

### Export Module

You can actually export piece of code like the following:

```JavaScript
module.exports = {
    User
};
```

It's nice to investigate what the `module` object really is. You can try to run `console.log(module)` in any module to see what's inside.

### Define is it module or running app

You can ckeck if the current code is a *module* or a an *app* that required that module:

```JavaScript
if (module.parent) {
  exports.run = run;
} else {
  run();
}
```

### Differenece between exports and module.exports

If you want to export function as it is - as the export object - you have to use `module.exports`. `exports` is just a reference to the `module.exports`. So when you try to change `exports` you just change the reference, not the object itself.

### util.inspect()

Apparently `console.log` calls for `util.inspect()` method if it supposed to log object. We can add `inspect` method to object like this:

```JavaScript
const obj = {
  a: 5,
  b: 6,
  inspect: function() {
    return 123;
  }
}
```

In this case `console.log(obj)` will result in `123`. It's works something like `toString()` for objects. We can use `util.inspect()` in cases where we want to stringify objects.

### util.format()

```JavaScript
const str = util.format('My %s %d %j', 'string', 123, {test: 'obj'});
console.log(str); // My string 123 {"test": "obj"}
```

### util.inherits()

Makes all objects created by one constructor to inherit from specified as second argument. Usage:

```JavaScript
function Animal(name) {
  this.name = name;
}

Animal.prototype.walk = function() {
  console.log('Walks ' + this.name);
}

function Rabbit(name) {
  this.name = name;
}

util.inherits(Rabbit, Animal);

Rabbit.prototype.jump = function() {
  console.log('Jumps ' + this.name);
}

let rabbit = new Rabbit('our fella');
rabbit.walk();  // Walks our fella
rabbit.jump();  // Jumbps our fella
```

## EventEmitter

In Node listeners to events are executed in exact same order they vere declared in (not like browser). Also you can get the list of the listeners in Node: `emitter.listeners(eventName)`.

## Emit 'error'

`emitter.emit('error')` actually throws an error - it has special handling. You can specify `Error` object as second argument. If you add listener to `'error'` event - error won't be thrown.

You can set unlimited listeners for emitter: `emitter.setMaxListeners(0)`.

## http module

`http.createServer` creates emitter if used with keyword `new`. We can the initialize `server` => `server.listen(1337, '127.0.0.1)`: here we say our server to listen to `localhost` on port 1337.

When new request arrives it initializes new event with name of `'request'`. It's handler receives two object usually called `req` and `res`. Request and Response correspondingly. From former we read request info and then write to the latter.

consider following code:

```JavaScript
let counter = 0;
server.on('request', (req, res) => {
  counter++;
  res.end('Hello, world!' + '\nRequest count:' + counter);
});
```

It's supposed to increment counter by one, right? Nope. If you run it, you'll see that when you refresh page counter is incremented by two on each refresh. The reason for that is browser sending separate request to get a favicon.

You can close the server with `server.close()`. But it will still process connections which were in process on the moment of closing.

## url module

```JavaScript
let parsedUrl = url.parse(req.url);
```

You can parse URL with `url` module to get all the info about the URL. You can pass second parameter to `parse` method to destructure it into objects => `url.parse(req.url, true)`.

## logging

You can log your apps with **debug** or **winston** modules.
You can know where the process is executed by running `process.cwd()`.

## fs

If you want to read a file from a directory where you run your node.js process you have to play with `__dirname`.

## timers 

Timers are objects in Node! Unlike in browser.

consider:

```JavaScript
setTimeout(() => {
  server.close();
}, 2500);

let timer = setInterval(() => {
  console.log(process.memoryUsage());
}, 1000);
```

Seems like node process should stop after 2.5 seconds, right? But it's not the case. In reality, libUV will still consider timer created and won't stop the proccess. We can add callback to the closing method: `server.close(() => clearInterval(timer))`. This will work just fine. But you can also add following statement instead of passing callback to `close()`: `timer.unref()`.

`unref` method tells libUV to consider timer as secondary(minor) timer and that it shouldn't be considered when inner watchers are checked to determine if it needs to end the process.

## domains

There are no domains in browser world. This is deprecated API, but we will go through it with educational purposes.

Main purpose of domains is to handle errors. Using `try ... catch` with callbacks are not useful.

Here is when domains become useful - we wrap our server with domain and it actually handles all the server errors. Looks something like this:

```JavaScript
serverDomain.run(function() {
    server.listen(3000);        // in case of error: Domain had catched: Error
});
```