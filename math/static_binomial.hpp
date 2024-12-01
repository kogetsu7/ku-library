#pragma once

#include <array>
#include <cassert>
#include <vector>

namespace Ku {
/**
 * @brief Static Binomial (二項係数, constexpr)
 */
template <class T, size_t N> class StaticBinomial {
  private:
    std::array<T, N + 1> fact;
    std::array<T, N + 1> ifact;

  public:
    constexpr StaticBinomial() : fact{}, ifact{} {
        fact[0] = T{1};
        for (size_t i = 0; i < N; i++) {
            fact[i + 1] = fact[i] * T{i + 1};
        }

        ifact[N] = T{1} / fact[N];

        for (size_t i = N; i > 0; i--) {
            ifact[i - 1] = ifact[i] * T{i};
        }
    }

    T p(const int a, const int b) const {
        if (b < 0 || a < b) {
            return T{0};
        }

        assert(0 <= a);
        assert(a <= static_cast<int>(N));
        assert(a - b <= static_cast<int>(N));

        return fact[a] * ifact[a - b];
    }

    T c(const int a, const int b) const {
        if (b < 0 || a < b) {
            return T{0};
        }

        assert(b <= static_cast<int>(N));

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
