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

        let src:i32 = ab_vec[0];
        let dest:i32 = ab_vec[1];
        let mut walker:i32 = src;
        let mut visit_nodes = VecDeque::new();
        let mut way_nodes = VecDeque::from([String::from("")]);
        while walker != dest {
            let way = way_nodes.pop_front().unwrap();
            let mut d_way = way.clone();
            let mut s_way = way.clone();
            let mut l_way = way.clone();
            let mut r_way = way.clone();
            let d_trans = (walker*2)%10000;
            let s_trans = (walker-1)%10000;
            let l_trans = ((walker*10)%10000)+((walker*10)/10000);
            let r_trans = (walker/10)+((walker%10)*1000);
            if !(visit_nodes.contains(&d_trans)) {
                visit_nodes.push_back(d_trans);
                d_way.push_str("D");
                way_nodes.push_back(d_way);
            }
            if !(visit_nodes.contains(&s_trans)) {
                visit_nodes.push_back(s_trans);
                s_way.push_str("S");
                way_nodes.push_back(s_way);
            }
            if !(visit_nodes.contains(&l_trans)) {
                visit_nodes.push_back(l_trans);
                l_way.push_str("L");
                way_nodes.push_back(l_way);
            }
            if !(visit_nodes.contains(&r_trans)) {
                visit_nodes.push_back(r_trans);
                r_way.push_str("R");
                way_nodes.push_back(r_way);
            }
            walker = visit_nodes.pop_front().unwrap();
        }
        let answer = way_nodes.pop_front().unwrap();
        println!("{}", answer);
        
    }
}