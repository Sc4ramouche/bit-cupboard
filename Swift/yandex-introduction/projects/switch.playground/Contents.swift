import UIKit

/*
 * Swift allows you to make switch
 * more complex, i.e. depending on tuple
 */
let a = true
let b = false

switch (a, b) {
case (true, false):
    print("true | false")
default:
    print("not the case")
}

// You can use switch to process Optional values
let p: String? = "sample"

switch p {
case .some:
    print("Unwrapped value: \(p!)")
case .none:
    print("nil")
}

// Tuple switch statement
let val = (5, "sample", 3.14)

switch val {
case (_, _, let pi):
    // extracting 3.14
    print("pi is \(pi)")
default:
    print("default")
}
