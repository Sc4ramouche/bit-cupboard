# Week 2: Functions

Function example in Python with docstring contained between a pair of `"""`:

```Python
def isEven( i ):
    """
    Input: i, a positive int
    Returns True if i is even, otherwise False
    """
    return i % 2 == 0
```

In case you don't `return` anything from a function, it will return `None` type – the absence of value.

## Invocation

Consider we have a function `printName`:

```Python
def printName(firstName, lastName, reverse):
    # ...
```

In Python you can not conform with formalism, and you can mix the order of the passed arguments as long as you add labels to them. So this is legal call of the function:

```Python
printName(reverse = False, firstName = 'eric', lastName = 'grimson')
```

Python also supports default argument values. Works similarly to JavaScript:

```Python
def printName(firstName, lastName, reverse = False)
```

## Recursion

When you design induction algorithm, you can take the advantage of _mathematical induction_: to prove a statement indexed on integers is true for all values of `n`:

- Prove it is true when `n` is smallest value (e.g. `n = 0` or `n = 1`)
- Then prove that if it is true for an arbitrary value of `n`, one can show that it must be true for `n + 1`

## Tower of Hanoi

Tower of Hanoi is a math puzzle where we have **three** rods and `n` disks. The objective is to move the entire stack to another rod, obeying the rules:

1. only onde disk can be moved at a time
2. a disk can only be moved if it is the uppermost disk on a stack
3. no disk may be placed on top of a smaller disk

Python solution for this puzzle:

```Python
def printMove(fr, to):
    print('move from ' + str(fr) + ' to ' + str(to))

def Towers(n, fr, to, spare):
    if n == 1:    # this is recurion base case
        printMove(fr, to)
    else:
        Towers(n - 1, fr, spare, to)
        Towers(1, fr, to, spare)
        Towers(n - 1), spare, to, fr)
```

In this code `n` is total number of disks in initial stack, `fr` – initial rod, from which we're going to move the whole stack, `to` – destionation, and `spare` – auxiliary rod we'll use to move disks.
