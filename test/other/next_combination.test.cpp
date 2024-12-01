#define PROBLEM "https://yukicoder.me/problems/no/2561"

#include <iostream>
#include <numeric>
#include <vector>

#include "../../other/next_combination.hpp"

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> id(N);
    std::iota(id.begin(), id.end(), 0);

    int ans = 0;
    do {
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < K; i++) {
            s1 = (s1 + A[id[i]]) % 998;
            s2 = (s2 + A[id[i]]) % 998244353;
        }

        if (s2 <= s1) {
            ans = (ans + 1) % 998;
        }
    } while (Ku::NextCombination(id.begin(), id.end(), K));

    std::cout << ans << "\n";

    return 0;
}
