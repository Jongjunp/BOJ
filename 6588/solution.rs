use std::io;

fn isprime(num: u32) -> bool {
    let mut result: bool = true;
    if num==3 {
        return result;
    }
    else {
        for i in 2..((num as f32).sqrt().floor() as u32)+1 {
            if num%i==0 {
                result = false;
                break;
            }
        }
        return result;
    }
}

fn main() {
    let mut temp_vec = Vec::new();
    let input_vec = loop {
        let mut str_input = String::new();
        io::stdin().read_line(&mut str_input).unwrap();
        let num: u32 = str_input.trim().parse().unwrap();
        if num == 0 {
            break temp_vec;
        }
        else {
            temp_vec.push(num);
        }
    };
    for even in input_vec {
        let mut passed = false;
        for i in 3..(even/2)+1 {
            let res = even - i;
            if isprime(i) & isprime(res){
                println!("{} = {} + {}", even, i, res);
                passed = true;
                break;
            }
        }
        if !passed {
            println!("Goldbach's conjecture is wrong.");
        }
    }
}