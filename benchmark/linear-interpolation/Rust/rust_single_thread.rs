use std::fs::File;
use std::io::prelude::*;

fn save(arr: Vec<f32>) {
    let mut f = File::create("resultRust.txt").unwrap();

    let cuantity: i32 = 1000000;

	let limited_selection: i32 = arr.len() as i32 / cuantity;

    for i in 0..limited_selection {
        writeln!(&mut f, "{} {}", i * limited_selection, arr[(i * limited_selection) as usize]).unwrap();
    }
}

fn work(start_index: i32, end_index: i32, smallnumber: &f32, diference_by_precission: &f32, arr: &mut Vec<f32>) {
    for i in start_index..end_index {
        arr[i as usize] = *smallnumber + (*diference_by_precission * ((i+1) as f32));
    }
}

fn interpolate(x: f32, y: f32, precission: i32) -> Vec<f32> {
    let mut arr: Vec<f32> = vec![0.0; precission as usize];

    let mut smallnumber: f32 = x;
    let mut diference: f32 = y - x;

    if x > y {
        smallnumber = y;
        diference = x - y;
    }

    let diference_by_precission: f32 = diference / ((precission+1) as f32);

    work(0, precission, &smallnumber, &diference_by_precission, &mut arr);

    return arr;
}

fn main() {
    let arr: Vec<f32> = interpolate(0.0, 1000.0, 450000000);

    save(arr);
}
