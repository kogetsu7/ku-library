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
    unsigned n;
    std::vector<T> fact;
    std::vector<T> ifact;

  public:
    DynamicBinomial() : DynamicBinomial{0U} {}
    explicit DynamicBinomial(const unsigned _n)
        : n(_n), fact(_n + 1), ifact(_n + 1) {
        fact[0] = T{1};
        for (unsigned i = 0; i < n; i++) {
            fact[i + 1] = fact[i] * T{i + 1};
        }

        ifact[n] = T{1U} / fact[n];

        for (unsigned i = n; i > 0; i--) {
            ifact[i - 1] = ifact[i] * T{i};
        }
    }

    T p(const int a, const int b) const {
        if (b < 0 || a < b) {
            return T{0U};
        }

        assert(0 <= a);
        assert(a <= static_cast<int>(n));
        assert(a - b <= static_cast<int>(n));

        return fact[a] * ifact[a - b];
    }

    T c(const int a, const int b) const {
        if (b < 0 || a < b) {
            return T{0U};
        }

        assert(b <= static_cast<int>(n));

        return p(a, b) * ifact[b];
    }

    T h(const int a, const int b) const {
        if (a == 0 && b == 0) {
            return T{1U};
        }

        if (a <= 0 || b < 0) {
            return T{0U};
        }

        return c(a + b - 1, b);
    }
};
}  // namespace Ku
