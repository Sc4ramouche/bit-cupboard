# Arrays and Dictionaries

Arrays and Dictionaries in Swift represented by value, not by reference. They are structures, so they can be found on stack, not on heap.

Both structures could be mutable and immutable. This is defined by simple logic used to declare primitive values: if you declare an array or dictionary with `let` keyword – you cannot mutate them after the initialization. In case of `var` you'd have access to `insert`, `remove`, and other methods for arrays.

## Arrays

Array is a structure in terms of Swift.

```Swift
// different ways to declare an array
let arr1 = [1, 2, 3]
let arr2 = [Int]()
let arr3 = Array<Int>()
```

If you try to access not existing array index, you'll get runtime exception.

### Iteration

```Swift
for element in arr {
    /* ... */
}

// in case you'll need index
for (index, element) in arr.enumerated() {
    /* ... */
}
```

## Dictionaries

```Swift
// different ways to declare an array
let dict  = [mark: "Tesla", model: "X"]
let dict2 = [Int: String]()
let dict3 = Dictionary<Ing, String>()
```

Unlike with arrays, if you try to access a non existing property, you'll receive `Optional` value in case it's there or `nil` if there is no such property.

To delete a property from the dictionary, you need to assign it's value to `nil`:

```Swift
var xdict = [Int: String]()
xdict[1] = "One"
xdict[1] = nil
```

### Iteration

```Swift
for (key, value) in dict {
    /* ... */
}
```
