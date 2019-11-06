# General info

- **UIKit** is interface toolkit focused on iOS.
- **AppKit** is interface toolkit focused on macOS.
- **CocoaTouch** is the name commonly used for Apple's vast collection of frameworks for iOS. It includes UIKit to do user interfaces, but most people would say it also includes SpriteKit for making 2D games, SceneKit for making 3D games, MapKit for maps, Core Graphics for drawing, Core Animation for animating things, and much more.
- **Cocoa** is the name used for Apple’s framework collection on macOS. Strictly speaking it’s made up of AppKit for user interface, Foundation for basic functionality, and Core Data for object graphs, but like Cocoa Touch it’s often used to mean “all of macOS development.”

## Variable and Constants

When it comes about `Float` and `Double`, you better use `Double` – that's Apple's official recommendation.

### Type Inference

There are two ways to tell Swift what type of data a variable holds: assign a value when you create the variable, or use a type annotation. Former is preferable, it's consideret to be more comprehensible. This technique is called _type inference_, because Swift can infer what data type should be used for a variable by looking at the type of data you want to put in there. When it comes to numbers like -3.1415, Swift will always infer `Double`.
