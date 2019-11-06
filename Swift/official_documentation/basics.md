Text and code snippets origin: [swift.org](https://swift.org)

# The Basics

## Constants and Variables

You can declare multiple constants or multiple variables on a single line, separated by commans and use a single type annotation:

```Swift
var x = 0.0, y = 0.0, z = 0.0
var red, green, blue: Double
```

## Integers

Swift provides signed and unsigned integers in 8, 16, 32 and 64 bit forms. These integers follow a naming convention similar to C, in that an 8-bit unsigned integer is of type `UInt8`, and a 32-bit signed integer is of type `Int32`.

### Integer Bounds

You can access the minimum and maximum values of each integer type with its `min` and `max` properties:

```Swift
let minValue = UInt8.min  // 0
let maxValue = UInt8.max  // 255
```

### `UInt`

Use `UInt` only when you specifically need an unsigned integer type with the same size as the platform's native word size. If this isn't the case, `Int` is preferred, even when the values to be stored are known to be nonnegative.

## Type Aliases

*Type aliases* define an alternative name for an existing type. You define type aliases with the `typealias` keyword.

Tye aliases are useful when you want to refer to an existing type by a name that is contextually more appropriate, such as when working with data of specific size from an extrernal source:

```Swift
typealias AudioSample = UInt16
var maxAmplitudeFound = AudioSample.min
```

## Tuples

*Tuples* group multiple values into a single compound value. The values within a tuple can be of any type and don't have to be of the same type as each other.

```Swift
let http404Error = (404, "Not Found")

// decompose tuple's contents
let (statusCode, statusMessage) = http404Error

// if you only need some of the tuple's values
let (justTheStatusCode, _) = http404Error

// access the individual element usin index
print("Status code: \(http404Error.0)")    // Status code: 404
```

You can name the individual elements in a tuple when the tuple is defined. You can use these names to access the values later:

```Swift
let http200Status = (statusCode: 200, description: "OK")
print("Status code: \(http200Status.statusCode)")    // Status code: 200
```

You can create tuples from any permutation of types, and they can contain as many different types as you like. You can have a tuple of type `(Int, Int, Int)`.

Tuples are particularly useful as the return values of functions. A function that tries to retrieve a web page might return the `(Int, String)` tuple type to describe the success or failure of the page retrieval. By returning a tuple with two distinct values, each of a different type, the function provides more useful information about its outcome than if it could only return a single value of a single type.

If your data structure is lilely to be more complex though, model it as a class or structure, rather than as a tuple.

## Optionals

You use *optionals* in situations where a value may be absent.

Example: Swift's `Int` type has an initializer which tries to convert a `String` value to an `Int` value. However, not every string can be converted into an integer. Because the initializer might fail, it returns an *optional* `Int`, rather than an `Int`. This is expressed as `Int?`, not `Int`.

```Swift
let possibleNumber = "123"
let convertedNumber = Int(possibleNumber)
```

### `nil`

You set an optional variable to a valueless state by assigning it the special value `nil`. **You can't** use `nil` with non-optional constants and variables. If a constant or variable needs to work with the absence of a value, always declare it as an optional value of the appropriate type.

If you define an *optional* variable without providing a default value, it's automatically set to `nil`.

Swift's `nil` isn't the same as `nil` in Objective-C. In Objective-C, `nil` is a pointer to a nonexistent object. In Swift, `nil` isn't a pointer – it's the absence of a value of a certain type. Optionals of *any* type can be set to `nil`, not just object types.

### If Statements and Forced Unwrapping

You can use `if` statement to find out whether an optional contains a value. Once you're sure that the optional does containt a value, you can access its underlying value by adding an exclamation mark (`!`) to the end of the optional's name. This is known as *forced unwrapping* of the optional's value:
```Swift
if convertedNumber != nil {
    print("convertedNumber is \(convertedNumber!)")
}
```

Trying to use `!` to access a nonexistent optional value triggers a runtime error.

### Optional Binding

You use *optional binding* to find out whether an optional contains a value, and if so, to make that value available as a temporary constant or variable. Optional binding can be used with `if` and `while` statements to check for a value inside an optional, and to extract that value into a constant or variable, as part of a single action.

```Swift
if let constantName = someOptional { /* statements */ }
```

You can rewrite the `possibleNumber` example from above:

```Swift
if let actualNumber = Int(possibleNumber) {
    print("String to number convertion: success with value \(actualNumber)")
} else {
    print("Could not convert the string to an integer")
}
```

**NOTE:** constants and variables created with optional binding in an `if` statement are available only withing the body of the `if` statement. In contrast, the constants and variables created with a `guard` statement are available in the lines of code that follow the `guard` statement.

### Implicitly Unwrapped Optionals

Sometimes it's clear that an optional will *always* have a value, after that value is first set. In these cases, it's useful to remove the need to check and unwrap the optional's value every time it's accessed, because it can be safely assumed to have a value all of the time.

These kinds of optionals are defined as *implicitly unwrapped optionals*. You write an implicitly unwrapped optional by placing an exclamation mark (`String!`) rather than a question mark (`String?`).

This could be useful when an optional's value is confirmed to exist immediately after the optional is first defined and can definetely be assumed to exist at every point thereafter. The primary use of implicitly unwrapped optionals in Swift is during class initialization.

An implicitly unwrapped optional is a normal optional behind the scenes, but can also be used like a non-optional value, without the need to unwrap the optional value each time it's accessed.

```Swift
let possibleString: String? = "An optional string."
let forcedString: String = possibleString!    // requires an exclamation mark

let assumedString: String! = "An implicitly unwrapped optional string."
let implicitString: String = assumedString    // no need for an exclamation mark
```

## Error Handling

When a function encounters an error condition, it *throws* an error. That function's caller can then catch the error and respond appropriately. A function indicates that it can throw an error by including the `throws` keyword in its declaration. When you call a function that can throw an error, you prepend the `try` keyword to the expression.

```Swift
func canThrowAnError() throws {
    // this function may or may not throw an error
}
```

Swift automatically propagates errors out of their current scope until they're handled by a `catch` clause.

```Swift
do {
    try canThrowAnError()
} catch {
    // an error was thrown
}
```

Example of how error handling can be used to respond to different error conditions:

```Swift
do {
    try makeASandwich()    // func makeASandwich() throws { /* ... */ }
    eatASandwich()
} catch SandwichError.outOfCleanDishes {
    washDishes()
} catch SandwichError.missingIngredient(let ingredients) {
    buyGroceries(ingredients)
}
```

## Assertions and Preconditions

*Assertions* and *preconditions* are checks that happen at runtime. You use them to make sure an essentianl condition is satisfied before executing any further code. If the condition evaluates to `false`, the current state of the program is invalid; code execution ends, and you app is terminated.

Unlike the error conditions, assertions and preconditions aren't used for recoverable or expected errors. There's no way to catch a failed assertion.

Using assertions and preconditions isn't a substitute for designing your code in such a way that invalid conditions are unlikely to arise. However, using them to enforce valid data and state causes you app to terminate more predictably if an invalid state occurs, and helps make the problem easier to debug. Stopping execution as soon as an invalid state is detected also helps limit the damage caused by that invalid state.

The difference between assertions and preconditions is in when they're checked: Assertions are checked only in debug builds, but preconditions are checked in both debug and production builds. (TODO: clarify how exactly that works)

### Debugging with Assertions

You write an assertion by calling the `assert(_:_:file:line:)` function from standart library. You pass this function an expression that evaluates to `true` or `false` and a message to display if the result of the condition is `false`.

```Swift
let age = -3
assert(age >= 0, "A person's age can't be less than zero.")
```
