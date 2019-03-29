use std::io;

fn main() {
    println!("Type Celsius value you would like to convert:");
    let mut celsius = String::new(); 

    io::stdin().read_line(&mut celsius)
        .expect("Failed to read line");

    let celsius: f32 = match celsius.trim().parse() {
        Ok(num) => num,
        Err(_) => 0.0, 
    };

    let fahrenheit = celsius * (9.0 / 5.0) + 32.0;

    println!("Celsius: {}\nFahrenheit: {}", celsius, fahrenheit);
}
