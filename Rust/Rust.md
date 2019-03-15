# Rust

Following notes are mostly inspired by [*The Rust Programming Language* book](https://doc.rust-lang.org/book/index.html)

## compile

You compile rust sources with `rustc filename.rs`. Similar to `gcc` or `clang`.

## anatomy

Execution of rust program starts (like in C) from executing `main` function.

```Rust
fn main() {
    /* example of main function declaration */
}
```

Note that Rust style is to indent with four spaces, not a tab.

`println!` calls a Rust macro. Normal function would be `println`. More details later.

## cargo tool

Cargo is Rust's build system and package manager. To create new project run `carg new project_name`. This would create new directory called `project_name`. It contains `Cargo.toml` file and `src` directory with `main.rs` inside.

### .toml file

TOML (Tom's Obvious, Minimal Language) is Cargo's configuration format.

`[package]` is a section heading with package configuration.

`[dependencies]` is the list of project dependencies. In Rust, packages of code are referred to as *crates*.

You build you Cargo project with `cargo build` command. It creates `Cargo.lock` file that keeps track of the exact version of dependencies in the project.

Instead of `cargo build` you can execute `cargo run` to compile and run in one command. There is `cargo check`– quickly checks code to make sure it compiles but doesn't produce an executable. 

### building for release

You can run `cargo build --release` to compile your project with optimizations. This command creates an executable in `target/release` instead of `target/debug`.

## values & variables

In Rust, variables are immutable by default. Use `mut` before the variable to make it mutable:

```Rust
let foo = 5;      // immutable
let mut bar = 5;  // mutable
```

## String

`String::new` retuns a new instance of `String` – type provided by the standard library that is a growable, UTF-8 encoded bit of text.

The `::` syntax indicates that `new` is an associated function of the `String` type. An associated function is implemented on a type, rather than on a particular instance of a `String`. Some languages call this a *static method*.

