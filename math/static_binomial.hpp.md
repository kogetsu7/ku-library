---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/static_binomial.test.cpp
    title: test/math/static_binomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Static Binomial (\u4E8C\u9805\u4FC2\u6570, constexpr)"
    links: []
  bundledCode: "#line 2 \"math/static_binomial.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace Ku {\n/**\n * @brief Static Binomial\
    \ (\u4E8C\u9805\u4FC2\u6570, constexpr)\n */\ntemplate <class T, size_t N> class\
    \ StaticBinomial {\n  private:\n    std::array<T, N + 1> fact;\n    std::array<T,\
    \ N + 1> ifact;\n\n  public:\n    constexpr StaticBinomial() : fact{}, ifact{}\
    \ {\n        fact[0] = T{1};\n        for (size_t i = 0; i < N; i++) {\n     \
    \       fact[i + 1] = fact[i] * T{i + 1};\n        }\n\n        ifact[N] = T{1}\
    \ / fact[N];\n\n        for (size_t i = N; i > 0; i--) {\n            ifact[i\
    \ - 1] = ifact[i] * T{i};\n        }\n    }\n\n    T p(const int a, const int\
    \ b) const {\n        if (b < 0 || a < b) {\n            return T{0};\n      \
    \  }\n\n        assert(0 <= a);\n        assert(a <= static_cast<int>(N));\n \
    \       assert(a - b <= static_cast<int>(N));\n\n        return fact[a] * ifact[a\
    \ - b];\n    }\n\n    T c(const int a, const int b) const {\n        if (b < 0\
    \ || a < b) {\n            return T{0};\n        }\n\n        assert(b <= static_cast<int>(N));\n\
    \n        return p(a, b) * ifact[b];\n    }\n\n    T h(const int a, const int\
    \ b) const {\n        if (a == 0 && b == 0) {\n            return T{1};\n    \
    \    }\n\n        if (a <= 0 || b < 0) {\n            return T{0};\n        }\n\
    \n        return c(a + b - 1, b);\n    }\n};\n}  // namespace Ku\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \nnamespace Ku {\n/**\n * @brief Static Binomial (\u4E8C\u9805\u4FC2\u6570, constexpr)\n\
    \ */\ntemplate <class T, size_t N> class StaticBinomial {\n  private:\n    std::array<T,\
    \ N + 1> fact;\n    std::array<T, N + 1> ifact;\n\n  public:\n    constexpr StaticBinomial()\
    \ : fact{}, ifact{} {\n        fact[0] = T{1};\n        for (size_t i = 0; i <\
    \ N; i++) {\n            fact[i + 1] = fact[i] * T{i + 1};\n        }\n\n    \
    \    ifact[N] = T{1} / fact[N];\n\n        for (size_t i = N; i > 0; i--) {\n\
    \            ifact[i - 1] = ifact[i] * T{i};\n        }\n    }\n\n    T p(const\
    \ int a, const int b) const {\n        if (b < 0 || a < b) {\n            return\
    \ T{0};\n        }\n\n        assert(0 <= a);\n        assert(a <= static_cast<int>(N));\n\
    \        assert(a - b <= static_cast<int>(N));\n\n        return fact[a] * ifact[a\
    \ - b];\n    }\n\n    T c(const int a, const int b) const {\n        if (b < 0\
    \ || a < b) {\n            return T{0};\n        }\n\n        assert(b <= static_cast<int>(N));\n\
    \n        return p(a, b) * ifact[b];\n    }\n\n    T h(const int a, const int\
    \ b) const {\n        if (a == 0 && b == 0) {\n            return T{1};\n    \
    \    }\n\n        if (a <= 0 || b < 0) {\n            return T{0};\n        }\n\
    \n        return c(a + b - 1, b);\n    }\n};\n}  // namespace Ku\n"
  dependsOn: []
  isVerificationFile: false
  path: math/static_binomial.hpp
  requiredBy: []
  timestamp: '2024-12-01 11:11:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/static_binomial.test.cpp
documentation_of: math/static_binomial.hpp
layout: document
redirect_from:
- /library/math/static_binomial.hpp
- /library/math/static_binomial.hpp.html
title: "Static Binomial (\u4E8C\u9805\u4FC2\u6570, constexpr)"
---
