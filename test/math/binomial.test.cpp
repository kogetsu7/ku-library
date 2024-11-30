#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <iostream>
#include <algorithm>

#include <atcoder/modint>

#include "../../math/binomial.hpp"

int main() {
    int T, M;
    std::cin >> T >> M;

    atcoder::modint::set_mod(M);

    Ku::Binomial<atcoder::modint> bin(std::min(M - 1, 10000000));

    for (; T--;) {
        int n, k;
        std::cin >> n >> k;

        std::cout << bin.c(n, k).val() << "\n";
    }

    return 0;
}
