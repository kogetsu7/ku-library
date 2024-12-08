#define PROBLEM "https://yukicoder.me/problems/no/106"

#include "../../math/prime_sieve.hpp"

#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    ku::PrimeSieve ps(N);

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
