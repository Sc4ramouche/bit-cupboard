use std::io;

fn main() {
    println!("Guess the number!");
    println!("Please input your guess.");

    // create new, empty string
    let mut guess = String::new();

    // if `use std::io` omitted
    // could use `std::io::stdin`
    io::stdin().read_line(&mut guess)
        .expect("Failed to read line");

    println!("You guessed: {}", guess);
}
