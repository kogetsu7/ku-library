---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/binomial.test.cpp
    title: test/math/binomial.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Binomial (\u4E8C\u9805\u4FC2\u6570)"
    links: []
  bundledCode: "#line 2 \"math/binomial.hpp\"\n\n/**\n * @brief Binomial (\u4E8C\u9805\
    \u4FC2\u6570)\n */\n\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \nnamespace Ku {\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570 (constexpr)\n */\ntemplate\
    \ <class T, int N> class StaticBinomial {\n    static_assert(0 < N, \"N must be\
    \ positive.\");\n\n  private:\n    std::array<T, N + 1> fact;\n    std::array<T,\
    \ N + 1> ifact;\n\n  public:\n    constexpr StaticBinomial() {\n        fact[0]\
    \ = T{1};\n        for (int i = 0; i < N; i++) {\n            fact[i + 1] = fact[i]\
    \ * T{i + 1};\n        }\n\n        ifact[N] = T{1} / fact[N];\n\n        for\
    \ (int i = N; i > 0; i--) {\n            ifact[i - 1] = ifact[i] * T{i};\n   \
    \     }\n    }\n\n    T p(const int a, const int b) const {\n        if (b < 0\
    \ || a < b) {\n            return T{0};\n        }\n\n        assert(0 <= a);\n\
    \        assert(a <= n);\n        assert(a - b <= n);\n\n        return fact[a]\
    \ * ifact[a - b];\n    }\n\n    T c(const int a, const int b) const {\n      \
    \  if (b < 0 || a < b) {\n            return T{0};\n        }\n\n        assert(b\
    \ <= n);\n\n        return p(a, b) * ifact[b];\n    }\n\n    T h(const int a,\
    \ const int b) const {\n        if (a == 0 && b == 0) {\n            return T{1};\n\
    \        }\n\n        if (a <= 0 || b < 0) {\n            return T{0};\n     \
    \   }\n\n        return c(a + b - 1, b);\n    }\n};\n\n/**\n * @brief \u4E8C\u9805\
    \u4FC2\u6570\n */\ntemplate <class T> class DynamicBinomial {\n  private:\n  \
    \  int n;\n    std::vector<T> fact;\n    std::vector<T> ifact;\n\n  public:\n\
    \    DynamicBinomial() : DynamicBinomial{0} {}\n    explicit DynamicBinomial(const\
    \ int _n)\n        : n(_n), fact(_n + 1), ifact(_n + 1) {\n        assert(0 <=\
    \ n);\n\n        fact[0] = T{1};\n        for (int i = 0; i < n; i++) {\n    \
    \        fact[i + 1] = fact[i] * T{i + 1};\n        }\n\n        ifact[n] = T{1}\
    \ / fact[n];\n\n        for (int i = n; i > 0; i--) {\n            ifact[i - 1]\
    \ = ifact[i] * T{i};\n        }\n    }\n\n    T p(const int a, const int b) const\
    \ {\n        if (b < 0 || a < b) {\n            return T{0};\n        }\n\n  \
    \      assert(0 <= a);\n        assert(a <= n);\n        assert(a - b <= n);\n\
    \n        return fact[a] * ifact[a - b];\n    }\n\n    T c(const int a, const\
    \ int b) const {\n        if (b < 0 || a < b) {\n            return T{0};\n  \
    \      }\n\n        assert(b <= n);\n\n        return p(a, b) * ifact[b];\n  \
    \  }\n\n    T h(const int a, const int b) const {\n        if (a == 0 && b ==\
    \ 0) {\n            return T{1};\n        }\n\n        if (a <= 0 || b < 0) {\n\
    \            return T{0};\n        }\n\n        return c(a + b - 1, b);\n    }\n\
    };\n\ntemplate <class T> using Binomial = DynamicBinomial<T>;\n}  // namespace\
    \ Ku\n"
  code: "#pragma once\n\n/**\n * @brief Binomial (\u4E8C\u9805\u4FC2\u6570)\n */\n\
    \n#include <array>\n#include <cassert>\n#include <vector>\n\nnamespace Ku {\n\
    /**\n * @brief \u4E8C\u9805\u4FC2\u6570 (constexpr)\n */\ntemplate <class T, int\
    \ N> class StaticBinomial {\n    static_assert(0 < N, \"N must be positive.\"\
    );\n\n  private:\n    std::array<T, N + 1> fact;\n    std::array<T, N + 1> ifact;\n\
    \n  public:\n    constexpr StaticBinomial() {\n        fact[0] = T{1};\n     \
    \   for (int i = 0; i < N; i++) {\n            fact[i + 1] = fact[i] * T{i + 1};\n\
    \        }\n\n        ifact[N] = T{1} / fact[N];\n\n        for (int i = N; i\
    \ > 0; i--) {\n            ifact[i - 1] = ifact[i] * T{i};\n        }\n    }\n\
    \n    T p(const int a, const int b) const {\n        if (b < 0 || a < b) {\n \
    \           return T{0};\n        }\n\n        assert(0 <= a);\n        assert(a\
    \ <= n);\n        assert(a - b <= n);\n\n        return fact[a] * ifact[a - b];\n\
    \    }\n\n    T c(const int a, const int b) const {\n        if (b < 0 || a <\
    \ b) {\n            return T{0};\n        }\n\n        assert(b <= n);\n\n   \
    \     return p(a, b) * ifact[b];\n    }\n\n    T h(const int a, const int b) const\
    \ {\n        if (a == 0 && b == 0) {\n            return T{1};\n        }\n\n\
    \        if (a <= 0 || b < 0) {\n            return T{0};\n        }\n\n     \
    \   return c(a + b - 1, b);\n    }\n};\n\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\
    \n */\ntemplate <class T> class DynamicBinomial {\n  private:\n    int n;\n  \
    \  std::vector<T> fact;\n    std::vector<T> ifact;\n\n  public:\n    DynamicBinomial()\
    \ : DynamicBinomial{0} {}\n    explicit DynamicBinomial(const int _n)\n      \
    \  : n(_n), fact(_n + 1), ifact(_n + 1) {\n        assert(0 <= n);\n\n       \
    \ fact[0] = T{1};\n        for (int i = 0; i < n; i++) {\n            fact[i +\
    \ 1] = fact[i] * T{i + 1};\n        }\n\n        ifact[n] = T{1} / fact[n];\n\n\
    \        for (int i = n; i > 0; i--) {\n            ifact[i - 1] = ifact[i] *\
    \ T{i};\n        }\n    }\n\n    T p(const int a, const int b) const {\n     \
    \   if (b < 0 || a < b) {\n            return T{0};\n        }\n\n        assert(0\
    \ <= a);\n        assert(a <= n);\n        assert(a - b <= n);\n\n        return\
    \ fact[a] * ifact[a - b];\n    }\n\n    T c(const int a, const int b) const {\n\
    \        if (b < 0 || a < b) {\n            return T{0};\n        }\n\n      \
    \  assert(b <= n);\n\n        return p(a, b) * ifact[b];\n    }\n\n    T h(const\
    \ int a, const int b) const {\n        if (a == 0 && b == 0) {\n            return\
    \ T{1};\n        }\n\n        if (a <= 0 || b < 0) {\n            return T{0};\n\
    \        }\n\n        return c(a + b - 1, b);\n    }\n};\n\ntemplate <class T>\
    \ using Binomial = DynamicBinomial<T>;\n}  // namespace Ku\n"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy: []
  timestamp: '2024-11-30 19:58:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/binomial.test.cpp
documentation_of: math/binomial.hpp
layout: document
redirect_from:
- /library/math/binomial.hpp
- /library/math/binomial.hpp.html
title: "Binomial (\u4E8C\u9805\u4FC2\u6570)"
---
