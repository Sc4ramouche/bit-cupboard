# [Enumerations](https://docs.swift.org/swift-book/LanguageGuide/Enumerations.html)

Enumerations have rich functionality in Swift. They support computed properties and functions.

```Swift
enum Planets {
    case mercury
    case venus
    case eart
    case mars
    case jupyter
    case saturn
    case neptune
    case uranus
}
```

Note that enum elements should start with lowercase letter (since Swift 3).

In C or TypeScript each enum element is linked to an integer value. In Swift no value is linked to enum element by default. But you can declare type of the matching value for `enum` and provide what's called *raw value*:

```Swift
enum Planets: Int {
    case mercuru = 0
    case venus = 1
    case earth       // following elements don't need
    case mars        // explicit raw value, as compiler
    case jupyter     // will expand them automatically
    /* ... */
}

let m = Planets.mars
print(m.rawValue)    // 3
```

## Associated Values

You can define Swift enumerations to store associated values of any given type, and the value types can be differenet for each case of the enumeration if needed.

```Swift
enum Barcode {
    case upc(Int, Int, Int, Int)
    case qrCode(String)
}
```

This can be read as: "define an enum type called `Barcode`, which can take either a value of `upc` with an associated value of type `(Int, Int, Int, Int)`, or a value of qrCode with an associated value of type `String`.

The definition doesn't provide any actual `Int` or `String` values – it just defines the type of the associated values. You can then create new barcode using either type:

```Swift
    var productBarcode = Bardoce.upc(8, 85909, 51225, 3)
    productBarcode = .qrCode("ABCDEFGHIJKLMNOP")
```

You can extract associated values in `switch` statement:

```Swift
switch productBarcode {
case .upc(let numberSystem, let manufacturer, let product, let check):
    print("UPC: \(numberSystem), \(manufacturer), \(product), \(check).")
case .qrCode(let productCode):
    print("QR code: \(productCode).")
}
// Prints "QR code: ABCDEFGHIJKLMNOP."
```

Another usecase for using associated values in enumeration could be handling network respone:

```Swift
enum Result {
    case success(data: Data, header: [String: Any])
    case failure(error: Error)
}
```

## Computed Values

```Swift
enum Planets {
    case mercury, case venus, case earth /* ... */

    // computed property
    var isInnerPlanet: Bool {
        switch self {
            case .mercury, .venus, .earth, .mars: return true
            defalut: return false
        }
    }

    // enum function example
    func distance(to planet: Planet) -> Double {
        return Double(arc4random())
    }
}

let m = Planets.mars
print(p.isInnerPlanet)           // true
print(p.distance(to: .venus))    // random distance
```

### Associated & Raw value

You can't have associated and raw value together by default, but there is workaround for that: enumeration elements are objects, so we can declare *computed* value for them.

```Swift
enum Result {
    case success(data: Data, header: [String: Any])
    case failure(error: Error)

    var rawValue: String {
        switch self {
            case .success: return "success"
            case .failure: return "failure"
        }
    }
}
```
