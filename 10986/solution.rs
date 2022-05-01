use std::io::{self, BufRead};
fn main() {
    let info: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())    
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())     
    .collect();
    let m = info[1];
    let seq: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())    
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())
    .collect(); 
    let mut ans : [i64;1000] = [0;1000];
    let mut sum = 0;
    for ele in seq.iter() {
        sum += ele;
        sum %= m;
        ans[sum as usize] += 1;
    }
    let mut answer = ans[0];
    for num in ans {
        answer += (num*(num-1))/2;
    }
    println!("{}",answer);
}