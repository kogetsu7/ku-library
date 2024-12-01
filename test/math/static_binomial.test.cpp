#define PROBLEM "https://yukicoder.me/problems/no/1520"

#include <iostream>

#include "../../math/static_binomial.hpp"
#include "../../math/static_mod_int.hpp"

using ModInt = Ku::StaticModInt<1000000007U>;
constexpr Ku::StaticBinomial<ModInt, 400000U> bin;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int h, w;
        std::cin >> h >> w;

        if (h == 1 || w == 1) {
            std::cout << 0 << "\n";
            continue;
        }

        ModInt ans{ModInt{2ULL * (h + w - 3)} * bin.c(h + w - 4, h - 2)};
        std::cout << ans.val() << "\n";
    }

    return 0;
}
