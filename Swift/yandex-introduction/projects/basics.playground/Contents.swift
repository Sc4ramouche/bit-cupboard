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
    guard n > 1 else {
        return 1
    }
    
    var n1 = 0
    var n2 = 0
    var sum = 1

    for _ in 1..<n {
        n1 = n2
        n2 = sum
        sum = n1 + n2
    }
    
    return sum
}

print(fibonachi(n: 8))
