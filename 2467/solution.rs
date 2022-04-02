use std::io::{self, BufRead};

fn main() {
    let mut solution_num = String::new();
    io::stdin().read_line(&mut solution_num).unwrap();
    let solution_vec: Vec<i32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())     
    .collect(); 

    let mut left = 0;
    let mut right = solution_vec.len()-1;
    let mut answer: [i32; 2] = [solution_vec[left],solution_vec[right]];
    let mut min_sum = (solution_vec[left]+solution_vec[right]).abs();
    while right > left {
        let ph_sum = solution_vec[left]+solution_vec[right];
        let ph_sum_abs = ph_sum.abs();
        if ph_sum_abs < min_sum {
            answer = [solution_vec[left],solution_vec[right]];
            min_sum = ph_sum_abs;
        }
        if ph_sum < 0 {
            left += 1;
        }
        else if ph_sum > 0 {
            right -= 1;
        }
        else {
            break;
        }
    }
    println!("{} {}", answer[0], answer[1]);
}