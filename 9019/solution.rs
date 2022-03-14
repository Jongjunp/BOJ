use std::io::{self, BufRead};
use std::collections::VecDeque;

fn main() {
    let mut testnum_str = String::new();
    io::stdin().read_line(&mut testnum_str).unwrap();
    let num_test:u32 = testnum_str.trim().parse().unwrap();
    for _i in 0..num_test {
        let ab_vec: Vec<i32> = io::stdin().lock().lines().next().unwrap().unwrap() 
        .split(' ').map(|s| s.trim())    
        .filter(|s| !s.is_empty())        
        .map(|s| s.parse().unwrap())     
        .collect();
        let mut ref_vec = vec![true;10000];
        let src:i32 = ab_vec[0];
        let dest:i32 = ab_vec[1];
        let mut walker:i32 = src;
        let mut visit_nodes = VecDeque::from([(walker as u32, String::from(""))]);
        loop {
            let tuple = visit_nodes.pop_front().unwrap();
            walker = tuple.0 as i32;
            let way = tuple.1;
            let mut d_way = way.clone();
            let mut s_way = way.clone();
            let mut l_way = way.clone();
            let mut r_way = way.clone();
            let d_trans = ((walker*2)%10000) as u32;
            let s_trans = ((walker-1).rem_euclid(10000)) as u32;
            let l_trans = (((walker*10)%10000)+((walker*10)/10000)) as u32;
            let r_trans = ((walker/10)+((walker%10)*1000)) as u32;
            if d_trans == dest as u32{
                d_way.push_str("D");
                println!("{}",d_way);
                break;
            }
            if s_trans == dest as u32 {
                s_way.push_str("S");
                println!("{}",s_way);
                break;
            }
            if l_trans == dest as u32 {
                l_way.push_str("L");
                println!("{}",l_way);
                break;
            }
            if r_trans == dest as u32 {
                r_way.push_str("R");
                println!("{}",r_way);
                break;
            }
            if ref_vec[d_trans as usize] {
                d_way.push_str("D");
                visit_nodes.push_back((d_trans,d_way));
                ref_vec[d_trans as usize] = false;
            }
            if ref_vec[s_trans as usize] {
                s_way.push_str("S");
                visit_nodes.push_back((s_trans,s_way));
                ref_vec[s_trans as usize] = false;
            }
            if ref_vec[l_trans as usize] {
                l_way.push_str("L");
                visit_nodes.push_back((l_trans,l_way));
                ref_vec[l_trans as usize] = false;
            }
            if ref_vec[r_trans as usize] {
                r_way.push_str("R");
                visit_nodes.push_back((r_trans,r_way));
                ref_vec[r_trans as usize] = false;
            }
        }
    }
}