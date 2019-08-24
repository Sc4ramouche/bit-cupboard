# [Chapter 3: Managing Function Inputs](https://github.com/getify/Functional-Light-JS/blob/master/manuscript/ch3.md)

## All for One

There could be scenario when you pass a function to utility that sends multiple arguments to the function you've given. But you may only want to receive a single argument:

```JS
['1', '2', '3'].map(parseInt)
```

The code above will return `[1, NaN, NaN]` because `map` signature can accept up to three parameters. And `parseInt` is expecting two arguments: string value and *radix*. So in that case map's `index` is passed as *radix* to the `parseInt` function.

For that case you might want to use `unary` utility:

```JS
function unary(func) {
    return function(arg) {
        return func(arg)
    }
}

// or
const unary = func => arg => func(arg);
```

That helper function wrapper ensures that only one argument will be passed through.

```JS
['1', '2', '3'].map( unary(parseInt) );
// returns [1, 2, 3]
```

## One for One

Another common utility is a function that takes one argument and does nothing but return the value untouched. At first it looks like this hardly can be useful. But it could be useful as filter predicate, for example:

```JS
const identity = v => v;

let words = '   Now is the time...   '.split( /\s|\b );
// ['', 'Now', 'is', 'the', 'time', '...', '']
words.filter( identity);
// ['Now', 'is', 'the', 'time', '...']
```

In this example `identity` will get rid off empty values.

You may also want to use `identity` in a place of a transformation as default function:

```JS
function output(msg, formatFn = identity) {
    return formatFn( msg )
}
```

## Adapting Arguments to Parameters
