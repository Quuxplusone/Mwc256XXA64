#pragma once

// The "pcg-mwc 0.2.1 (MWC X A 256/64 variant)" generator.
// C++ port by Arthur O'Dwyer (2021).
// Based on the Rust version by Tom Kaitchuck (2018),
// https://github.com/tkaitchuck/Mwc256XXA64/blob/f668e18b/impl/src/gen64.rs

// Copyright (c) 2018 Tom Kaitchuck
// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// https://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or https://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.
// Modifications by Arthur O'Dwyer, 2021, under the same license.

static_assert(sizeof(long long) == 8, "64-bit machines only");

struct Mwc256XXA64 {
    using u64 = unsigned long long;
    using u128 = __uint128_t;

    u64 x1_;
    u64 x2_;
    u64 x3_ = 0xcafef00d'd15ea5e5;
    u64 c_ = 0x14057b7e'f767814f;

    using result_type = u64;
    static constexpr u64 min() { return 0; }
    static constexpr u64 max() { return u64(-1); }

    constexpr explicit Mwc256XXA64() : Mwc256XXA64(1, 2) {}
    constexpr explicit Mwc256XXA64(u64 k1) : Mwc256XXA64(k1, 2) {}
    constexpr explicit Mwc256XXA64(u64 k1, u64 k2) : x1_(k1), x2_(k2) {
        // Advance 6 steps to fully mix the keys.
        for (int i = 0; i < 6; ++i) {
            (*this)();
        }
    }

     constexpr u64 operator()() {
        u128 hilo = x3_ * u128(0xfeb34465'7c0af413);
        u64 hi = hilo >> 64;
        u64 result = (x3_ ^ x2_) + (x1_ ^ hi);
        u128 x1b = u64(hilo) + u128(c_);
        x3_ = x2_;
        x2_ = x1_;
        x1_ = x1b;
        c_ = hi + (x1b >> 64);
        return result;
    }
};
