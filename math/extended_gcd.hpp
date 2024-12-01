#pragma once

namespace Ku {
/**
 * @brief Extended Euclidean Algorithm (拡張ユークリッドの互除法)
 */
template <class T> T ExtendedGCD(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    T res = ExtendedGCD(b, a % b, y, x);
    y -= (a / b) * x;

    return res;
}
};  // namespace Ku
