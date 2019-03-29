use std::io;

fn main() {
    println!("Enter element number:");

    let mut n = String::new();
    io::stdin().read_line(&mut n)
        .expect("Failed to read line");

    let n: i32 = match n.trim().parse() {
        Ok(num) => num,
        Err(_) => 0,
    };

    let result = fibonacci(n);
    println!("{} is the {} element in Fibonacci sequence", result, n);
}

fn fibonacci(n: i32) -> i32 {
    if n == 1 || n == 0 {
        return n;
    } else {
        return fibonacci(n - 2) + fibonacci(n - 1);
    }
}
