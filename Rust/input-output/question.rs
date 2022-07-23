use std::io;

fn main() {
    println!("What is your name?");

    let mut name = String::new();
    io::stdin().read_line(&mut name).expect("Failed to read line");
    name = name.trim().to_string();


    println!("What is your age?");
    
    let mut age = String::new();
    io::stdin().read_line(&mut age).expect("Failed to read line");
    age = age.trim().to_string();
    
    
    println!("Hello {} you are {} years old", name, age);
}