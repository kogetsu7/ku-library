#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

namespace ku {
/**
 * @brief Matrix (行列)
 */
template <class T> class Matrix {
  private:
    size_t h;
    size_t w;
    std::vector<std::vector<T>> d;

  public:
    Matrix() noexcept : Matrix(0) {}
    explicit Matrix(const size_t _h) noexcept : Matrix(_h, _h) {}
    explicit Matrix(const size_t _h, const size_t _w) noexcept
        : Matrix(std::vector<std::vector<T>>(_h, std::vector<T>(_w))) {}
    explicit Matrix(const std::vector<std::vector<T>>& _d) noexcept
        : h(_d.size()), w(_d.empty() ? 0 : _d[0].size()), d(_d) {
        assert(std::all_of(
            d.begin(), d.end(),
            [&](const std::vector<T>& r) -> bool { return r.size() == w; }));
    }

    //! 単位行列
    static Matrix identity(const size_t s) noexcept {
        Matrix res(s);

        for (size_t i = 0; i < s; i++) {
            res.set(i, i, T(1));
        }

        return res;
    }

    size_t height() const noexcept { return h; }
    size_t width() const noexcept { return w; }

    T get(const size_t i, const size_t j) const noexcept {
        assert(i < h);
        assert(j < w);

        return d[i][j];
    }

    T set(const size_t i, const size_t j, const T& v) noexcept {
        assert(i < h);
        assert(j < w);

        return d[i][j] = v;
    }

    friend bool operator==(const Matrix& lhs, const Matrix& rhs) noexcept {
        return lhs.d == rhs.d;
    }

    friend bool operator!=(const Matrix& lhs, const Matrix& rhs) noexcept {
        return lhs.d != rhs.d;
    }

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) noexcept {
        assert(lhs.width() == rhs.height());

        Matrix res(lhs.height(), rhs.width());
        for (size_t i = 0; i < lhs.height(); i++) {
            for (size_t j = 0; j < rhs.width(); j++) {
                for (size_t k = 0; k < lhs.width(); k++) {
                    res.set(i, j,
                            res.get(i, j) + lhs.get(i, k) * rhs.get(k, j));
                }
            }
        }

        return res;
    }

    Matrix& operator*=(const Matrix& rhs) noexcept {
        assert(height() == width());
        assert(rhs.height() == rhs.width());

        return *this = *this * rhs;
    }

    Matrix pow(unsigned long long y) const noexcept {
        assert(height() == width());

        Matrix res = identity(height());
        Matrix x = *this;

        while (0 < y) {
            if (y & 1U) {
                res *= x;
            }

            x *= x;
            y >>= 1U;
        }

        return res;
    }
};
};  // namespace ku
