#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../math/extended_gcd.hpp"

#include <iostream>

int main() {
    long long a, b;
    std::cin >> a >> b;

    long long x, y;
    ku::ExtendedGCD(a, b, x, y);

    std::cout << x << " " << y << "\n";

    return 0;
}
