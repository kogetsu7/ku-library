#pragma once

#include <array>
#include <cassert>
#include <vector>

namespace Ku {
/**
 * @brief Dynamic Binomial (二項係数)
 */
template <class T> class DynamicBinomial {
  private:
    int n;
    std::vector<T> fact;
    std::vector<T> ifact;

  public:
    DynamicBinomial() : DynamicBinomial{0} {}
    explicit DynamicBinomial(const int _n)
        : n(_n), fact(_n + 1), ifact(_n + 1) {
        assert(0 <= n);

        fact[0] = T{1};
        for (int i = 0; i < n; i++) {
            fact[i + 1] = fact[i] * T{i + 1};
        }

        ifact[n] = T{1} / fact[n];

        for (int i = n; i > 0; i--) {
            ifact[i - 1] = ifact[i] * T{i};
        }
    }

    T p(const int a, const int b) const {
        if (b < 0 || a < b) {
            return T{0};
        }

        assert(0 <= a);
        assert(a <= n);
        assert(a - b <= n);

        return fact[a] * ifact[a - b];
    }

    T c(const int a, const int b) const {
        if (b < 0 || a < b) {
            return T{0};
        }

        assert(b <= n);

        return p(a, b) * ifact[b];
    }

    T h(const int a, const int b) const {
        if (a == 0 && b == 0) {
            return T{1};
        }

        if (a <= 0 || b < 0) {
            return T{0};
        }

        return c(a + b - 1, b);
    }
};
}  // namespace Ku
