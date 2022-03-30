use std::io::{self, BufRead};

fn main() {
    let mut list_len = String::new();
    io::stdin().read_line(&mut list_len).unwrap();
    let mut given_list: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())    
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())     
    .collect(); 

    let mut lis_num_list = Vec::new();
    let mut lis_list = Vec::new();
    let mut lds_num_list = Vec::new();
    let mut lds_list = Vec::new();
    for ele in given_list.iter() {
        if lis_list.is_empty() || ele > lis_list[lis_list.len()-1] {
            lis_list.push(ele);
            lis_num_list.push(lis_list.len());
            continue;
        }
        let mut lis_left = 0;
        let mut lis_right = lis_list.len()-1;
        let mut lis_mid = (lis_left+lis_right)/2;
        while lis_right > lis_left {
            if ele <= lis_list[lis_mid] {
                lis_right = lis_mid
            }
            else {
                lis_left = lis_mid + 1
            }
            lis_mid = (lis_left+lis_right)/2;
        }
        lis_list[lis_mid] = ele;
        lis_num_list.push(lis_list.len());
    }
    given_list.reverse();
    for ele in given_list.iter() {
        if lds_list.is_empty() || ele > lds_list[lds_list.len()-1] {
            lds_list.push(ele);
            lds_num_list.push(lds_list.len());
            continue;
        }
        let mut lds_left = 0;
        let mut lds_right = lds_list.len()-1;
        let mut lds_mid = (lds_left+lds_right)/2;
        while lds_right > lds_left {
            if ele <= lds_list[lds_mid] {
                lds_right = lds_mid
            }
            else {
                lds_left = lds_mid + 1
            }
            lds_mid = (lds_left+lds_right)/2;
        }
        lds_list[lds_mid] = ele;
        lds_num_list.push(lds_list.len());
    }
    lds_num_list.reverse();
    let mut max_bitonic_len_list = Vec::new();
    for (lis_len, lds_len) in lis_num_list.iter().zip(&lds_num_list) {
        max_bitonic_len_list.push(lis_len+lds_len-1);
    }
    let answer = *(max_bitonic_len_list.iter().max().unwrap());

    println!("{}", answer);
}