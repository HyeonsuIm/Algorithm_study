use std::io;

fn main() {
    let mut numberArray = String::new();
    let mut A: u32;
    let mut B: u32;
    io::stdin().read_line(&mut numberArray).unwrap();
    let numbers: Vec<&str> = numberArray.split_whitespace().collect();
    let number_first = numbers[0].parse::<i32>().unwrap();
    let number_second = numbers[1].parse::<i32>().unwrap();
    let number_third = numbers[2].parse::<i32>().unwrap();
    println!("{}", (number_first+number_second)%number_third);
    println!("{}", ((number_first%number_third)+(number_second%number_third))%number_third);
    println!("{}", (number_first*number_second)%number_third);
    println!("{}", ((number_first%number_third)*(number_second%number_third))%number_third);
}
