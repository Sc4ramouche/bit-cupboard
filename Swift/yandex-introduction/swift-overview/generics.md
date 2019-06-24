# [Generics](https://docs.swift.org/swift-book/LanguageGuide/Generics.html)

Generic code enbles you to write flexible, reusable functions and types that can work with any type. You can write code that avoid duplication and expresses its intent in a clear, abstracted manner.

## Generic functions

Simple usecase for this – function that adds two objects together. You'd need to write separate implementations for `Int` and `Double`, etc. But you can achieve this with generic function:

```Swift
func sum<T: Numeric>(lhs: T, rhs: T) -> {
    return lhs + rhs
}

print(sum(lhs: 1, rhs: 2))        // 3
print(sum(lhs: 1.2, rhs: 2.8))    // 4.0
```

Note that for this function you'd need to make sure that passed in objects support `+` operation. In the example above we achieve this by using `Numeric` generic type.

## Generic types

Swift enables you to define your own *generic types*. These are custom classes, structures, and enumerations that can work with *any* type, in a similar way to `Array` and `Dictionary`.

There's *stack* data structure implementation **without** using generic code:

```Swift
struct IntStack {
    var items = [Int]()
    mutating func push(_ item: Int) {
        items.append(item)
    }
    mutating func pop() -> Int {
        return items.removeLast()
    }
}
```

This structure uses an `Array` property called `items` to store the values in the stack. `push` and `pop` methods marked as `mutating`, because they need to modify (or *mutate*) the `items` array.

Example above can only be used with `Int` values. Here's a generic version of the same code:

```Swift
struct Stack<Element> {
    var items = [Element]()
    mutating func push(_ item: Element) {
        items.append(item)
    }
    mutating func pop() -> Element {
        return items.removeLast()
    }
}
```

Note that for sake of brevity there's no check for stack to be empty in `pop` function.
