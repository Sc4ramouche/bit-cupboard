# Week 1: Python Basics

## Basic Primitives

Turing showed you can **compute anything** using 6 primitives. This principle is illustrated by the _Turing Machine_. Those primitives are: move left, move right, scan, read, write, do nothing. Modern programming languages have more convenient set of primitives though.

## Python Scalar Object

- `int`
- `float`
- `bool`
- `NoneType` – special, has one value, `None`

`NoneType` used when you call `print` function. So `print` returns `None`.

In Python you can use `//` operator, which stands for _integer division_. Another thing is that you can multiply strings: `3 * 'hello` will result in `hellohellohello`. These things are not present in JavaScript.

## Strings

In Python you slice strings like this:

```Python
'eric'[1:3]    # 'ri'
'eric'[:3]     # 'eri'
'eric'[1:]     # 'ric'
'eric'[:]      # 'eric'
```

Notice that slicing return new String instance. That means that last example will give us a copy of the original string.

There's optional third argument to the slicing which defines step.

```Python
'Python is fun'[1:12:2]    # yhni u
'Python is fun'[::2]       # Pto sfn
```

## Input

Command line input is easily managed by calling `input` function. You can assign returned value to a variable. `input` interprets everything as a `str` value, so in case you'd need a number, you'll have to manually cast it:

```Python
text = input("Type something:")
price = int(input("How much for this? "))
```

## Range

Ranges are oftenly used in for loops. Some glance examples:

```Python
range(7, 10)       # 7, 8, 9
range(2, 10, 2)    # 2, 4, 6, 8
range(4)           # 0, 1, 2, 3
```

## Loops

You can rewrite a `for` loop using a `while` loop, but can not do the opposite thing.

In Python you can access loop variables after the loop is completed (just like in JavaScript with `var` syntax):

```Python
for var in range(4)
    print('inside of the loop:', var)

print('outside of the loop:', var)    # 3
```
