#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <utility>
#include <vector>

namespace ku {
/**
 * @brief Prime Sieve (エラトステネスの篩)
 */
class PrimeSieve {
  private:
    std::vector<unsigned> d;
    std::vector<unsigned> p;

  public:
    PrimeSieve() noexcept : PrimeSieve(0) {}
    PrimeSieve(const size_t _n) noexcept : d(_n + 1), p() {
        for (unsigned i = 2; i <= static_cast<unsigned>(_n); i++) {
            if (d[i] != 0) {
                continue;
            }

            d[i] = i;
            p.push_back(i);

            for (unsigned long long j = static_cast<unsigned long long>(i) * i;
                 j <= static_cast<unsigned long long>(_n); j += i) {
                if (d[j] != 0) {
                    continue;
                }

                d[j] = i;
            }
        }
    }

    bool is_prime(const size_t n) const noexcept {
        assert(n < d.size());

        return (n < 2) ? false : (d[n] == n);
    }

    const std::vector<unsigned>& get_primes() const noexcept { return p; }

    std::vector<std::pair<unsigned, unsigned>> prime_factors(
        size_t n) const noexcept {
        assert(n < d.size());

        std::vector<std::pair<unsigned, unsigned>> res;

        while (2 <= n) {
            if (res.empty() || res.back().first != d[n]) {
                res.emplace_back(static_cast<unsigned>(d[n]), 1U);
            } else {
                res.back().second++;
            }

            n /= d[n];
        }

        return res;
    }

    std::vector<unsigned> divisors(const size_t n) const noexcept {
        assert(n < d.size());

        std::vector<unsigned> res;
        res.emplace_back(1U);

        const auto pf = prime_factors(n);

        for (const auto& te : pf) {
            const size_t s = res.size();

            for (size_t i = 0; i < s; i++) {
                unsigned m = 1U;

                for (unsigned j = 0; j < te.second; j++) {
                    m *= te.first;
                    res.emplace_back(res[i] * m);
                }
            }
        }

        std::sort(res.begin(), res.end());

        return res;
    }
};
};  // namespace ku
