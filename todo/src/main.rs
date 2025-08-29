use std::env;

static BUFFER: String = String::new();

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        println!("invalid input");
    }
}

fn read_file() {
    BUFFER = String::new();
}

fn write_file() {}

fn display_buffer() {}
