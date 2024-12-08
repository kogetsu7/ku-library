#pragma once

#include <cassert>
#include <type_traits>
#include <vector>

namespace ku {
/**
 * @brief Binomial (二項係数)
 * @note 参考: https://blog.hamayanhamayan.com/entry/2018/06/06/210256
 */
template <class T> class Binomial {
    static_assert(!std::is_floating_point_v<T>, "T must not be floating point");

  private:
    size_t n;
    std::vector<T> fact;
    std::vector<T> ifact;

  public:
    Binomial() noexcept : Binomial(0) {}
    explicit Binomial(const size_t _n) noexcept
        : n(_n), fact(_n + 1), ifact(_n + 1) {
        fact[0] = T(1);
        for (size_t i = 0; i < n; i++) {
            fact[i + 1] = fact[i] * T(i + 1);
        }

        ifact[n] = T(1) / fact[n];

        for (size_t i = n; i > 0; i--) {
            ifact[i - 1] = ifact[i] * T(i);
        }
    }

    //! 順列
    T p(const int a, const int b) const noexcept {
        if (b < 0 || a < b) {
            return T(0);
        }

        assert(0 <= a);
        assert(a <= static_cast<int>(n));
        assert(a - b <= static_cast<int>(n));

        return fact[a] * ifact[a - b];
    }

    //! 組合せ
    T c(const int a, const int b) const noexcept {
        if (b < 0 || a < b) {
            return T(0);
        }

        assert(b <= static_cast<int>(n));

        return p(a, b) * ifact[b];
    }

    //! 重複組合せ
    T h(const int a, const int b) const noexcept {
        if (a == 0 && b == 0) {
            return T(1);
        }

        if (a <= 0 || b < 0) {
            return T(0);
        }

        return c(a + b - 1, b);
    }
};
}  // namespace ku
