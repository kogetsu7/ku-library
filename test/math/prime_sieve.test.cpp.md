---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.hpp
    title: "Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/106
    links:
    - https://yukicoder.me/problems/no/106
  bundledCode: "#line 1 \"test/math/prime_sieve.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/106\"\
    \n\n#include <iostream>\n\n#line 2 \"math/prime_sieve.hpp\"\n\n#include <array>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace Ku {\n\
    /**\n * @brief Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
    )\n */\nclass PrimeSieve {\n  private:\n    std::vector<unsigned> d;\n    std::vector<unsigned>\
    \ p;\n\n  public:\n    PrimeSieve() : PrimeSieve(0) {}\n    PrimeSieve(const size_t\
    \ _n) : d(_n + 1), p() {\n        for (unsigned i = 2; i <= static_cast<unsigned>(_n);\
    \ i++) {\n            if (d[i] != 0) {\n                continue;\n          \
    \  }\n\n            d[i] = i;\n            p.push_back(i);\n\n            for\
    \ (unsigned long long j = static_cast<unsigned long long>(i) * i;\n          \
    \       j <= static_cast<unsigned long long>(_n); j += i) {\n                if\
    \ (d[j] != 0) {\n                    continue;\n                }\n\n        \
    \        d[j] = i;\n            }\n        }\n    }\n\n    bool is_prime(const\
    \ unsigned n) const {\n        assert(n < static_cast<unsigned>(d.size()));\n\n\
    \        return (n < 2) ? false : (d[n] == n);\n    }\n\n    unsigned get_prime(const\
    \ size_t i) const {\n        assert(i < p.size());\n\n        return p[i];\n \
    \   }\n\n    std::vector<std::pair<unsigned, unsigned>> prime_factors(unsigned\
    \ n) const {\n        assert(n < static_cast<unsigned>(d.size()));\n\n       \
    \ std::vector<std::pair<unsigned, unsigned>> res;\n\n        while (2 <= n) {\n\
    \            if (res.empty() || res.back().first != d[n]) {\n                res.emplace_back(d[n],\
    \ 1U);\n            } else {\n                res.back().second++;\n         \
    \   }\n\n            n /= d[n];\n        }\n\n        return res;\n    }\n\n \
    \   std::vector<unsigned> divisors(const unsigned n) const {\n        assert(n\
    \ < static_cast<unsigned>(d.size()));\n\n        std::vector<unsigned> res;\n\
    \        res.push_back(1);\n\n        const auto pf = prime_factors(n);\n\n  \
    \      for (const auto& te : pf) {\n            const size_t s = res.size();\n\
    \n            for (size_t i = 0; i < s; i++) {\n                unsigned m{1};\n\
    \n                for (unsigned j = 0; j < te.second; j++) {\n               \
    \     m *= te.first;\n                    res.push_back(res[i] * m);\n       \
    \         }\n            }\n        }\n\n        std::sort(res.begin(), res.end());\n\
    \n        return res;\n    }\n};\n};  // namespace Ku\n#line 6 \"test/math/prime_sieve.test.cpp\"\
    \n\nint main() {\n    int N, K;\n    std::cin >> N >> K;\n\n    const Ku::PrimeSieve\
    \ ps(N);\n\n    int ans = 0;\n    for (int i = 2; i <= N; i++) {\n        auto\
    \ pf = ps.prime_factors(i);\n\n        if (K <= static_cast<int>(pf.size())) {\n\
    \            ans++;\n        }\n    }\n\n    std::cout << ans << \"\\n\";\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/106\"\n\n#include <iostream>\n\
    \n#include \"../../math/prime_sieve.hpp\"\n\nint main() {\n    int N, K;\n   \
    \ std::cin >> N >> K;\n\n    const Ku::PrimeSieve ps(N);\n\n    int ans = 0;\n\
    \    for (int i = 2; i <= N; i++) {\n        auto pf = ps.prime_factors(i);\n\n\
    \        if (K <= static_cast<int>(pf.size())) {\n            ans++;\n       \
    \ }\n    }\n\n    std::cout << ans << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/prime_sieve.test.cpp
  requiredBy: []
  timestamp: '2024-12-01 13:33:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/prime_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime_sieve.test.cpp
- /verify/test/math/prime_sieve.test.cpp.html
title: test/math/prime_sieve.test.cpp
---
