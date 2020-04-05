from math import sqrt

def improve(update, close, guess = 1):
    while not close(guess):
        guess = update(guess)

    return guess

# golden ratio is one less than its square
# 1.6180339^2 = 2.6180339
def square_close_to_successor(guess):
    return approx_eq(guess * guess, guess + 1)

# golden ratio can be computed by repeatedly summing the inverse of any positive number with 1
# phi = 1 + 1 / phi
def golden_update(guess):
    return 1 + 1 / guess

def approx_eq(x, y, tolerance=1e-15):
    return abs(x - y) < tolerance

golden_ratio = improve(golden_update, square_close_to_successor)

# test
phi = 1/2 + sqrt(5)/2
def improve_test():
    approx_phi = improve(golden_update, square_close_to_successor)
    assert approx_eq(phi, approx_phi), 'phi differs from its approximation'
