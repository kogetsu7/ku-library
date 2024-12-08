---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: "Binomial (\u4E8C\u9805\u4FC2\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/math/binomial.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#line 2 \"math/binomial.hpp\"\n\n#include <array>\n#include <cassert>\n#include\
    \ <type_traits>\n#include <vector>\n\nnamespace ku {\n/**\n * @brief Binomial\
    \ (\u4E8C\u9805\u4FC2\u6570)\n */\ntemplate <class T> class Binomial {\n    static_assert(!std::is_floating_point_v<T>,\
    \ \"T must not be floating point\");\n\n  private:\n    size_t n;\n    std::vector<T>\
    \ fact;\n    std::vector<T> ifact;\n\n  public:\n    Binomial() noexcept : Binomial(0)\
    \ {}\n    explicit Binomial(const size_t _n) noexcept\n        : n(_n), fact(_n\
    \ + 1), ifact(_n + 1) {\n        fact[0] = T(1);\n        for (size_t i = 0; i\
    \ < n; i++) {\n            fact[i + 1] = fact[i] * T(i + 1);\n        }\n\n  \
    \      ifact[n] = T(1) / fact[n];\n\n        for (size_t i = n; i > 0; i--) {\n\
    \            ifact[i - 1] = ifact[i] * T(i);\n        }\n    }\n\n    //! \u9806\
    \u5217\n    T p(const int a, const int b) const noexcept {\n        if (b < 0\
    \ || a < b) {\n            return T(0);\n        }\n\n        assert(0 <= a);\n\
    \        assert(a <= static_cast<int>(n));\n        assert(a - b <= static_cast<int>(n));\n\
    \n        return fact[a] * ifact[a - b];\n    }\n\n    //! \u7D44\u5408\u305B\n\
    \    T c(const int a, const int b) const noexcept {\n        if (b < 0 || a <\
    \ b) {\n            return T(0);\n        }\n\n        assert(b <= static_cast<int>(n));\n\
    \n        return p(a, b) * ifact[b];\n    }\n\n    //! \u91CD\u8907\u7D44\u5408\
    \u305B\n    T h(const int a, const int b) const noexcept {\n        if (a == 0\
    \ && b == 0) {\n            return T(1);\n        }\n\n        if (a <= 0 || b\
    \ < 0) {\n            return T(0);\n        }\n\n        return c(a + b - 1, b);\n\
    \    }\n};\n}  // namespace ku\n#line 4 \"test/math/binomial.test.cpp\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n\n#include <atcoder/modint>\n\nint main()\
    \ {\n    int T, M;\n    std::cin >> T >> M;\n\n    atcoder::modint::set_mod(M);\n\
    \n    ku::Binomial<atcoder::modint> bin(std::min(M - 1, 10000000));\n\n    while\
    \ (T--) {\n        int n, k;\n        std::cin >> n >> k;\n\n        std::cout\
    \ << bin.c(n, k).val() << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../../math/binomial.hpp\"\n\n#include <algorithm>\n#include <iostream>\n\
    \n#include <atcoder/modint>\n\nint main() {\n    int T, M;\n    std::cin >> T\
    \ >> M;\n\n    atcoder::modint::set_mod(M);\n\n    ku::Binomial<atcoder::modint>\
    \ bin(std::min(M - 1, 10000000));\n\n    while (T--) {\n        int n, k;\n  \
    \      std::cin >> n >> k;\n\n        std::cout << bin.c(n, k).val() << \"\\n\"\
    ;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - math/binomial.hpp
  isVerificationFile: true
  path: test/math/binomial.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 06:34:06+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/binomial.test.cpp
layout: document
redirect_from:
- /verify/test/math/binomial.test.cpp
- /verify/test/math/binomial.test.cpp.html
title: test/math/binomial.test.cpp
---
