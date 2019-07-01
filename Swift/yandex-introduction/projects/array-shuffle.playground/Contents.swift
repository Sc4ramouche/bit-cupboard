import UIKit

extension Array {
    mutating func myShuffle() {
        var n = self.count - 1
        var temp: Element
        
        for _ in self {
            let random = Int.random(in: 0...n)
            
            temp = self[n]
            self[n] = self[random]
            self[random] = temp
            
            n -= 1
        }
    }
}

var arr = [1, 2, 3, 4, 5]
arr.myShuffle()

for element in arr {
    print(element)
}

/* --------------------- */

func calcLetters(str: String) -> [String: Int] {
    return [str: str.count]
}

print(calcLetters(str: "Word"))
