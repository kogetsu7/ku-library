#pragma once

namespace Ku {
/**
 * @brief Static Mod Int
 */
template <unsigned M> class StaticModInt {
  private:
    unsigned v;

  public:
    constexpr StaticModInt() : StaticModInt(0) {}
    constexpr explicit StaticModInt(const unsigned long long _v)
        : v(static_cast<unsigned>(_v % M)) {}

    constexpr static unsigned mod() { return M; }

    constexpr unsigned val() const { return v; }

    constexpr StaticModInt& operator+=(const StaticModInt& rhs) {
        v += rhs.val();
        if (M <= v) {
            v -= M;
        }

        return *this;
    }

    constexpr StaticModInt& operator-=(const StaticModInt& rhs) {
        if (v < rhs.val()) {
            v += M;
        }
        v -= rhs.val();

        return *this;
    }

    constexpr StaticModInt& operator*=(const StaticModInt& rhs) {
        v = static_cast<unsigned>(
            (static_cast<unsigned long long>(v) * rhs.val()) % M);

        return *this;
    }

    constexpr StaticModInt& operator/=(const StaticModInt& rhs) {
        return *this *= rhs.inv();
    }

    constexpr friend StaticModInt operator+(const StaticModInt& lhs,
                                            const StaticModInt& rhs) {
        return StaticModInt(lhs) += rhs;
    }

    constexpr friend StaticModInt operator-(const StaticModInt& lhs,
                                            const StaticModInt& rhs) {
        return StaticModInt(lhs) -= rhs;
    }

    constexpr friend StaticModInt operator*(const StaticModInt& lhs,
                                            const StaticModInt& rhs) {
        return StaticModInt(lhs) *= rhs;
    }

    constexpr friend StaticModInt operator/(const StaticModInt& lhs,
                                            const StaticModInt& rhs) {
        return StaticModInt(lhs) /= rhs;
    }

    constexpr StaticModInt pow(unsigned y) const {
        StaticModInt res{1U}, x{*this};
        while (0 < y) {
            if (y & 1U) {
                res *= x;
            }

            x *= x;
            y >>= 1U;
        }

        return res;
    }

    constexpr StaticModInt inv() const { return pow(M - 2); }
};
};  // namespace Ku
