---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/static_binomial.hpp
    title: "Static Binomial (\u4E8C\u9805\u4FC2\u6570, constexpr)"
  - icon: ':heavy_check_mark:'
    path: math/static_mod_int.hpp
    title: Static Mod Int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1520
    links:
    - https://yukicoder.me/problems/no/1520
  bundledCode: "#line 1 \"test/math/static_binomial.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1520\"\n\n#include <iostream>\n\n#line 2 \"math/static_binomial.hpp\"\
    \n\n#include <array>\n#include <cassert>\n#include <vector>\n\nnamespace Ku {\n\
    /**\n * @brief Static Binomial (\u4E8C\u9805\u4FC2\u6570, constexpr)\n */\ntemplate\
    \ <class T, unsigned N> class StaticBinomial {\n  private:\n    std::array<T,\
    \ N + 1> fact;\n    std::array<T, N + 1> ifact;\n\n  public:\n    constexpr StaticBinomial()\
    \ : fact{}, ifact{} {\n        fact[0] = T{1U};\n        for (unsigned i = 0;\
    \ i < N; i++) {\n            fact[i + 1] = fact[i] * T{i + 1};\n        }\n\n\
    \        ifact[N] = T{1U} / fact[N];\n\n        for (unsigned i = N; i > 0; i--)\
    \ {\n            ifact[i - 1] = ifact[i] * T{i};\n        }\n    }\n\n    T p(const\
    \ int a, const int b) const {\n        if (b < 0 || a < b) {\n            return\
    \ T{0U};\n        }\n\n        assert(0 <= a);\n        assert(a <= static_cast<int>(N));\n\
    \        assert(a - b <= static_cast<int>(N));\n\n        return fact[a] * ifact[a\
    \ - b];\n    }\n\n    T c(const int a, const int b) const {\n        if (b < 0\
    \ || a < b) {\n            return T{0U};\n        }\n\n        assert(b <= static_cast<int>(N));\n\
    \n        return p(a, b) * ifact[b];\n    }\n\n    T h(const int a, const int\
    \ b) const {\n        if (a == 0 && b == 0) {\n            return T{1U};\n   \
    \     }\n\n        if (a <= 0 || b < 0) {\n            return T{0U};\n       \
    \ }\n\n        return c(a + b - 1, b);\n    }\n};\n}  // namespace Ku\n#line 2\
    \ \"math/static_mod_int.hpp\"\n\nnamespace Ku {\n/**\n * @brief Static Mod Int\n\
    \ */\ntemplate <unsigned M> class StaticModInt {\n  private:\n    unsigned v;\n\
    \n  public:\n    constexpr StaticModInt() : StaticModInt{0U} {}\n    constexpr\
    \ explicit StaticModInt(const unsigned long long _v)\n        : v(static_cast<unsigned>(_v\
    \ % M)) {}\n\n    constexpr static unsigned mod() { return M; }\n\n    constexpr\
    \ unsigned val() const { return v; }\n\n    constexpr StaticModInt& operator+=(const\
    \ StaticModInt& rhs) {\n        v += rhs.val();\n        if (M <= v) {\n     \
    \       v -= M;\n        }\n\n        return *this;\n    }\n\n    constexpr StaticModInt&\
    \ operator-=(const StaticModInt& rhs) {\n        if (v < rhs.val()) {\n      \
    \      v += M;\n        }\n        v -= rhs.val();\n\n        return *this;\n\
    \    }\n\n    constexpr StaticModInt& operator*=(const StaticModInt& rhs) {\n\
    \        v = static_cast<unsigned>(\n            (static_cast<unsigned long long>(v)\
    \ * rhs.val()) % M);\n\n        return *this;\n    }\n\n    constexpr StaticModInt&\
    \ operator/=(const StaticModInt& rhs) {\n        return *this *= rhs.inv();\n\
    \    }\n\n    constexpr friend StaticModInt operator+(const StaticModInt& lhs,\n\
    \                                            const StaticModInt& rhs) {\n    \
    \    return StaticModInt{lhs} += rhs;\n    }\n\n    constexpr friend StaticModInt\
    \ operator-(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) {\n        return StaticModInt{lhs} -= rhs;\n \
    \   }\n\n    constexpr friend StaticModInt operator*(const StaticModInt& lhs,\n\
    \                                            const StaticModInt& rhs) {\n    \
    \    return StaticModInt{lhs} *= rhs;\n    }\n\n    constexpr friend StaticModInt\
    \ operator/(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) {\n        return StaticModInt{lhs} /= rhs;\n \
    \   }\n\n    constexpr StaticModInt pow(unsigned y) const {\n        StaticModInt\
    \ res{1U}, x{*this};\n        while (0 < y) {\n            if (y & 1U) {\n   \
    \             res *= x;\n            }\n\n            x *= x;\n            y >>=\
    \ 1U;\n        }\n\n        return res;\n    }\n\n    constexpr StaticModInt inv()\
    \ const { return pow(M - 2); }\n};\n};  // namespace Ku\n#line 7 \"test/math/static_binomial.test.cpp\"\
    \n\nusing ModInt = Ku::StaticModInt<1000000007U>;\nconstexpr Ku::StaticBinomial<ModInt,\
    \ 400000U> bin;\n\nint main() {\n    int T;\n    std::cin >> T;\n\n    while (T--)\
    \ {\n        int h, w;\n        std::cin >> h >> w;\n\n        if (h == 1 || w\
    \ == 1) {\n            std::cout << 0 << \"\\n\";\n            continue;\n   \
    \     }\n\n        ModInt ans{ModInt{2ULL * (h + w - 3)} * bin.c(h + w - 4, h\
    \ - 2)};\n        std::cout << ans.val() << \"\\n\";\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1520\"\n\n#include <iostream>\n\
    \n#include \"../../math/static_binomial.hpp\"\n#include \"../../math/static_mod_int.hpp\"\
    \n\nusing ModInt = Ku::StaticModInt<1000000007U>;\nconstexpr Ku::StaticBinomial<ModInt,\
    \ 400000U> bin;\n\nint main() {\n    int T;\n    std::cin >> T;\n\n    while (T--)\
    \ {\n        int h, w;\n        std::cin >> h >> w;\n\n        if (h == 1 || w\
    \ == 1) {\n            std::cout << 0 << \"\\n\";\n            continue;\n   \
    \     }\n\n        ModInt ans{ModInt{2ULL * (h + w - 3)} * bin.c(h + w - 4, h\
    \ - 2)};\n        std::cout << ans.val() << \"\\n\";\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - math/static_binomial.hpp
  - math/static_mod_int.hpp
  isVerificationFile: true
  path: test/math/static_binomial.test.cpp
  requiredBy: []
  timestamp: '2024-12-01 10:43:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/static_binomial.test.cpp
layout: document
redirect_from:
- /verify/test/math/static_binomial.test.cpp
- /verify/test/math/static_binomial.test.cpp.html
title: test/math/static_binomial.test.cpp
---
