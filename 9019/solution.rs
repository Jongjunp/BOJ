use std::io::{self, BufRead};
use std::collections::LinkedList;

fn main() {
    let mut testnum_str = String::new();
    io::stdin().read_line(&mut testnum_str).unwrap();
    let num_test:u32 = testnum_str.trim().parse().unwrap();
    for _i in 0..num_test {
        let ab_vec: Vec<i32> = io::stdin().lock().lines().next().unwrap().unwrap()
        .split(' ').map(|s| s.trim())     
        .map(|s| s.parse().unwrap())     
        .collect();
        let mut ref_vec = [true;10000];
        ref_vec[ab_vec[0] as usize] = false;
        let dest:u32 = ab_vec[1] as u32;
        let mut visit_nodes = LinkedList::from([(ab_vec[0] as u32, String::from(""))]);
        loop {
            let tuple = visit_nodes.pop_front().unwrap();
            let walker = tuple.0 as i32;
            let mut d_way = tuple.1.clone();
            let mut s_way = tuple.1.clone();
            let mut l_way = tuple.1.clone();
            let mut r_way = tuple.1.clone();
            let d_trans = ((walker*2)%10000) as u32;
            let s_trans = ((walker-1).rem_euclid(10000)) as u32;
            let l_trans = (((walker*10)%10000)+((walker*10)/10000)) as u32;
            let r_trans = ((walker/10)+((walker%10)*1000)) as u32;
            if d_trans == dest {
                d_way.push_str("D");
                println!("{}",d_way);
                break;
            }
            if s_trans == dest {
                s_way.push_str("S");
                println!("{}",s_way);
                break;
            }
            if l_trans == dest {
                l_way.push_str("L");
                println!("{}",l_way);
                break;
            }
            if r_trans == dest {
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