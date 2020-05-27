# source: http://composingprograms.com/pages/23-sequences.html


def divisors(n):
    """ Returns all the divisors for n """
    return [1] + [i for i in range(2, n) if n % i == 0]


# using devisors, we could list all perfect numbers in a given range
[n for n in range(1, 1000) if sum(divisors(n)) == n]
