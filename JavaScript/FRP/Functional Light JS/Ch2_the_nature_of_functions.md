# [Chapter 2: The Nature Of Functions](https://github.com/getify/Functional-Light-JS/blob/master/manuscript/ch2.md/#chapter-2-the-nature-of-functions)

## Morphism

Fancy way of describing correlation between two sets of values - like input to output values.

## Function vs Procedure

Many are accustomed to viewing functions as a set of procedures. It may have return value and may not as well.

Functions, in their turn, **always** have return value. We are using *functions* as functions in it's mathematical sense. Something that takes input and produces output.

## Function Input

Diffrence between *parameter* and *argument* is simple: arguments are the values you pass in the function as input, wherever parameters are named variables inside the function that receive passed-in values.

## Counting Inputs

consider:

```JavaScript
function foo(x, y, z) { /* ... */ }
```

`foo` expects three arguments. There is special name to describe it: **arity** - the number of parameters in function declaration. The arity of `foo` function is 3. Functions with arity = 1 could be called *unary*, with arity = 2 - *binary*. In JavaScript you can actually easily get the arity without inspecting the function itself. This could be done with accessing `length` property - for example above:

```JavaScript
foo.length // 3
```

**Note**: `length` property is readonly and it's determined at the moment of function declarartion. But there are some gotchas with certain kinds of arguments:

```JavaScript
function foo(x, y = 1) { /* ... */ }
function bar(x, ...rest) { /* ... */ }
function baz({a , b}) { /* ... */ }

foo.length;    // 1
bar.length;    // 1
baz.length;    // 1
```

You can get passed arguments count by accessing `arguments.length`. `arguments` itself is deprecated, but accessing it's `length` property is somewhat ok as soon as there are no handy counterpart for it (yet).

*Variadric* function - function that accepts arbitrary amount of arguments.

You can access not declared arguments with ES `...` rest operator. Example:

```JavaScript
function foo(x, y, z, ...args) { console.log(x, y, z, args) }

foo(1, 2, 3);    // 1 2 3 []
```

**Note**: if you gather not declared arguments with `...`(rest) operator, it will always be an array even in case when it's empty.

## Parameter Destructuring

Consider example of desctructuring two first values of prodided array into separate variables:

```JavaScript
function foo([x, y, ...args] = []) { /* ... */ }

foo([1, 2, 3, 4, 5]);
```

Same goes for the objects:

```JavaScript
function foo({x, y} = {}) { /* ... */ }

foo({ y: 3 });
```

With objects destructuring comes neat detail: we don't care about `x` at our call site. Imagine that function was receiving plain arguments - in this cause would have to do something like `foo(undefined, y)`. With object destructuring we can just omit `x`. Some other languages have explicit feature for this - *named arguments*. JS don't have such feature, but parameter destructuring is the next best thing.

## Function Output

In JavaScript functions actually always return a value. There three function have same behaviour:

```JavaScript
function foo() {}
function bar() {
    return;
    }
function baz() {
    return undefined;
}
```

## Early Returns

`return` serves not only as a tool to yield value from a function, but also as flow control tool. Be careful using several `return` statements in your functions as it could bring implicity.

## Functions of Functions

A function that receives or returns function or functions is called *higher-order function*.

## Keeping Scope

Closure is when function is able to remember and access variables outside of it's own scope, even if it is executed in a different scope.

FP encourages us to use closures all the way. And since functions are values too, we can use closures to define simple functions that encapsulate particular behaviour.

```JavaScript
function formatter(formatFn) {
    return function inner(value) {
        return formatFn(value);
    }
}

let lower = formatter(function formatting(v) {
    return v.toLowerCase();
});

lower('WOW');    // wow
```

## Syntax

Functions in JavaScript have the `name` property on them. This property is used by environment while printing stack trace, for example. Modern environment can even guess (infer) the name of the function if you didn't provide it explicitly:

```JavaScript
function foo(fn) {
    console.log(fn.name);
}

let x = function (){};
foo(x);                  // x
foo(function (){});      //
```

In this part Kyle implies to use named functions even in function expressions. That's not only good for debugging, but makes it easy to self-reference for functions. Also properly named functions could tell us a little more about code itself. So basically you can name every single function.

## `this`

`this` is considered as implicit parameter in FP code. Consider:

```JavaScript
function sum() {
    return this.a + this.b;
}

const obj = {a: 1, b: 2};
sum.call(obj);    // 3
```

See the implicity? But we can pass arguments explicitly:

```JavaScript
function sum(context) {
    return context.a + context.b;
}

const obj = {a: 1, b: 2};
sum(obj);    // 3
```
