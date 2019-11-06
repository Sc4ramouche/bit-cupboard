# Notes on bullseye

When you create SwiftUI project, initially it would have `ContentView.swift` file, which has `ContentView` and `body` property which has `some View` type. This means that this is not exactly an `View`, but an object that behaves like `View` – contain same properties and methods.

When you call a method on an object, it might create new instance of the object:

```Swift
Text("Hello world!")
    .fontWeight(.semibold)
    .foregroundColor(Color.green)
```

Both calls here return brand new object.

## Managing state

With SwiftUI you're able to add special property to the View object with `@State` keyword. Whenever it is being changed, the `body` should be refreshed.

```Swift
@State var alertIsVisible: Bool = false
```

When you use such kind of variables, you prepend them with `$` sign.

You can add `alert` call to the button. And nice thing is that `dismissButton` will automatically manage `$alertIsVisible` state:

```Swift
.alert(isPresented: $alertIsVisible) { () ->
  Alert in
  return Alert(title: Text("Hello there"),
             message: Text("First popup"),
       dismissButton: .default(Text("Dismiss")))
}
```
