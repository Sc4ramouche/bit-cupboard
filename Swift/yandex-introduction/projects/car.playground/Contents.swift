import UIKit

struct Position {
    var x: Int
    var y: Int
}

enum Direction {
    case left
    case forward
    case right
    case backward
}

struct Go {
    let direction: Direction
    let distance: Int
}

class Car {
    let make: String
    let model: String
    var position: Position
    
    init(make: String, model: String, position: Position) {
        self.make = make
        self.model = model
        self.position = position
    }
    
    public func move(direction: Direction, distance: Int) {
        switch direction {
        case Direction.left:
            position.x -= distance
        case Direction.forward:
            position.y += distance
        case Direction.right:
            position.x += distance
        case Direction.backward:
            position.y -= distance
        }
    }
    
    public func execute(command: Go) {
        self.move(direction: command.direction, distance: command.distance)
    }
}

let car = Car(make: "Tesla", model: "Model X", position: Position(x: 0, y: 0))
print("Initial position: x: \(car.position.x), y: \(car.position.y)")          // x: 0, y: 0

car.move(direction: .left, distance: 8)
car.move(direction: .forward, distance: 4)
print("Position after move: x: \(car.position.x), y: \(car.position.y)")       // x: -8, y: 4

car.execute(command: Go(direction: .right, distance: 10))
car.execute(command: Go(direction: .backward, distance: 2))
print("Position after execute: x: \(car.position.x), y: \(car.position.y)")    // x: 2, y: 2

