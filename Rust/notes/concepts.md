# variables and mutability

By default variables are immutable. You declare them with `let` keyword. If you need mutable variable add `mut`:

```Rust
let mut x = 5;
```

When you declare `const` value you always have to annotate type of the value.

## shadowing

```Rust
let x = 5;
let x = x + 1;
let x + x * 2;
```

This program first binds `x` to a value of `5`. Then it shadows `x` by repeating `let x =`. Running this will output value `12`.

Shadowing is different than marking a variable as `mut`, because we'll get a compile-time error if we accidentally try to reassign to this variable without using `let` keyword. By using `let`, we can perform a few transformations on a value but have the variable immutable after thos transformations have been completed.

The other difference – we're effectively creating a new variable when we use the `let` keyword again, we can change the type of the value but reuse the same name:

```Rust
let spaces = "   ";
let spaces = spaces.len();
```

In example above first `spaces` variable is a string type and the second (brand new) variable is a number type. However, if we try to use `mut` for this, we'll get a compile-time error.

# data types

Every value in Rust is of a certain data type. There are two data types subsets: scalar and compound.

Rust is statically typed language, but compiler can usually infer what type we want to use based on the value and the way it is used.

## scalar types

Represents a single values. Four primary scalar types: integers, floating-point numbers, Booleans and characters.

### integer types

| length  | signed | unsigned |
|---------|--------|----------|
| 8-bit   | i8     | u8       |
| 16-bit  | i16    | u16      |
| 32-bit  | i32    | u32      |
| 64-bit  | i64    | u64      |
| 128-bit | i128   | u128     |
| arch    | isize  | usize    |

`isize` and `usize` types depend on the kind of computer your program is running on: 64 bits if you're on a 64-bit architecture and 32 bit if you're on a 32-bit architecture.

You can write number with type suffix, like `57u8`. You can also use `_` as visual separator, such as `1_000` or `0b1111_0000`.

Default integer type is `i32`. This type is generally the fastest, even on 64-bit systems. The primary situation in which you'd use `isize` or `usize` is when indexing some sort of collection.

### floating point types

There are two floating point types: `f32` and `f64`, latter is being default.

### character type

```Rust
let c = 'z';
let z = 'ℤ';
let heart_eyed_cat = '😻';
```

`char` literal is specified with single quotes, as opposed to string literals, which use double quotes. Rust's `char` type represented a Unicode Scalar Value, which can represent a lot more than just ASCII.

## compound types

*Compound types* can group multiple values into one types. Rust has two primitive compound types: tuples and arrays.

### the tuple type

A tuple is a general way of grouping together some number of other values with a variety of types into one compound type. Tuples have a fixed length: once declared, they cannot grow or shrink in size.

```Rust
let tup: (i32, f64, u8) = (500, 6.4, 1);
```

The variable `tup` binds to the entire tuple, because a tuple is considered a single compound element (type annotation is optional). To get the individual values out of a tuple, we can use pattern matching to destructure a tuple value, like this:

```Rust
let tup = (500, 6.4, 1);
let (x, y, z) = tup;
```

Another way we can access a tuple element directly by using a period (`.`) followed by the index of the value we want to access.

```Rust
let x: (i32, f64, u8) = (500, 6.4, 1);
let five_hundred = x.0;    // 500
let one = x.2;             // 1
```

### the array type

Every element of an array must have the same type. Arrays in rust have a fixed length, like tuples (similar to C). Arrays are useful when you want your data allocated on the stack rather than the heap or when you want to ensure you always have a fixed number of elements.

An array isn't as flexible as the vector type – similar collection type provided by the standard library that is allowed to grow or shrink in size. If unsure whether to use an array or a vector – probably a vector. 

```Rust
// declare i32 array of length 5
let a: [i32, 5] = [1, 2, 3, 4, 5];
```

# functions

In Rust it doesn't matter where you do declare a function. But in every function signature you must declare the type of each parameter.

*Statements* are instructions that perform some action and do not return a value:

```Rust
let y = 6;
```

This is different from what happens in other languages, such as C and Ruby, where assignment returns the value of the assignment. You could write `x = y = 6` and have both `x` and `y` have the value `6`. That is not the case in Rust.

*Exppressions* evaluate to a resulting value.

In Rust blocks can be used as expression. Blocks of code actually evaluate to the last expression in them:

```Rust
// y will hold 4
let y = {
    let x = 3;
    x + 1
};
```

Note the `x + 1` without a semicolon at the end. Expressions do not include ending semicolons. If you add a semicolon to the end of an expression, you turn it into a statement, which will then not return a value. 

## functions with return values

We do declare return value type after an arrow (`->`). In Rust, the return value of the function is synonymous with the value of the final expression in the block of the body of function. You can return early from a function by using the `return` keyword and specifying a value, but most functions return the last expression implicitly.

```Rust
fn five() -> i32 {
    5
}
```

Note how we don't place semicolon because it's an expression whose value we want to return.

If we place a semicolon, we'll get an error: "mismatched types". The function definition says it will return an `i32`, but statements don't evaluate to a value, which is expressed by `()`, the empty tuple.Therefore, nothing is returned, which contradicts the function definition and results in an error.

# control flow

Condition in `if` statement *must* be a `bool`. Rust won't automatically try to convert non-Boolean types to a Boolean.

In Rust `if` is an expression, so we can use it on the right side of a `let` statement:

```Rust
let condition = true;
let number = if condition {
    5
} else {
        6
};
```

## loops

Rust has three kinds of loops: `loop`, `while`, and `for`.

The `loop` keyword tells Rust to execute a block of code over and over again forever or until you explicitly tell it to stop.

```Rust
loop {
    println!("again!");
}
```

One of the uses of a `loop` is to retry an oparation you know can fail, such as checking if a thread completed its job. However, you might need to pass the result of that operation to the rest of your code. If you add it to the `break` expression you use to stop the loop, it will be returned by the broken loop:

```Rust
let result = loop {
    counter += 1;

    if counter == 10 {
        break counter * 2;
    }
}
```

`while` loop is just a pattern that substitutes construction of `loop` with `if`, `else`, and `break` in it – you check condition inside `while`, while condition is true, the code runs; otherwise, it exits the loop:

```Rust
while number != 0 {
    println!("{}!", number);
    number = number - 1;
}
```

`for` loop is a more concise alternative, which is great for executing some code for each item in a collection:

```Rust
let a = [10, 20, 30, 40, 50];
for element in a.iter() {
    println!("the value is: {}", element);
}
```

Using `for` loop in Rust increases the safety of the code and eliminates the chance of bugs that might result from going beyond the end of the array or not going far enough and missing some items.

`for` loop is also suitable for running some code a certain number of times, thanks to `Range` type provided by the standard library that generates all numbers in sequence starting from one number and ending before another:

```Rust
for number in (1..4).rev() {
    println!("{}!", number);
}
```
