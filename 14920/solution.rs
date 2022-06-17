use std::io::{self};

fn main() {
    let mut input_str = String::new();
    io::stdin().read_line(&mut input_str).unwrap();
    let mut num:u32 = input_str.trim().parse().unwrap();
    let mut cnt = 1;
    while num != 1 {
        if num%2==0 {
            num = num/2;
        }
        else {
            num = (3*num)+1;
        }
        cnt += 1;
    }
    println!("{}",cnt);
}