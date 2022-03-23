use std::io::{self, BufRead};
use std::cmp;

//finding lis length for each elements in port_vec
//lis_vec[i] is the value of lis length which is ended with port_vec[i]
fn bitonic_search(port_vec: Vec<u32>) -> u32 {
    let mut lis_vec = Vec::new();
    let mut lds_vec = Vec::new();
    let mut lis_start = 0;
    let mut lds_start = 0;
    for (i,port) in port_vec.iter().enumerate() {
        let mut lis_flag = false;
        let mut lds_flag = false;
        if lis_vec.is_empty() && lds_vec.is_empty() {
            lis_vec.push(port);
            lds_vec.push(port);
            continue;
        }
        if port > lis_vec[lis_vec.len()-1] {
            lis_vec.push(port);
            lis_start = i;
            lis_flag = true;
        }
        if port < lds_vec[lds_vec.len()-1] {
            lds_vec.push(port);
            lds_flag = true;
        }
        if !lis_flag {
            let mut lis_left = 0;
            let mut lis_right = lis_vec.len()-1;
            let mut lis_mid = (lis_left+lis_right) / 2;
            while lis_right > lis_left {
                if port <= lis_vec[lis_mid] {
                    lis_right = lis_mid;
                }
                else {
                    lis_left = lis_mid+1;
                }
                lis_mid = (lis_left+lis_right) / 2;
            }
            lis_vec[lis_mid] = port;
        }
        if !lds_flag {
            let mut lds_left = 0;
            let mut lds_right = lds_vec.len()-1;
            let mut lds_mid = (lds_left+lds_right) / 2;
            while lds_right > lds_left {
                if port >= lds_vec[lds_mid] {
                    lds_right = lds_mid;
                }
                else {
                    lds_left = lds_mid+1;
                }
                lds_mid = (lds_left+lds_right) / 2;
            }
            lds_prev_max = 
            lds_vec[lds_mid] = port;
            if (lds_mid == 0) && (lds_max > port) {
                lds_start = i;
                lds_max = port;
            }
        }
    }
    let lis_len = lis_vec.len() as u32;
    let lds_len = lds_vec.len() as u32;

    //get subvec lds length for lis result
    let mut lis_subvec = Vec::new();
    for lis_subele in &port_vec[(lis_start+1)..] {
        if lis_subvec.is_empty() {
            lis_subvec.push(lis_subele);
            continue;
        }
        if lis_subele < lis_subvec[lis_subvec.len()-1] {
            lis_subvec.push(lis_subele);
            continue;
        }
        let mut left = 0;
        let mut right = lis_subvec.len()-1;
        let mut mid = (left+right) / 2;
        while right > left {
            if lis_subele >= lis_subvec[mid] {
                right = mid;
            }
            else {
                left = mid+1;
            }
            mid = (left+right) / 2;
        }
        lis_subvec[mid] = lis_subele;
    }

    //get subvec lis length for lds result
    let mut lds_subvec = Vec::new();
    for lds_subele in &port_vec[..(lds_start)] {
        if lds_subvec.is_empty() {
            lds_subvec.push(lds_subele);
            continue;
        }
        if lds_subele > lds_subvec[lds_subvec.len()-1] {
            lds_subvec.push(lds_subele);
            continue;
        }
        let mut left = 0;
        let mut right = lds_subvec.len()-1;
        let mut mid = (left+right) / 2;
        while right > left {
            if lds_subele <= lds_subvec[mid] {
                right = mid;
            }
            else {
                left = mid+1;
            }
            mid = (left+right) / 2;
        }
        lds_subvec[mid] = lds_subele;
    }

    let mut lis_sublen = lis_subvec.len() as u32;
    let mut lds_sublen = lds_subvec.len() as u32;
    if (lis_subvec.len() > 0) && (lis_subvec[0] == &port_vec[lis_start]) && (lis_sublen > 0) {
        lis_sublen -= 1;
    }
    if (lds_vec.len() > 0) && (&port_vec[lds_start] == lds_vec[0]) && (lds_sublen > 0) {
        lds_sublen -= 1;
    }
    println!("{} {} {} {}", lis_len, lis_sublen, lds_len, lds_sublen);
    let temp_answer = cmp::max(lis_len+lis_sublen, lds_len+lds_sublen);
    let mut answer = 0;
    if temp_answer > 1 {
        answer = temp_answer;
    }
    answer
}

fn main() {
    let mut port_num = String::new();
    io::stdin().read_line(&mut port_num).unwrap();
    let subj_score: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
    .split(' ').map(|s| s.trim())    
    .filter(|s| !s.is_empty())        
    .map(|s| s.parse().unwrap())     
    .collect(); 
    
    let bitonic_len = bitonic_search(subj_score);

    println!("{}", bitonic_len);

}