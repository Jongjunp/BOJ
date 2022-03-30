use std::io::{self, BufRead};

fn bitonic_search(li: Vec<u32>) -> u32 {
    let mut lis_list = Vec::new();
    let mut decreasing_len = 0;
    let mut prev_loc = 0;
    let mut max_bitonic_len = 0;
    for ele in li {
        if lis_list.is_empty() || ele > lis_list[lis_list.len()-1]{
            decreasing_len = 0;
            lis_list.push(ele);
            prev_loc = lis_list.len()-1;
            if max_bitonic_len < decreasing_len + lis_list.len(){
                max_bitonic_len = decreasing_len + lis_list.len();
            }
            continue;
        }

        let mut left = 0;
        let mut right = lis_list.len()-1;
        let mut mid = (left+right)/2;
        while right > left {
            if ele <= lis_list[mid] {
                right = mid
            }
            else {
                left = mid + 1
            }
            mid = (left+right)/2;
        }
        if ele < lis_list[prev_loc]{
            decreasing_len += 1;
        }
        else {
            decreasing_len = 0;
        }
        lis_list[mid] = ele;
        prev_loc = mid;
        if max_bitonic_len < decreasing_len + lis_list.len(){
            max_bitonic_len = decreasing_len + lis_list.len();
        }
    }
    if max_bitonic_len==1 {
        max_bitonic_len = 0;
    }
    let answer = max_bitonic_len;
    answer as u32
}

fn main() {
    let mut list_len = String::new();
    io::stdin().read_line(&mut list_len).unwrap();
    let given_list: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())    
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())     
    .collect(); 
    let bitonic_len = bitonic_search(given_list);
    println!("{}", bitonic_len);
}