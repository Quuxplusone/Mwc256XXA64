A minimal "Mwc256XXA64" generator, with the C++ `<random>` interface.

Generate 64-bit random integers, speedily, with code small enough to
paste directly into your project.

Based on Rust code by Tom Kaitchuck (copyright 2018; see LICENSE-MIT).
Modifications by Arthur O'Dwyer (copyright 2021; modifications are public domain).
All errors are my own.

* https://github.com/tkaitchuck/Mwc256XXA64/blob/f668e18b/impl/src/gen64.rs

## Test vectors

Initialize `Mwc256XXA64` with the key values `1, 2`, then
generate four 64-bit results; they should be

    14212867858439706905
    4805082258640568467
    1745200755115809256
    7181137736313698539

or, in hex,

    c53e4003'a5dd9919
    42af14db'16cd8093
    183832d7'1e6bd9e8
    63a886b9'502178eb

In this repository, `test-vector.cpp` uses this C++ `Mwc256XXA64.h` implementation;
`test-vector.rs` uses Kaitchuck's Rust code (although it requires a little extra
work, such as adding a `Cargo.toml` that includes `pcg-mwc = "0.2.1"` in the appropriate
spot). Both produce the expected output on my machine.
