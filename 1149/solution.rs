use std::io::{self, BufRead};

fn main() {
    let mut input_str = String::new();
    io::stdin().read_line(&mut input_str).unwrap();
    let num_house:u32 = input_str.trim().parse().unwrap();
    let mut rgb_mat = Vec::new();
    for _i in 0..num_house {
        let inputs: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
        .split(' ').map(|s| s.trim())
        .filter(|s| !s.is_empty())
        .map(|s| s.parse().unwrap())
        .collect();
        rgb_mat.push(inputs.to_vec());
    }
    let mut cost_mat = Vec::new();
    cost_mat.push(rgb_mat[0].clone());
    for j in 1..num_house {
        let cand_vec_0 = vec![cost_mat[(j-1) as usize][1]+rgb_mat[j as usize][0],cost_mat[(j-1) as usize][2]+rgb_mat[j as usize][0]];
        let cand_0 = cand_vec_0.iter().min().unwrap();
        let cand_vec_1 = vec![cost_mat[(j-1) as usize][0]+rgb_mat[j as usize][1],cost_mat[(j-1) as usize][2]+rgb_mat[j as usize][1]];
        let cand_1 = cand_vec_1.iter().min().unwrap();
        let cand_vec_2 = vec![cost_mat[(j-1) as usize][0]+rgb_mat[j as usize][2],cost_mat[(j-1) as usize][1]+rgb_mat[j as usize][2]];
        let cand_2 = cand_vec_2.iter().min().unwrap();
        let opt_ans = vec![*cand_0, *cand_1, *cand_2];
        cost_mat.push(opt_ans);
    }
    let answer = cost_mat[(num_house-1) as usize].iter().min().unwrap();
    println!("{}", *answer);
}