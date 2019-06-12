# Basics

## Types

Python uses *objects* as a values.

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
