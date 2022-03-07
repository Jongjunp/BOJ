use std::io::{self, BufRead, Write};

fn main() {
    const LIMIT: u32 = 1000001;
    let mut check = [true;LIMIT as usize];
    for i in 2..((LIMIT as f32).sqrt() as u32) {
        if check[i as usize] {
            for j in 1..(LIMIT/i) {
                if ((j+1)*i) != 1000001 {
                    check[((j+1)*i) as usize] = false;
                }
            }
        }
    }
    loop {
        let mut str_input = String::new();
        io::stdin().lock().read_line(&mut str_input).unwrap();
        let num: u32 = str_input.trim().parse().unwrap();
        if num == 0 {
            break;
        }
        let mut passed = false;
        for i in 3..(num/2)+1 {
            let res = num - i;
            if check[i as usize] & check[res as usize] {
                let stdout = io::stdout();
                let mut out = io::BufWriter::new(stdout.lock());
                writeln!(out, "{} = {} + {}", num, i, res).unwrap();
                passed = true;
                break;
            }
        }
        if !passed {
            println!("Goldbach's conjecture is wrong.");
        }
    };
}