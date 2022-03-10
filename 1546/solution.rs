use std::io::{self,BufRead};

fn main() {
    let mut input_str = String::new();
    io::stdin().read_line(&mut input_str).unwrap();
    let _num_subj:u32 = input_str.trim().parse().unwrap();
    
    let subj_score: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
        .split(' ').map(|s| s.trim())    
        .filter(|s| !s.is_empty())        
        .map(|s| s.parse().unwrap())     
        .collect(); 
    let max_score = subj_score.iter().max().unwrap();
    let temp_sum: u32 = subj_score.iter().sum();
    let ori_avg = (temp_sum as f32)/(subj_score.len() as f32);
    let modif_avg: f32 = (ori_avg/(*max_score as f32))*100.0;
    println!("{}", modif_avg);
}