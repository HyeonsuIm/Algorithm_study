use std::io;

fn main() {
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();
    let numbers:Vec<&str> = str.split_whitespace().collect();
    
    let e = numbers[0].parse::<i32>().unwrap();
    let s = numbers[1].parse::<i32>().unwrap();
    let m = numbers[2].parse::<i32>().unwrap();
    let mut result = 1;
    loop{
        if (result-e) % 15 == 0 && (result-s) % 28 == 0 && (result-m) % 19 == 0 {
            break;
        }
        else{
            result += 1;
        }
    }

    println!("{}",result);
}