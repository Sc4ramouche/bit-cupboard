# Protocols

A *protocol* defines a blueprint of methods, properties, and other requiremenets that suit a particular task or piece of functionality. The protocol can then be adopted by a class, structure, or enum to provide an actual implementation of those requirements.

```Swift
protocol Vehicle {
    var isMoving: Bool { get }
    var name: String { get set }
    func move(to: CGPoint)
}
```

Protocol `Vehicle` declares readable `isMoving` property, readable and writable `name` and `moveTo` method. Example of the class which implements the `Vehicle` protocol:

```Swift
class Car: Vehicle {
    var isMoving = true
    var name = "Tuzik"
    func move(to: CGPoint) {
        /* ... */
    }
}
```

Swift does not support multiple inheritance (unlike C++), so for every class there should be exactly one superclass. But you're able to implement as many protocols as you want for one class.

Protocols can have associated type:

```Swift
protocol Soldier {
    associatedtype Weapon
    var weapon: Weapon { get }
}
```

## Protocol Extensions

Protocols can be extended to provide method, initializer, subscript, and computed property implementations to conforming types. This allows you to define behavior on protocols themselves, rather than in each type's individual conformance or in a global function.

Example – extension for `RandomNumberGenerator` protocol. The protocol itself assumes you have to implement `random` method. And extension can rely on this implementation:

```Swift
extension RandomNumberGenerator {
    func randomBool() -> Bool {
        return random() > 0.5
    }
}
```

By creating an extension on the protocol, all conforming types automatically gain this method implementation without any additional modification.
