#pragma once

#include <type_traits>

namespace ku {
/**
 * @brief Extended Euclidean Algorithm (拡張ユークリッドの互除法)
 * @note 参考: https://qiita.com/drken/items/b97ff231e43bce50199a
 */
template <class T> T ExtendedGCD(T a, T b, T& x, T& y) {
    static_assert(!std::is_floating_point_v<T>, "T must not be floating point");

    if (b == T(0)) {
        x = T(1);
        y = T(0);

        return a;
    }

    T res = ExtendedGCD(b, a % b, y, x);
    y -= (a / b) * x;

    return res;
}
};  // namespace ku
