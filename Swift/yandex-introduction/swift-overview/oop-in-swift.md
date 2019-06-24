# OOP Concepts in Swift

Swift is object-oriented language.

```Swift
class Car {
    let mark: String
    let model: String
    var mileage: Int

    static let steelType: Int
    class var productionAmout: Int

    func drive(to location: CLLocation) {
        /* ... */
    }
}
```

## Properties and methods

There are `static` and `class` keywords which serve to associate a method or a property with a class, rather than an instance of a class. The difference is that subclasses can override `class` methods; they cannot override `static` methods.

Accessing instance properties and methods is similar to most programming languages (`.` dot notation).

```Swift
let car = Car()
print(car.model)
car.mileage += 1
```

## `get` & `set`

When you declare a class property with `var` keyword, Swift allocates memory (depending on type) for this property. But you can declare *computed* properties which will be available like public properties, but they are functions actually and they don't store a value. In this case you'd need to declare *setter* and *getter* functions:

```Swift
class Car {
    /* ... */
    var origin = Point()
    size = Size()
    var center: Point {
        get {
            let centerX = origin.x + (size.width / 2)
            let centerY = origin.y + (size.height / 2)
            return Point(x: centerX, y: centerY)
        }
        set(newCenter) {
            origin.x = newCenter.x - (size.width / 2)
            origin.y = newCenter.y - (size.height / 2)
        }
    }
}
```

For `set` function you can actually omit declaration of the argument and use `newValue` instead:

```Swift
var buyDate: Date
var buyTimestamp: TimeInterval {
    set { buyDate = Date(timeIntervalSince1970: newValue) }
    get { return buyDate.timeIntervalSince1970 }
}
```

In case you need *readonly* property you can omit *setter* function. Example:

```Swift
var buyTimestamp: TimeInterval {
    return buyDate.timeIntervalSince1970
}
```

## Access Control

The list is:

* `private`
* `public`
* `private set` – inside of a class behaves like public, but readonly for the rest of the world
* `fileprivate` – public for all objects inside current file and *private* in other files

```Swift
class Car {
    private let model: String
    public var mileage: Int
    private(set) var guardian: String = "Sentinel"
    fileprivate var ownedBy: UUID
}
```

If you don't explicitly specify access modifier, property or method will get `internal` modifier, which behaves like public (read and write access), but for the objects outside of current module or binary file it would be treated like `private`.

## Initialization

Swift doesn't have a concept of constructor and destructor. The are *initialization* and *deinitialization* instead. In an initializer function you have to call `super.init()`. Example:

```Swift
class Car {
    init(make: String, model: String) {
        self.mark = mark
        self.model = model
        super.init()
    }

    deinit {
     /* ... */
    }
}
```

There are two types of initializers in Swift: *designatated* and *convenience*. Former is like basic initializer for the class and the latter is supportive one. You'd need to call designated initializer from conveniecne initializer still like *super*.
