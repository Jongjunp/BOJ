use std::io;

fn main() {
    let mut num_input = String::new();
    io::stdin().read_line(&mut num_input).unwrap();
    let mut num_str = String::new();
    io::stdin().read_line(&mut num_str).unwrap();
    let num_vec = num_str.trim();
    let mut answer = 0;
    for n in num_vec.chars() {
        answer += (n as u32) - 48;
    }
    println!("{}",answer);
}