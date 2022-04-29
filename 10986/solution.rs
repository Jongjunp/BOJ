use std::io::{self, BufRead};
fn main() {
    let mut N_M: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())    
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())     
    .collect();
    let mut M = N_M[1];
    let mut seq: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())    
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())     
    .collect(); 
    let mut pointer1 = 0;
    let mut pointer2 = 0;
    let mut sum = seq[pointer1];
    let mut cnt = 0;
    while (pointer1!=seq.len() && pointer2!=seq.len()) {
        if (sum%M==0) {
            cnt++;
        }
        else {

        }
    }

}