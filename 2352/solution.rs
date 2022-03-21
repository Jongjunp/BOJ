use std::io::{self, BufRead};

//finding lis length for each elements in port_vec
//lis_vec[i] is the value of lis length which is ended with port_vec[i]
fn lis_search(port_vec: Vec<u32>) -> u32 {
    let mut lis_vec = Vec::new();
    let mut lis_len:u32 = 0;
    for port in port_vec {
        if (lis_vec.is_empty()) || (port > lis_vec[lis_vec.len()-1]) {
            lis_vec.push(port);
            lis_len = lis_vec.len() as u32;
            continue;
        }
        let mut left = 0;
        let mut right = lis_vec.len()-1;
        let mut mid = (left+right) / 2;
        while right > left {
            if port <= lis_vec[mid] {
                right = mid;
            }
            else {
                left = mid+1;
            }
            mid = (left+right) / 2;
        }
        lis_vec[mid] = port;
        if lis_len < (right as u32) {
            lis_len = right as u32;
        }
    }
    lis_len
}

fn main() {
    let mut port_num = String::new();
    io::stdin().read_line(&mut port_num).unwrap();
    let subj_score: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())    
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())     
    .collect(); 
    
    let lis_len = lis_search(subj_score);

    println!("{}", lis_len);

}