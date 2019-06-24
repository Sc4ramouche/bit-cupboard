import UIKit

class Car {
    func drive(to location: String) {
        print("driving you to \(location)")
    }
}

let car = Car()
car.drive(to: "paradise")

/* more complex example
   with getter and setter */
struct Point {
    var x = 0.0, y = 0.0
}
struct Size {
    var width = 0.0, height = 0.0
}
struct Rect {
    var origin = Point()
    var size = Size()
    var center: Point {
        get {
            let centerX = origin.x + (size.width / 2)
            let centerY = origin.y + (size.height / 2)
            return Point(x: centerX, y: centerY)
        }
        set {
            origin.x = newValue.x - (size.width / 2)
            origin.y = newValue.y - (size.height / 2)
        }
    }
}

var square = Rect(origin: Point(x: 0.0, y: 0.0), size: Size(width: 10.0, height: 10.0))
let initialSquareCenter = square.center
print("initial – x:\(square.center.x) y:\(square.center.y)")                 // initial center is at (x:5.0, y:5.0)
square.center = Point(x: 15.0, y: 15.0)                                      // move center to (x:15.0, y:15.)
print("new – x:\(square.center.x) y:\(square.center.y)")
print("square.origin is now at (\(square.origin.x), \(square.origin.y))")     // rectangle now starts at (x:10.0, y:10.0)
