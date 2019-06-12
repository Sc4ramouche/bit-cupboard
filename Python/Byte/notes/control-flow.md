# Control Flow

In Python control flow is mostly achieved with `if`, `for` and `while` statements. Unsurprisingly. Python support `break` and `continue` in familiar way.

## `if`

Note that Python use elegant `elif`. Example:

```Python
if guess == number:
    print('You guessed it!')
elif guess < number:
    print('Too low.')
else:
    print('Too high.')
```

There is no `switch` statement in Python. You could use a dictionary to imitate `switch` behaviour.

## `while`

Just example:

```Python
number = 3
while number > 0:
    print('{}!'.format(number))
    number -= 1
```

## `for`

The `for..in` statement iterates over a *sequence* of objects. Sequence in just an ordered collection of items.

```Python
for i in range(1, 5):
    print(i)
else:
    print('The for loop is over')
```

Surprisingly, `for` loop supports `else` statement. It's optional, always executed once after the `for` loop is over **unless** a `break` statement is encountered.

The `for` loop iterates over `range(1, 5)` in the example above, which is equivalent to `for i in [1, 2, 3, 4]` which is like assigning each number (or object) in sequence to 'i', one at a time, and then executing the block of statements for each value of `i`.

In general, we can use `for..in` loop with any kind of sequence of any kind of objects.

### Note on `range`

`range` function generates the `[1, 2, 3, 4]` sequence. It can also take third argument which becomes step count, so `range(1, 5, 2)` will result in `[1, 3]`.

Note that `range()` generates only one number at a time, if you want the full list of numbers, call `list()` on the `range()`, for example: `list(range(5))` will result in `[0, 1, 2, 3, 4]`.
