# Basics

In Swift you don't have to put semicolon to the end of every line unless you're willing to put two statements on the same line.

## Variables and Constants

To declare constant in Swift you'd need to use `let` keyword. For familiar variable you'd need `var`.

For constants it's not necessary to declare type of the value as compiler will try to define it itself from assigned value. But you can still declare variable type for both `let` and `var` values.

```Swift
print("Hello, World!")

let a1 = UIView()
let a2: UIView = UIView()

var b1 = 10
var b2: Int = 20
```

### Optionals

Swift has a way to declare a variable that may or may not contain a value:

```Swift
var maybeThing: String? = nil
maybeThing = "Hi"
```

This could be used to work with objects:

```Swift
var view0: UIView?
var view1: Optional<UIView>    // same thing, syntax sugar

var frame0 = view0?.frame
var frame1 = view1!.frame    // optional force unwrapping
```

Note that in case of `frame0` variable it will aquire `Optional` value in case this property exists on `view0`. In case of `view1!` we won't perform the check if `view1` contains `frame` property and in case of success `frame1` will hold *non-optional* value. This might be useful if you don't want to mess around with `Optional` value too much.

```Swift
var view1: UIView? = nil
var view2: UIView? = UIView()

var f1 = view1?.frame    // nil
var f2 = view2?.frame    // optional frame value

var fx1 = view1!.frame   // RunTime Error
var fx2 = view2!.frame   // non-optional (pure) frame value
```

One of the ways of working with optional values is using `if let` construction. This would let us to unwrap optional value. This is considered kind of best practice:

```Swift
var view1: UIView? = nil
var view1: UIView? = UIView()

if let view1 = view1 {
    // we would not reach this block
}

if let view2 = view2 {
    /* we'll happily reach this block.
     * here view2 would not be optional anymore.
     */
}

// guard could be used to achieve similar behavior
guard let vs1 = view1 else {
    print("no value")
}

// function example
func getFrame(view: UIView?) -> CGRect {
    guard let view = view else {
        return .zero
    }
    return view.frame
}

// non Swift way for the same function
func getFrameBad(view: UIView?) -> CGRect {
    if let view = view {
        return view.frame
    } else {
        return .zero
    }
}
```

First `getFrame` function is implemented in a cleaner and more readable way. Consider these types of checks as best practice.

## Control Flow

Note that parenthesis are not necessary unless you'd want to affect operators priority in any way.

```Swift
if a == 10 {
    /* ... */
} else if a == 20 {
    /* ... */
} else {
    /* ... */
}
```

## Loops

### `for`

Once Swift had ordinary `for` loop, but it was deprecated and now Swift uses *range* based implementation:

```Swift
for i in 0..<10 {}    /* from 0 to 9 including */
for j in 0...10 {}    /* from 0 to 10 including */
```

### `while`

```Swift
var i = 0
while i < 10 {
    i += 1    /* note that Swift doesn't have ++ etc. */
}
```

```Swift
// ordinary do ... while
var i = 0
repeat {
    i += 1
} while i < 10
```

Note that Swift uses `repeat` instead of `do` like many languages do 😉

### `for ... each`

Swift can iterate through *collections* with the following syntax:

```Swift
let arr = [1, 2, 3]
for element in arr {
    /* ... */
}
```

## `try ... catch`

Swift's way to constructing *try - catch* blocks is a little not ordinary:

```Swift
do {
    try doSomething()
} catch {
    print(error)
}
```

### generating errors

To indicate that particular function is capable of creating an error we need to explicitly state this fact in its signature:

```Swift
enum DoorErrors: Error {
    case somethingBad
}

func handleTheDoor() throws {
    /* ... */
    throw DoorErrors.somethingBad
}
```

Usually you'll see enums as the way to declare error types.

## Functions

```Swift
// simple function / procedure
func foo() {}

// function with return value
func bar() -> Int {
    return 2
}
```

Swift inherits the concept of inner and outer names for the arguments. Usually they share the same name.

```Swift
func say1(p: String) {
    print(p)
}
say1(p: "Hello, World!")

// function with outer and inner name
func say2(phrase p: String) {
    print(p)
}
say2(phrase: "Hello, World!")

// function that does not label the argument
func say3(_ p: String) {
    print(p)
}
say3("Hello, World")
```

### Default Argument Value

Swift supports default values for arguments:

```Swift
func subtraction(lhs: Int = 0, rhs: Int = 0) -> Int {
    return lhs - rhs
}

subtraction()                  //  0
subtraction(lhs: 1)            //  1
subtraction(rhs: 1)            // -1
subtraction(lhs: 9, rhs: 1)    //  8
```

### `guard`

`guard` statement is like inverse `if`. We declare condition which we want to be true and do something in case it fails. This might help to verify function inputs (arguments). This is related to the concept of *golden path* or *happy path*.

```Swift
func two(a: Int) -> String? {
    guard a == 2 else {
        return nil
    }
    return "two"
```

### `defer`

Another useful thing in Swift is `defer` statement. This is something alike to `finally` in `try ... catch ... finally` construct from JavaScript. This statement ensures that logic wrapped with `defer` will be executed just before leaving current block of code.

```Swift
func readFiles() {
    let file = openFile()
    defer { closeFile(file) }

    /* ...
     * we don't need to bother closing
     * opened file anymore
     */
}
```
