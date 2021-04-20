use std::io::{stdout, BufWriter};

fn main() {
    println!("Hello, world!");
}

fn other() {
    let stdout = stdout();
    let message = String::from("Hello fellow Rustanceans!");
    let width = message.chars().count();

    let mut writer = BufWriter::new(stdout.lock());
}