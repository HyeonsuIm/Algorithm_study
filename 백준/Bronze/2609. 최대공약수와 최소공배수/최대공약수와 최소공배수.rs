use std::io;
use std::cmp;

fn gcd(num1:i32, num2:i32) -> i32 {
    let mut c = num1 % num2;
    let mut val1 = num1;
    let mut val2 = num2;
    while c != 0 {
        val1 = val2;
        val2 = c;
        c = val1 % val2;
    }
    val2
}

fn lcm(num1:i32, num2:i32) -> i32 {
    (num1 * num2) / gcd(num1,num2)
}

fn main() {
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let numbers:Vec<&str> = str.split_whitespace().collect();
    println!("{}", gcd(numbers[0].parse::<i32>().unwrap(), numbers[1].parse::<i32>().unwrap()));
    println!("{}", lcm(numbers[0].parse::<i32>().unwrap(), numbers[1].parse::<i32>().unwrap()));
}