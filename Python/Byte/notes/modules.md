# Modules

You can create Python modules with `.py` files.

Another method is to write modules in the native language in which the Python interpreter itself was written. For example, you can write modules in the *C programming language* and when compiled, they can be used from Python code when using standard Python interpreter.

## Standard Library import

```Python
import sys

print('The command line arguments are:')
for i in sys.argv:
    print(i)

print('\nThe PYTHONPATH is', sys.path, '\n')
```

## Byte-compiled .pyc files

The `.pyc` files are useful when you import the module the next time from a different program – it will be much faster since a portion of the processing is already done.

## `from...import`

If you want to import just one piece of the module you can do it like this:

```Python
from math import sqrt
```

## A module's `__name__`

This could help to figure out whether the module is being run standalone or being imported. Every Python module has its `__name__` defined.

```Python
if __name__ == '__main__':
    print('This program is being run by itself')
else:
    print('I am being imported from another module')
```

## Creating Modules

You don't have to explicitly state `export` statements when you create modules. The following example should work.

Exporting module (saved as `mymodule.py`):

```Python
def say_hi():
    print('Hi, this is me speaking.')

__version__ = '3.14'
```

Importing module:

```Python
import mymodule

mymodule.say_hi()
```

You can also use wildcard import (`from mymmodule import *`), but it won't import `__variables__` because it starts with double underscores.

## The `dir` function

The built-in `dir()` function returns the list of names defined by an object. If the object is a module, this list includes function, classes and variables, defined inside that module. It can accept arguments – if the argument is the name of a module, the function return the list of names from that specified module, otherwise it would return the list of names from current module.

This could be handy to observe exported values of the module.

## Packages

Packages are just folders of modules with a special `__init__.py` file that indicates to Python that this folder is special because it contains Python modules.
