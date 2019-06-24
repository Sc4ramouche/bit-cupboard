import UIKit

func sum<T: Numeric>(lhs: T, rhs: T) -> T {
    return lhs + rhs
}

print(sum(lhs: 1, rhs: 2))
print(sum(lhs: 1.2, rhs: 2.8))
