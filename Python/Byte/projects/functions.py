# simple function
def say_hello():
    print('hello world')

say_hello()

# global keyword

x = 50

def func():
    global x
    x = 2

func()

print('x is', x)

# keyword arguments

def key_args(a, b=5, c=10):
    print('a is {} and b is {} and c is {}'.format(a, b, c))

key_args(3, 7)
key_args(25, c=24)
key_args(c=50, a=100)

def docstring_func():
    '''This is test function

    It doesn't really do anything'''

help(docstring_func)
