# `this`

`this` add flexibility to our code. Whenever you need to access object's property it's much more flexible to use `this` instead of object's name. Consider we have an `user` object with `sayHi` method:

```JavaScript
const user = {
    name: 'Alan',
    sayHi: function () {
        console.log(this.name);
    }
};
```

You could just use `user.name` here. But if you reassign this object to another pointer (like `let admin = user;`) you would get an error. So if you manage to create `user`-like objects with constructor, you would get uniform way to execute `sayHi` and get intended result.

## calling `this` without any context

```JavaScript
function check() {
    console.log(this);
}
```

In this case plain `check()` call `this` will refer to *global* object. But if you execute this snippet in *strict* mode `this` will evaluate to `undefined`.

## Reference Type

`this` is not bound to function in any way. `this` evaluation depends only on **call site**. 

One common problem with `this` is loss of context. Such thing can happen if you pass a function as a callback. The subtle detail here is that actually two things happen when we call an object method: `.`(dot) operator - accessing property (method in this case) **and** `()` - actual call of the retrieved function.

So as function can't remember the context itself, `.` dot operator to the rescue. It doesn't return actual function, but special [`Reference Type`](http://www.ecma-international.org/ecma-262/5.1/#sec-8.7) value. It's represented with bundle:

1. base - object itself i.e. context
2. name - property name
3. strict - auxiliary flag for `use strict` evaluation.

`Reference Type` lives in specification world, we can not access it manually. Every operator throws it away as soon as operation is completed. The flow is:

1. `()` gets the `name` from the `base` and call retrieved method in the context of `base`.
2. Other operators get the `name` from the `base` and just use it ignoring everything else.

Thus every operation besides *call* `()` leads to context loss. These rules apply to `obj['method']` way of retrieving property as well.