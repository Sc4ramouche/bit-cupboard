# Introduction to iOS 11, Xcode 9 and Swift 4

## Xcode

Xcode has interface builder. And if we, for example, add the button to the view – we're able to see different properties in the *Attributes inspector*. And what's special abouth that – everything is described in the sense of the object oriented programming. There we would have `Button` section with different options, which is followed by `Control`, and the last section is `View`. And that's exactly how things are described in the object-oriented sence: `Control` inherits from `View`, and button inherits from `Control`.

If you need a hint about particular documentation you can try to hold *option* (`⌥`) and click something you want to learn about, like class method.

There's common mistake related to the interface builder – if you copy something, you really want to make sure that you didn't get the events of the copied UI element if you don't need them. To do so you'd need to **right click** the new copy and check for the connections between the elements.

Instance variables (a.k.a properties) could be used without dedicated `init` function. This is achieved by using default value:

```Swift
class ViewController: UIViewController {
    var flipCount: Int = 0
}
```

Swift is strongly typed language. And it also has *strong type inference*, which means it will (if it can) guess the proper type for you. And it's not necessary to put types explicitly in some cases, like when you declare simple variables:

```Swift
var flipCount = 0    // Swift will know that it's an Int variable
```

## Property Observer

Property observervers respond to changes in a property's value. Property observers are called every time a property's value is set, even if the new value is the same as the preprty's current value.

You can define:

* `willSet` – called just before the value is stored
* `didSet` – called immediately after the new value is stored

```Swift
class StepCounter {
    var totalSteps: Int = 0 {
        willSet(newTotalSteps) {
            print("About to set totalSteps to \(newTotalSteps)")
        }
        didSet {
            if totalSteps > oldValue {
                print("Added \(totalSteps - oldValue) steps")
            }
        }
    }
}
```

Notice that for `willSet` observer you pass the new property value as constant parameter. Similarly, if you implement `didSet` observer, it's passed a constant parameter `oldValue`.

## Renaming things in Xcode

Similar to clicking with option key (`⌥`), you can click things with command key (`⌘`). And there you can rename things properly, so you don't accidentally break connection with interface builder, for example. Another handy thing here is *Jump to defintion option*. Speaks for itself. Another handy thing here is *Jump to defintion option*. Speaks for itself.

## Optional

`Optional` is special type and has two states: *set* and *nonSet*.

## `nil` semantics

In Swift `nil` is used to indicate that `Optional` value is not set.
