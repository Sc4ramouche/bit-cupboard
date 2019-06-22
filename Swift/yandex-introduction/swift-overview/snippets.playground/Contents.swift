import UIKit

func say(phrase p: String) {
    print(p)
}
say(phrase: "Hello, World!")

func subtraction(lhs: Int = 0, rhs: Int = 0) -> Int {
    return lhs - rhs
}

print(subtraction())    // 0
print(subtraction(lhs: 1))    // 1
print(subtraction(rhs: 1) )   // -1
print(subtraction(lhs: 9, rhs: 1))    // 8

// fibonachi implementation
func fibonachi (n: Int) -> Int {
    var i = 0
    while i < n {
        <#code#>
    }
}
