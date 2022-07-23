fn readinput() -> String {
    let mut toreturn = String::new();
	std::io::stdin().read_line(&mut toreturn).unwrap();
	return toreturn;
}

fn main() {
    print!("Write your name: ");

    let username = readinput();

	print!("Write your age: ");
    // let my_int = my_string.parse::<i32>().unwrap()
	// if you specify type invariable automatically takes  <T>
	// let my_int: i32 = my_string.parse().unwrap();
    let age: i32  = readinput().parse();
    
	print!("Hello my name is {} and i am {} yo", username, age);
}
