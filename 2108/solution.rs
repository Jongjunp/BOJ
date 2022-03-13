use std::io;

fn main() {
    let mut input_str = String::new();
    io::stdin().read_line(&mut input_str).unwrap();
    let input_num:u32 = input_str.trim().parse().unwrap();

    let mut sample_numbers = Vec::new();
    for _i in 0..input_num {
        let mut sample = String::new();
        io::stdin().read_line(&mut sample).unwrap();
        let sample_num:i32 = sample.trim().parse().unwrap();
        sample_numbers.push(sample_num);
    }
    sample_numbers.sort();
    let arith_avg = ((sample_numbers.iter().sum::<i32>() as f32)/(sample_numbers.len() as f32)).round() as i32;
    let center_val = sample_numbers[(input_num/2) as usize];
    let mut flag = 0;
    let mut most_common = 0;
    let mut second_common = 1;
    let mut com_res: i32 = 0;
    let mut cnt = [0;8001];
    for number in sample_numbers.iter() {
        cnt[(number+4000) as usize] += 1;
    }
    for i in 0..8001 {
        if cnt[i]>cnt[most_common] {
            most_common = i;
            flag = 1;
        }
        else if cnt[i]==cnt[most_common] {
            if flag == 1 {
                second_common = i;
                flag = 2;
            }
        }
    }
    if flag == 1 {
        com_res = (most_common as i32) - 4000;
    }
    else {
        com_res = (second_common as i32) - 4000;
    }

    let range = sample_numbers.iter().max().unwrap()-sample_numbers.iter().min().unwrap();
    println!("{}", arith_avg);
    println!("{}", center_val);
    println!("{}", com_res);
    println!("{}", range);
}