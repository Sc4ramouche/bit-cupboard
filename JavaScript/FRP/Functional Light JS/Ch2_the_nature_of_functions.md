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

