#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>

#include "../../math/extended_gcd.hpp"

int main() {
    long long a, b;
    std::cin >> a >> b;

    long long x, y;
    Ku::ExtendedGCD(a, b, x, y);

    std::cout << x << " " << y << "\n";

    return 0;
}
