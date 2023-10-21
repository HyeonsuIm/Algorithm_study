use std::io;

fn check_sum_cnt(num:i32) -> i32 {
    if num < 1 {
        return 0;
    }

    let mut cnt = 0;
    for i in 1..4 {
        if i == num{
            cnt+=1;
        }
        else
        {
            cnt += check_sum_cnt(num-i);
        }
    }
    cnt
}

fn main() {
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let cnt = str.trim().parse::<i32>().unwrap();
    for _ in 0..cnt{
        str = "".to_string();
        io::stdin().read_line(&mut str).unwrap();
        let val = str.trim().parse::<i32>().unwrap();
        println!("{}", check_sum_cnt(val))
    }
}
