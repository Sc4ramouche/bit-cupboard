Text and code snippets origin: [swift.org](https://swift.org)

# Basic Operators

Swift support most standard C operators nd improves several capabilities to eliminate common coding errors.

## Assignment Operator

The assignment operator initializes or updates the value. If the right side of the assignment is a tuple with multiple values, its elements can be decomposed into multiple constants or variables at once:

```Swift
let (x, y) = (1, 2)
```

The assignment operator (`=`) doesn't return a value, to prevent it from being mistakenly used when the equal to operator (`==`) is intended.

## Arithmetic Operators

There are 4 standard *arithmetic operators*: addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`).

Arithmetic operators detect and disallow value overflow to avoid unexpected results.

## Comparison operators

Swift supports usual list of comparison operators: `==`, `!=`, `>`, `<`, `>=`, and `<=`. But it also provides two *identity operators: `===` and `!==`, which you use to test whether two object references both refe to the same object instance.

You can compare two tuples if they have the same type and the same number of values. Tuples are compared from left to right, one value at a time, until it finds two value that aren't equal.

## Nil-Coalescing Operator

The *nil-coalescing operator* (`a ?? b`) unwraps an optional `a` if it contains a value, or returns a default value `b` if `a` is `nil`. The expression `a` is always of an optional type. The expression `b` must match the type of `a`.

The nil-coalescing operator is shorthand for this:

```Swift
a != nil ? a! : b
```

## Range Operators

### Closed Range Operator

The *closed range operator* (`a...b`) defines a range that runs from `a` to `b`, and includes the values `a` and `b`. This is useful to iterate over a range in which you want all of the values to be used.

```Swift
for index in 1...5 { /* ... */ }
```

### Half-Open Range Operator

The *half-open range operator* (`a..<b`) defines a range that runs from `a` to `b`, but doesn't include `b`. This is useful when you work with zero-based lists such as arrays, where it's useful to count up to (but not including) the length of the list.

```Swift
for i in 0..<array.count { /* ... */ }
```

### One-Sided Ranges

The closed range operator has an alternative form for ranges that continue as fat as possible in one direction – for example, a range that includes all the elements of an array from index 2 to the end of the array.

```Swift
for name in names[2...] { /* ... */ }
```

You can check whether a one-sided range contains a particular value:

```Swift
let range = ...5
range.contains(7)    // false
range.contains(4)    // true
```
