#pragma once

#include <algorithm>
#include <iterator>

namespace ku {
/**
 * @brief Next Combination
 */
template <class I>
bool NextCombination(const I& begin, const I& end, const size_t k) {
    const I sub = std::next(begin, k);

    if (begin == end || begin == sub || end == sub) {
        return false;
    }

    I src = sub;
    while (begin != src) {
        std::advance(src, -1);

        if (*src < *std::prev(end, 1)) {
            I dst = sub;
            while (*dst <= *src) {
                std::advance(dst, 1);
            }

            std::iter_swap(src, dst);
            std::rotate(std::next(src, 1), std::next(dst, 1), end);
            std::rotate(sub, std::next(sub, std::distance(dst, end) - 1), end);

            return true;
        }
    }

    std::rotate(begin, sub, end);

    return false;
}
};  // namespace ku
