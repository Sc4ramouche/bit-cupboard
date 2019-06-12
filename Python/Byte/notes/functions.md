# Functions

Functions are defined using the `def` keyword, followed by an identifier name.

```Python
def say_hello():
    print('hello world')
```

Variables in Python are block scoped.

```Python
x = 50

def func(x):
    print('x is', x)                  # x is 50
    x = 2
    print('Changed local x to, x')    # Changed local x to 2

func(x)
print('x is still', x)                # x is still 50
```

## `global` keyword

If you want to interact with a value defined at the top level of the program, then you can use `global` keyword:

```Python
x = 50

def func():
    global x
    x = 2

func()
print('x is', x)  # x is 2
```

## Default Argument Values

You can specify default argument value with assignment operator followed by the default value:

```Python
def say(message, times=1)
```

## Keyword Arguments

```Python
def func(a, b=5, c=10):
    print('a is {} and b is {} and c is {}'.format(a, b, c))   

func(3, 7)        # a is 3   and b is 7 and c is 10
func(25, c=24)    # a is 25  and b is 5 and c is 24
func(c=50, a=100) # a is 100 and b is 5 and c is 50
```

## The `return` statement

A `return` statement without a value is equivalent to `return None`. `None` is a special type in Python that represents nothingness. 

Every function implicitly contains a `return None` statement at the end unless you've provided your own `return` statement. This could be illustrated by running `print(some_function())` where `some_function` does no use the `return` statement:

```Python
def some_function():
    pass
```

The `pass` statement indicates an empty block os statements.

## DocStrings

DocStrings are an tool that helps to document the program.

```Python
def print_max(x, y):
    '''Prints the maximum of two numbers.
    
    The two values must be integers.'''

    # actual function body could be here

print_max(3, 5)
print(print_max.__doc__)    # prints the DocString
```

The convention followed ofr a docstring is a multi-line string where the first line starts with a capital letter and ends with a dot. Then second blank line followed by any detailed explanation starting from third line.
