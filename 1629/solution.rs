use std::io::{self, BufRead};

fn main() {
    let inputs: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
        .split(' ').map(|s| s.trim())    
        .filter(|s| !s.is_empty())        
        .map(|s| s.parse().unwrap())     
        .collect();
    let operand_a:u64 = inputs[0] as u64;
    let operand_b:u64 = inputs[1] as u64;
    let operand_c:u64 = inputs[2] as u64;
    let mut binary_form = Vec::new();
    let mut quotient = operand_b;
    let base = 2;
    while quotient != 0 {
        binary_form.push(quotient%base);
        quotient = quotient / base;
    }
    let mut binary_table:Vec<u64> = Vec::new();
    for i in 0..binary_form.len() {
        if i == 0 {
            binary_table.push(operand_a % operand_c);
        }
        else {
            binary_table.push((binary_table[i-1]*binary_table[i-1])%operand_c);
        }
    }
    let mut temp_res:u64 = 1;
    for res in 0..binary_form.len() {
        if binary_form[res]==1 {
            temp_res = (temp_res * binary_table[res]) % operand_c;
        }
    }
    let answer = temp_res % operand_c;
    println!("{}", answer);

}