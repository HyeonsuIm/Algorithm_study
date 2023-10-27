use std::io;
use std::cmp;

struct Item{
    weight:usize,
    cost:usize
}

fn main() {
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();
    let numbers : Vec<usize> = str.split_whitespace().map(|x| x.parse().unwrap()).collect();

    let mut items : Vec<Item> = Vec::new();
    items.push(Item{weight:0,cost:0});
    for _ in 0..numbers[0]{
        str = String::new();
        io::stdin().read_line(&mut str).unwrap();
        let item_info : Vec<usize> = str.split_whitespace().map(|x| x.parse().unwrap()).collect();
        items.push(Item{weight:item_info[0], cost:item_info[1]});
    }

    let mut dp = vec![vec![0;numbers[1]+1]; numbers[0]+1];
    for i in 1..(numbers[0]+1){
        for j in 1..(numbers[1]+1){
            if j >= items[i].weight {
                dp[i][j] = cmp::max(dp[i-1][j], dp[i-1][j-items[i].weight]+items[i].cost)
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    println!("{}", dp[numbers[0]][numbers[1]]);
}