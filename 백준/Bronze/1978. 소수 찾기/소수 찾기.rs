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
        let mut check:bool = true;
        let val = number.parse::<i32>().unwrap();
        if val > 2{
            for i in 2..val-1{
                if val % i == 0 {
                    check=false;
                    break;
                }
            }
        }
        else if val==2{
            check=true
        }
        else{
            check=false
        }

        if check {
            cnt+=1
        }
    }

    println!("{}", cnt);
}
