#pragma once

#include <array>
#include <cassert>
#include <utility>
#include <vector>

namespace Ku {
/**
 * @brief Prime Sieve (エラトステネスの篩)
 */
class PrimeSieve {
  private:
    std::vector<unsigned> d;
    std::vector<unsigned> p;

  public:
    PrimeSieve() : PrimeSieve(0) {}
    PrimeSieve(const size_t _n) : d(_n + 1), p() {
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

    bool is_prime(const unsigned n) const {
        assert(n < static_cast<unsigned>(d.size()));

        return (n < 2) ? false : (d[n] == n);
    }

    unsigned get_prime(const size_t i) const {
        assert(i < p.size());

        return p[i];
    }

    std::vector<std::pair<unsigned, unsigned>> prime_factors(unsigned n) const {
        assert(n < static_cast<unsigned>(d.size()));

        std::vector<std::pair<unsigned, unsigned>> res;

        while (2 <= n) {
            if (res.empty() || res.back().first != d[n]) {
                res.emplace_back(d[n], 1U);
            } else {
                res.back().second++;
            }

            n /= d[n];
        }

        return res;
    }

    std::vector<unsigned> divisors(const unsigned n) const {
        assert(n < static_cast<unsigned>(d.size()));

        std::vector<unsigned> res;
        res.push_back(1);

        const auto pf = prime_factors(n);

        for (const auto& te : pf) {
            const size_t s = res.size();

            for (size_t i = 0; i < s; i++) {
                unsigned m{1};

                for (unsigned j = 0; j < te.second; j++) {
                    m *= te.first;
                    res.push_back(res[i] * m);
                }
            }
        }

        std::sort(res.begin(), res.end());

        return res;
    }
};
};  // namespace Ku
