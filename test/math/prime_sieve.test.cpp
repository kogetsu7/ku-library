#define PROBLEM "https://yukicoder.me/problems/no/106"

#include <iostream>

#include "../../math/prime_sieve.hpp"

int main() {
    int N, K;
    std::cin >> N >> K;

    const Ku::PrimeSieve ps(N);

    int ans = 0;
    for (int i = 2; i <= N; i++) {
        auto pf = ps.prime_factors(i);

        if (K <= static_cast<int>(pf.size())) {
            ans++;
        }
    }

    std::cout << ans << "\n";

    return 0;
}
