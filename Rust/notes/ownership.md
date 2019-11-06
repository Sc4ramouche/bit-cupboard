# Ownership

Ownership enables Rust to make memory safety guarantees without needing a garbage collector.

Some languages use garbage collectors, some oblige you to allocate and free memory manually. It's different approach in Rust. In many languages you don't have to think about the stack and the heap very often. But it's important to Rust.

## stack vs heap

Stack follows *first in, last out* principle. It's just like pile of plates. Two things make stack fast: the way it access data (never has to search for it as it's always on top of the stack) and that all data on the stack take up a fixed size.

Heap works different: allocates memory, returns a pointer, which is the address of that location. Because the pointer is a known, fixed size, you can store it on the stack, but when you want the actual data, you have to follow the pointer. Allocating a large amount of space on the heap can take considerable time.

Keeping track of what parts of code are using what data on the heap, minimizing the amount of duplicate data on the heap, and cleaning up unused data on the heap so you don't run out of space are all problems that ownership addresses. With ownership, you won't need to think about the stack and the heap very often, but knowing that managing heap data is why ownership exists can help explain why it works the way it does.

## Ownership Rules

* Each value in Rust has a variable that's called its owner.
* There can only be one owner at a time.
* When the owner goes out of scope, the value will be dropped.

## The `String` Type

There is difference between string literal and `String` type value. String literals are all allocated on stack, while `String` value is allocated on the heap and able to store an amount of text that is unknown to us at compile time.

```Rust
let s1 = "hello";                  // string literal
let s2 = String::from("hello");    // `String` value, can be mutated
```

The double colon (`::`) allows us to namespace this particular `from` function under the `String` type.

`String` values can be mutated:

```Rust
let mut s = String::from("hello");
s.push_str(", world!");    // push_str() appends a literal to a String
```

String literals are fast, as they are known at compile time and text is being hardcoded directly into the final executable.

Classic approach to memory in programmin languages is either garbace collector or manual memory managment (`allocate` & `free`). Rust takes a different path: the memory is automatically returned once the variable that owns it goes out of scope.

There is a natural point at which we can return the memory our `String` needs back to the OS: when `s` goes out of scope. Rust then calls a special function called `drop`. Rust calls `drop` automatically at the closing curly bracket.

That can lead to unexpected behavior. Consider the example:

```Rust
let s1 = String::from("hello");
let s2 = s1;
```

In rust complex data in copied by reference. So pointer to the `hello` string ends up in both `s1` and `s2` values. This is a problem: when `s1` and `s2` go out of scope, they will both try to free the same memory. This is know as a *double free* error and is one of the memory safety bugs.

To ensure memory safety, Rust considers `s1` to no longer be valid and, therefore, Rust doesn't need to free anything when `s1` goes out of scope.

```Rust
let s1 = String::from("hello");
let s2 = s1;
println!("{}, world!", s1);    // won't compile
```

Code above won't compile because Rust prevents you from using the invalidated reference. The concept of copying the pointer, length, and capacity without copying the data probably sounds like making a shallow copy. But because Rust also invalidates the first variable, instead of being called a shallow copy, it's known as a *move*. We would say that `s1` was moved into `s2`.

In addition, there's a design choice that's implied by this: Rust will never automatically create "deep" copies of you data (in C you could copy structs).

If we do want to deeply copy the heap data, we can use a common method `clone`.

```Rust
let s1 = String::from("hello");
let s2 = s1.clone();
```

The semantics for passing a value to a function are similar to those for assigning a value to a variable. Passing a variable to a function will move or copy, ju as assignment does.

```Rust
let s = String::from("hello");
takes_ownership(s):    // s's value moves into the function
                       // and so is no longer valid here

fn takes_ownership(str: String) {
    println!("{}", str);
}    // `drop` is called, `str` memory is freed
```

If we tried to use `s` after the call to `takes_ownership`, Rust would throw a compile-time error.

When a variable that includes data on the heap goes out of scope, the value will be cleaned up by `drop` unless the data has been moved to be owned by another variable (like returned from a function).

What if wwe want to let a function use a value but not take ownership? Anything we pass in also need to be passed back if we want to use it again, in addition to any data resulting from the body of the function that we might want to return as well. It's possible to return multiple values using a tuple:

```Rust
fn main() {
    let s1 = String::from("hello");
    let (s2, len) = calculate_length(s1);
}

fn calculate_length(s: String) -> (String, usize) {
    let length = s.len();

    (s, length)
}
```

But there are much more convenient approach to this problem – *references*.

## References and Borrowing

Issue with return tuples is that we are obliged to return `String` if we want to use it later.

Here is definition of `calculate_length` function that has a refrence to an object as a parameter instead of taking ownership of the value:

```Rust
fn main() {
    let s1 = String::from("hello");
    let len = calculate_length(&s1);
}

fn calculate_length(s: &String) -> usize {
    s.len()
}    // s goes out of scope, but it does not have ownership
     // of what it refer to, so nothing happens
```

The opposite of referencing by using `&` is dereferencing, which is accomplished with the derefernce operator, `*` (similarly to C).

Having references as function parameters called *borrowing*. References are immutable by default just as variables, so we're not allowed to modify something we have a reference to.

### Mutable References

If we want to mutate original string we have to explicitly state it in function definition, variable declaration,  and on the call site:

```Rust
fn main() {
    let mut s = String::from("hello");
    change(&mut s);
}

fn change(str: &mut String) {
    str.push_str(", world");
}
```

Mutable references have one big restriction: you can have only one mutable reference to a particular piece of data in a particular scope. This code will fail:

```Rust
let mut s = String::from("hello");

let r1 = &mut s;
let r2 = &mut s;
```

Idea behind this is to prevent *data races*, which occurs when:

* Two or more pointers access the same data at the same time.
* At least one of the pointers is being used to write to the data.
* There's no mechanism being used to synchronize access to the data.

We also cannot have a mutable reference while we have an immutable one. However, multiple immutable references are okay because no one who is just reading the data has the ability to affect anyone else's reading of the data.
