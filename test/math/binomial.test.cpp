#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../math/binomial.hpp"

#include <algorithm>
#include <iostream>

#include <atcoder/modint>

int main() {
    int T, M;
    std::cin >> T >> M;

    atcoder::modint::set_mod(M);

    ku::Binomial<atcoder::modint> bin(std::min(M - 1, 10000000));

    while (T--) {
        int n, k;
        std::cin >> n >> k;

        std::cout << bin.c(n, k).val() << "\n";
    }

    return 0;
}
