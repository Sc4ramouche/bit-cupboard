import UIKit

struct Planet {
    let radius: Int
}

/* --- basic example --- */
enum Planets: Int {
    case mercury = 0
    case venus = 1
    case earth
    case mars
    case jupyter
    case saturen
    case neptune
    case uranus
    
    // computed property
    var isInnerPlanet: Bool {
        switch self {
        case .mercury, .venus, .earth, .mars:
            return true
        default:
            return false
        }
    }
    
    // function
    func distance(to planet: Planet) -> Double {
        return Double(arc4random())
    }
}

let m = Planets.mars
print(m.rawValue)
print(m.isInnerPlanet)
print(m.distance(to: Planet(radius: 6000)))


/* --- Associated values --- */
enum Barcode {
    case upc(Int, Int, Int, Int)
    case qrCode(String)
}

var productBarcode = Barcode.upc(8, 85909, 51226, 3)
productBarcode = .qrCode("ABCDEFGHIJKLMNOP")
