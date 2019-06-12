# Basics

## Comments

Comments are denoted with `#` symbol in Python.

## Numbers

Mainly of two types: integers and floats. Floats examples: `3.23`, `52.3E-4`. The `E` notation indicates powers of 10.

Python has no separate `long` type. The `int` type can be an integer of any size.

## Strings

Single quotes don't differ in any way from double quotes in Python.

There are multi-line quotes in Python, you specify them with `'''` or `"""`.

Strings are immutable – once you have created a string, you cannot change it.

### `.format` method

To create string with dynamic values you could use `format` method:


```Python
print('{0} and {} were killed by sir Paul'.format('Jimmy', 'Jemimah'))
```

Numbers are optional: could be just `{} and {} were killed ...`.

Python 3.6 introduced named strings (f-strings):

```Python
name =  'Joel'
print(f'{name} is great artist.')
```

`print` function always ends output with `\n` character. To prevent this, you can explicitly state it like `print('your string', end='')`.

If you need to span your string statement across several lines, you can use `\\` (backslash).

```Python
print('first. \
second.')
# is equivalent to 'first. second'
```

If you need to limit processing of escape characters, you specify string as a *raw* one with `r` or `R`:

```Python
print(r'Newlines are indicated by \n')
```

Note: **always** use raw string when dealing with regular expressions.

## Logical and Physical Line

Physical line is basically line of code. A *logical* line is what Python see as a single statement. Python implicitly assumes that each physical line corresponds to a logical line. If you want to specify more than one logical line on a single physical line – use semicolon (`;`):

```Python
i = 5; print(i);
```

However, it's conventional to write code without semicolons in Python.

## Indentation

Official Python recommendation is to use **four** space for indentation.
