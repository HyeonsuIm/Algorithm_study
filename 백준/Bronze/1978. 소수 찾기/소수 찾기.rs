use std::io;

fn main() {
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();
    
    str = String::new();
    io::stdin().read_line(&mut str).unwrap();
    let numbers:Vec<&str> = str.split_whitespace().collect();
    let mut cnt = 0;
    for number in numbers
    {
        let mut match_cnt = 0;
        let val = number.parse::<i32>().unwrap();
        for i in 1..val+1{
            if val % i == 0 {
                match_cnt+=1;
            }
        }

        if match_cnt == 2 {
            cnt+=1
        }
    }

    println!("{}", cnt);
}