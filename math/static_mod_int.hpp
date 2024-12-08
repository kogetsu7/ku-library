#pragma once

namespace ku {
/**
 * @brief Static Mod Int
 */
template <unsigned M> class StaticModInt {
    static_assert(0 < M, "M must be positive.");

  private:
    unsigned v;

  public:
    constexpr StaticModInt() noexcept : v(0) {}
    explicit constexpr StaticModInt(const unsigned long long _v) noexcept
        : v(static_cast<unsigned>(_v % M)) {}

    static constexpr StaticModInt raw(const unsigned _v) noexcept {
        StaticModInt res;
        res.v = _v;

        return res;
    }

    static constexpr unsigned mod() noexcept { return M; }

    constexpr unsigned val() const noexcept { return v; }

    friend constexpr bool operator==(const StaticModInt& lhs,
                                     const StaticModInt& rhs) noexcept {
        return lhs.v == rhs.v;
    }

    friend constexpr bool operator!=(const StaticModInt& lhs,
                                     const StaticModInt& rhs) noexcept {
        return lhs.v != rhs.v;
    }

    constexpr StaticModInt& operator+=(const StaticModInt& rhs) noexcept {
        v += rhs.val();
        if (M <= v) {
            v -= M;
        }

        return *this;
    }

    constexpr StaticModInt& operator-=(const StaticModInt& rhs) noexcept {
        if (v < rhs.val()) {
            v += M;
        }
        v -= rhs.val();

        return *this;
    }

    constexpr StaticModInt& operator*=(const StaticModInt& rhs) noexcept {
        v = static_cast<unsigned>(
            (static_cast<unsigned long long>(v) * rhs.val()) % M);

        return *this;
    }

    constexpr StaticModInt& operator/=(const StaticModInt& rhs) noexcept {
        assert(rhs.val() != 0);

        return *this *= rhs.inv();
    }

    friend constexpr StaticModInt operator+(const StaticModInt& lhs,
                                            const StaticModInt& rhs) noexcept {
        return StaticModInt(lhs) += rhs;
    }

    friend constexpr StaticModInt operator-(const StaticModInt& lhs,
                                            const StaticModInt& rhs) noexcept {
        return StaticModInt(lhs) -= rhs;
    }

    friend constexpr StaticModInt operator*(const StaticModInt& lhs,
                                            const StaticModInt& rhs) noexcept {
        return StaticModInt(lhs) *= rhs;
    }

    friend constexpr StaticModInt operator/(const StaticModInt& lhs,
                                            const StaticModInt& rhs) noexcept {
        return StaticModInt(lhs) /= rhs;
    }

    constexpr StaticModInt pow(unsigned y) const noexcept {
        StaticModInt res = raw(1);
        StaticModInt x = *this;

        while (0 < y) {
            if (y & 1U) {
                res *= x;
            }

            x *= x;
            y >>= 1U;
        }

        return res;
    }

    constexpr StaticModInt inv() const noexcept { return pow(M - 2); }
};
};  // namespace ku
