fn generator_cal(num: &u32, array: &mut [bool;10001]){
    let mut remains = Vec::new();
    let mut quotient = *num;
    while quotient!=0 {
        remains.push(quotient%10);
        quotient = quotient/10;
    }
    let mut sum_remains = 0;
    for remain in remains {
        sum_remains += remain;
    }
    let result = num + sum_remains;
    if result <= 10000 {
        array[result as usize] = false;
    }
}

fn main() {
    let mut self_num: [bool;10001] = [true;10001];
    for num in 0..10001 {
        if num==0 {
            self_num[num] = false;
        }
        else {
            generator_cal(&(num as u32), &mut self_num);
        }
    }
    let mut idx = 0;
    for is_self_num in self_num.iter() {
        if *is_self_num {
            println!("{}",idx);
        }
        idx += 1;
    }
}