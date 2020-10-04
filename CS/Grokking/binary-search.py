def binary_search(elements, target):
    left = 0
    right = len(elements) - 1

    while left <= right:
        middle = (left + right) // 2
        guess = elements[middle]

        if guess == target:
            return middle

        if target < guess:
            right = middle - 1
        
        if target > guess:
            left = middle + 1

    return None

print(binary_search([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 8))