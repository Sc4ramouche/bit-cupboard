# Introduction

## run C program

1. compile with `gcc -o desired_name source_file.c`
2. run with `./desired_name`
3. if you want to avoid `./` part: add `export PATH=.:$PATH` to profile

## range

In C size depends on machine you are running. It could be 16 or 32 bit for type `int`.

Basic types are:

* `int` – integer;
* `float` – floating point number;
* `char` – character, a single byte;
* `short` – short integer;
* `long` – long integer;
* `double` – double-precision floating point.

## arithmetic coercion

If an arithmetic operator has integer operands, an integer operation is performed. If an arithmetic operator has one floating-point operand and one integer operand, however, the integer will be converted to floating point before the operation is done. But it's still a good practice to write floating point constants. This is true for comparison (`>, <, <= ...)` and assignments as well.

## EOF

Special value equals to `-1`. You can put it into terminal with `Ctrl+D`.

## command line arguments

You can pass arguments to your C program. Conventionally it looks like this:

```C
int main(int argc, char** argv) { /* ... */ }
```

`argc` used to denote number of command line arguments. Note that it would always be >= 1, because name of the program counts as the first argument. Rest of the command line arguments end up split by whitespaces and pushed to the `argv` array.

## arguments

If you want to declare a function which doesn't accept any arguments you can state it implicitly:

```C
int get_line(void)
```

Another reason to do this is to achive compatibility with older C standarts.
