# Basics

## Types

Python uses *objects* as a values.

You can use handy `is` operator to check for particular type, like this:

```Python
if type(varA) is str:
    print('string')
```

### Scalar Objects

* `int` – represent *integers*, ex. `5`
* `float` – represent *real numbers*, ex 3.27
* `bool` – represent *Boolean* values `True` and `False`
* `NoneType` – special and has one value, `None`

You can use `type()` to see the type of an object.

### Casting

```Python
float(5)    # 5.0
int(3.9)    # 3
bool(42)    # True
```

## Operators on ints and floats

* `i + j` – the sum
* `i - j` – the difference
* `i * j` – the product
* `i / j` – division. Result is `float`
* `i // j` – int division. Result is `int`, quotient without remainder
* `i % j` – the remainder when `i` is divided by `j`
* `i ** j` – `i` to the power of `j`

## Strings

```Python
# slice example
'Gratitude'[2:5]    # 'ati'
'Gratitude'[:5]     # 'Grati'
'Gratitude'[2:]     # 'atitude'

# copy a string
'Gratitude'[:]      # 'Gratitude'
```

## Control Flow

If you need descending `range` you can use `reversed` function:


```Python
for i in reversed(range(2, 11, 2):
    print(i)    # 10, 8, 6, 4, 2

# or just with negative range argument
for i in range(10, 1, -2)
    print(i)    # 10, 8, 6, 4, 2
```
