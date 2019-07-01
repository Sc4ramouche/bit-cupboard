import UIKit

extension String {
    static func random(length: Int) -> String {
        guard length > 0 else {
            return ""
        }
        
        let letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        var result = ""
        
        for _ in 0..<length {
            result.append(letters.randomElement()!)
        }
        
        return result
    }
}

print("Random string of length 4: \(String.random(length: 4))")
print("Random string of length 7: \(String.random(length: 7))")
