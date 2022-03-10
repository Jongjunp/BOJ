use std::io;

fn main() {
    let mut input_str = String::new();
    io::stdin().read_line(&mut input_str).unwrap();
    let words = input_str.trim().split(' ');
    let mut count = 0;
    for _word in words {
        if _word != "" {
            count += 1;
        }
    }
    println!("{}", count);
}