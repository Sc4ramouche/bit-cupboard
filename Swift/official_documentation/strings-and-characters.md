Text and code snippets origin: [swift.org](https://swift.org)

# Strings and Characters

Multiline strings are created with triple quotes `"""` and can be intended. They don't count line break at the start and at the end. That's similar to Python.

Another similar thing is *raw strings*. When you don't need to invoke special characters like `\n`, you wrap the strign with `#`: `#"Line 1\nLine2"#`.

## Initializing an Empty String

There are two ways to create an *empty string*:

```Swift
var emptyString = ""
var anotherEmptyString = String()
```

You can check this with `emptyString.isEmpty`. That would be `true`.

## String Mutability

Depends on the way you declare the string: it would be immutable if declared with `let` and mutable if declared with `var`.

## Strigns are Value Types

Swift's String type is a *value type*. If you create a new String value, that String value is copied when it's passed to a function or method, or when it's assigned to a constant or variable.

## Working with Character

You can access the individual Character values by iterating over the string with a for-in loop. You can also create a stand-alone `Character` constant or variable from a single-character string.

```Swift
lex exclamationMark: Character = "!"
```

`String` values can be constructed by passing an array of `Character` values to its initializer:

```Swift
let catCharacters: [Character] = ["C", "a", "t", "!"]
let catString = String(catCharacters)
```

## Concatenating Strings and Characters

```Swift
let string1 = "hello"
let string2 = " there"
var welcome = string1 + string2    // "hello there"

var instructions = "look over"
instruction += string2             // "look over there"

welcome.append("!")                // "hello there!"
```

## String Interpolation

```Swift
let multiplier = 3
let message = "\(multiplier) times 2.5 is \(Double(multiplier) * 2.5)"
```

## Unicode Scalar Values

Swift's `String` and `Character` types are fully Unicode-compliant. Swift's native `String` type is built from *Unicode scalar values*. It's a unique 21-bit number for a character or modififer, such as `U+0061` for `"a"`.

## String Indices

Each `String` value has an associated *index type*, `String.Index`, thich corresponds to the position of each `Character` in the string.

```Swift
let greeting = "Guten Tag!"
greeting[greeting.startIndex]                                  // G
greeting[greeting.index(before: greeting.endIndex)]            // !
greeting[greeting.index(after: greeting.startIndex)]           // u
let index = greeting.index(greeting.startIndex, offsetBy: 7)
greeting[index]                                                // a
```

Use the `indecis` property to access all of the indices of individual characters in a string:

```Swift
for index in greeting.indices { /* ... */ }
```

## Inserting and Removing

To insert a single character you can use `insert(_:at:)`, to insert the contents of another string use `insert(contentsOf:at:)`.

```Swift
var welcome = "hello"
welcome.insert("!", at: welcome.endIndex)    // "hello!"

welcome.insert(contentsOf: " there", at welcome.index(before: welcome.endIndex))
```

To remove a single character use the `remove(at:)`, to remova a substring – `removeSubrange(_:)`.

```Swift
let range = welcome.index(welcome.endIndex, offsetBy: -6)..<welcome.endIndex
welcome.removeSubrange(range)
```

## Substrings

When you get a substring from a string in Swift you receive `Substring` type, not another `String`. They have most of the same methods as strings, however they are intended to be used for short amount of time. When you're ready to store the result, you convert the substring to an instance of `String`.

The difference between strings and substrings is that, a substring can reuse part of the memory that's used to store the original string, oro part of the memory that's used to store another substring. This means you don't have to pay the cost of copying memory until you modify either the string or substring.

## Comparing Strings

Swift provides three ways to compare textual values: string and character equality, prefix equality, and suffix equality.

### String and Character Equality

Two `String` (of `Character`) values are considered equal are considere equal if their extended grapheme clusters are canonically equivalent – if they have the same linguistic meaning and appearance, even if they're composed from different Unicode scalars.

### Prefix and Suffix Equality

To check whether a string has a particular string prefix or suffix, call the string's `hasPrefix(_:)` and `hasSuffix(_:)` methods.

