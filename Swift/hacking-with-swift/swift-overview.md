# General info

- **UIKit** is interface toolkit focused on iOS.
- **AppKit** is interface toolkit focused on macOS.
- **CocoaTouch** is the name commonly used for Apple's vast collection of frameworks for iOS. It includes UIKit to do user interfaces, but most people would say it also includes SpriteKit for making 2D games, SceneKit for making 3D games, MapKit for maps, Core Graphics for drawing, Core Animation for animating things, and much more.
- **Cocoa** is the name used for Apple’s framework collection on macOS. Strictly speaking it’s made up of AppKit for user interface, Foundation for basic functionality, and Core Data for object graphs, but like Cocoa Touch it’s often used to mean “all of macOS development.”

## Variable and Constants

When it comes about `Float` and `Double`, you better use `Double` – that's Apple's official recommendation.

### Type Inference

There are two ways to tell Swift what type of data a variable holds: assign a value when you create the variable, or use a type annotation. Former is preferable, it's consideret to be more comprehensible. This technique is called _type inference_, because Swift can infer what data type should be used for a variable by looking at the type of data you want to put in there. When it comes to numbers like -3.1415, Swift will always infer `Double`.

### Optionals

An optional value is one that might have a value or might not.

Optional values must be unwrapped before being used. Here's the syntax:

```Swift
if let unwrappedStatus = status {
    // unwrappedStatus contains a non-optional value
} else {
    // in case there's nil and you need to do anything else...
}
```

There's also neat *nil coalescing operator*:

```Swift
// if optional returned by albumReleased function will contain `nil`,
// then "unknown" will be used as assigned value
let album = albumReleased(year: 2006) ?? "unknown"
```

Another way to safely work with optionals is through chaining:

```Swift
// album will containt `nil` or uppercased value
let album = albumReleased(year: 2006)?.uppercased()
```

### Enumerations

Enums can have additional values in Swift!

```Swift
enum WeatherType {
    case sun
    case cloud
    case rain
    case wind(speed: Int)
    case snow
}

func getHaterStatus(weather: WeatherType) -> String? {
    switch weather {
        case .wind(let speed) where speed < 10:
            return "meh"
        case .cloud, .wind:
            return "dislike"
        default:
            return "hate"
    }
}
```

### Closures

Closures are close in spirit to what we have in JavaScript. Closures capture environment and contain statements to be executed.

```Swift
let vm = UIView()

UIView.animate(withDuration: 0.5, animations: {
    vm.alpha = 0
})
```

Notice how closure captures `vm` value. So later, when this code actually gets executed, it would still have access to `vm`.

Little syntactic sugar – *trailing closures*. If the last parameter to a method takes a closure, you can eliminate that parameter and instead provide it as a block of code:

```Swift
UIView.animate(withDuration: 0.5) {
    vm.alpha = 0
}
```

### self nuances

There're actually two selves in Swift: `self`, referring to current value, and `Self`, referring to current type.
