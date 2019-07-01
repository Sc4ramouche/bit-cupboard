# Structs

Another way to create objects in Swift is using *structures*:

```Swift
struct Car {
    let make: String
    let model: String
}

// initialization
let car = Car(mark: "Motors", model: "T80")
```

Unlike classes, structs don't need explicit initializer in case there's no complex initializating logic involved – compiler will automatically generate standard initializer.

## Classes vs Structs

There are two separate places in memory: *stack* and *heap*. Memory in the stack are represented by the object type, while heap stores objects by their reference. In other words, stack objects types are represented by the value type they are holding.

Structures are stored in the stack, classes are stored in the heap.

Structures don't support inheritance.

Stack objects are always being passed by value. Structs don't need deinitializers because of it. That also causes absence of reference counting mechanism and shared ownership.

If you have mutable property in the structure and you decide to change its value, you'll receive new `struct` instance with mutated property.
