#pragma once

#include <array>
#include <cassert>
#include <vector>

namespace Ku {
/**
 * @brief Binomial (二項係数)
 */
template <class T> class Binomial {
  private:
    size_t n;
    std::vector<T> fact;
    std::vector<T> ifact;

  public:
    Binomial() : Binomial(0U) {}
    explicit Binomial(const size_t _n) : n(_n), fact(_n + 1), ifact(_n + 1) {
        fact[0] = T(1);
        for (size_t i = 0; i < n; i++) {
            fact[i + 1] = fact[i] * T{i + 1};
        }

        ifact[n] = T(1) / fact[n];

        for (size_t i = n; i > 0; i--) {
            ifact[i - 1] = ifact[i] * T{i};
        }
    }

    T p(const int a, const int b) const {
        if (b < 0 || a < b) {
            return T(0);
        }

        assert(0 <= a);
        assert(a <= static_cast<int>(n));
        assert(a - b <= static_cast<int>(n));

        return fact[a] * ifact[a - b];
    }

    T c(const int a, const int b) const {
        if (b < 0 || a < b) {
            return T(0);
        }

        assert(b <= static_cast<int>(n));

        return p(a, b) * ifact[b];
    }

    T h(const int a, const int b) const {
        if (a == 0 && b == 0) {
            return T(1);
        }

        if (a <= 0 || b < 0) {
            return T(0);
        }

        return c(a + b - 1, b);
    }
};
}  // namespace Ku
