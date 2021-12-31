#include "Mwc256XXA64.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>

constexpr bool test() {
    Mwc256XXA64 g(1, 2);
    assert(g() == 14212867858439706905uLL);
    assert(g() == 4805082258640568467uLL);
    assert(g() == 1745200755115809256uLL);
    assert(g() == 7181137736313698539uLL);
    return true;
}
static_assert(test(), "compile-time OK");

void shuffle_example() {
    int cards[52] {};
    Mwc256XXA64 g;
    std::shuffle(cards, cards + 52, g);
    (void) std::uniform_int_distribution<int>(1,6)(g);
    (void) std::uniform_real_distribution<float>(1,6)(g);
}

int main() {
    Mwc256XXA64 g(1, 2);
    std::cout << g() << '\n';
    std::cout << g() << '\n';
    std::cout << g() << '\n';
    std::cout << g() << '\n';

    test();
    shuffle_example();
}
