# Week 2: Simple Programs

## Strings

Strings are immutable objects in Python. To demonstrate this concept, you can try to assign a value to the string directly:

```Python
s = 'hello'
s[0] = 'y'    # Error
```

But you're able to do the following, which won't cause error. The reason is that we _redefine_ `s` variable:

```Python
s = 'y' + s[1:len(s)]    # s == 'yello'
```

### Iterate over Strings

Generally we would greate a _range_ based on string length:

```Python
s = 'abcdefg'

for index in range(len(s)):
    if s[index] == 'i' or s[index] == 'u'
        print('There is an i or u')
```

But we can also just grab the characters themselves:

```Python
for char in s:
    if char == 'i' or char == 'u':
        print('There is an i or u')
```

## Bisection search

Has the same spirit as binary search. For example, if we have a problem of finding a square root we can address it with bisection search.

We know that square root of an integer `x` lies somewhere between 1 and `x`. That gives us boundaries. And then we can pick a middle value, which is `(x + 1) / 2.0` as a guess. And if the square of our guess is less than `x`, we throw away everything more than guess.

```Python
x = 25
epsilon = 0.01
low = 1.0
hight = x
ans = (high + low) / 2.0

while abs(ans ** 2 - x) >= epsilon:
    numGuesses += 1
    if ans ** 2 < x:
        low = ans
    else:
        high = ans
    ans = (high + low) / 2.0

print(str(ans) + ' is close to square root of ' str(x))
```
