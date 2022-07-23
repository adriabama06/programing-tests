fn print_array(arr: Vec<f32>) {
    for (i, v) in arr.iter().enumerate() {
        println!("[{}] = {}", i, v);
    }
}

fn work(i: i32, smallnumber: &f32, diference_by_precission: &f32, arr: &mut Vec<f32>) {
    arr[i as usize] = *smallnumber + (*diference_by_precission * ((i+1) as f32));
}

fn interpolate(x: f32, y: f32, precission: i32) -> Vec<f32> {
    let mut arr: Vec<f32> = vec![0.0; precission as usize];

    let mut smallnumber: f32 = x;
    let mut diference: f32 = y - x;

    if x > y {
        smallnumber = y;
        diference = x - y;
    }

    let diference_by_precission: f32 = diference / (precission as f32);

    for i in 0..precission {
        work(i, &smallnumber, &diference_by_precission, &mut arr);
    }

    return arr;
}

fn main() {
    let arr: Vec<f32> = interpolate(0.0, 100.0, 4);

    print_array(arr);
}
