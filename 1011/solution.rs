use std::io::{self, BufRead};

fn main() {
    let mut fst_input = String::new();
    io::stdin().read_line(&mut fst_input).expect("Non valid input!");
    let testnum: u32 = fst_input.trim().parse().unwrap();

    let mut resultdatum = Vec::new();
    for i in 0..testnum {
        let tempvec: Vec<u32> = io::stdin().lock().lines().next().unwrap().unwrap() 
        .split(' ').map(|s| s.trim())    
        .filter(|s| !s.is_empty())        
        .map(|s| s.parse().unwrap())     
        .collect(); 
        let dist = tempvec[1] - tempvec[0];
        let mut max = 1;
        let mut acc = 0;
        let mut flag = true;
        while (acc*2) < dist {
            if (acc*2)+ max >= dist {
                resultdatum.push(((max-1)*2)+1);
                flag = false;
                break;
            }
            else {
                acc += max;
                max += 1;
            }
        }
        if flag {
            resultdatum.push((max-1)*2);
        }
    }

    for i in resultdatum {
        println!("{}",i);
    }
}