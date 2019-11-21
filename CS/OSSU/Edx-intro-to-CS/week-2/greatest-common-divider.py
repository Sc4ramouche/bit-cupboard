def gcdIter(a, b):
    '''
    a, b: positive integers

    returns: a positive integer, the greatest commond divisor of a & b.
    '''
    res = min(a, b)

    while res > 0:
        if a % res == 0 and b % res == 0:
            return res
        else:
            res -= 1

# test
print(gcdIter(2, 12))
print(gcdIter(6, 12))
print(gcdIter(9, 12))
print(gcdIter(17, 12))

# there's a bit shortened implementation:
def gcdIterShortened(a, b):
    res = min(a, b)

    while a % res != 0 or b % res != 0:
        res -= 1

    return res
