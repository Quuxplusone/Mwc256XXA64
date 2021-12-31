use pcg_mwc::Mwc256XXA64;

fn main() {
    let mut mwc = Mwc256XXA64::new(1, 2);
    for i in 1..10 {
        println!("{}", mwc.next_u64());
    }
}
