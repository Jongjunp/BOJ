use std::io;
use std::char;

fn main() {
    let mut input_str = String::new();
    io::stdin().read_line(&mut input_str).unwrap();
    let char_list = input_str.trim().to_lowercase().chars().collect::<Vec<char>>();
    let mut alphabet_array = [0;26];
    for i in 0..(char_list.len()) {
        let index = (char_list[i] as u32) - ('a' as u32);
        alphabet_array[index as usize] += 1;
    }
    let mut num_char = 0;
    let mut inc = 0;
    for j in 0..(alphabet_array.len()){
        if num_char < alphabet_array[j]{
            num_char = alphabet_array[j];
            inc = j;
        }
    }
    let mut output = 'A';
    match char::from_u32(('A' as u32) + inc as u32) {
        Some(letter) => output = letter,
        None => println!("Error!")
    }
    let mut rep_count = 0;
    for k in 0..(alphabet_array.len()){
        if num_char == alphabet_array[k]{
            rep_count += 1;
        }
        if rep_count >= 2 {
            output = '?';
            break;
        }
    }
    println!("{}",output);
}