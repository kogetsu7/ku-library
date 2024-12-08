---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/binomial.test.cpp
    title: test/math/binomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Binomial (\u4E8C\u9805\u4FC2\u6570)"
    links:
    - https://blog.hamayanhamayan.com/entry/2018/06/06/210256
  bundledCode: "#line 2 \"math/binomial.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace ku {\n/**\n * @brief Binomial (\u4E8C\u9805\u4FC2\
    \u6570)\n * @note \u53C2\u8003: https://blog.hamayanhamayan.com/entry/2018/06/06/210256\n\
    \ */\ntemplate <class T> class Binomial {\n    static_assert(!std::is_floating_point_v<T>,\
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
    \    }\n};\n}  // namespace ku\n"
  code: "#pragma once\n\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\
    \nnamespace ku {\n/**\n * @brief Binomial (\u4E8C\u9805\u4FC2\u6570)\n * @note\
    \ \u53C2\u8003: https://blog.hamayanhamayan.com/entry/2018/06/06/210256\n */\n\
    template <class T> class Binomial {\n    static_assert(!std::is_floating_point_v<T>,\
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
    \    }\n};\n}  // namespace ku\n"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy: []
  timestamp: '2024-12-08 08:00:28+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/binomial.test.cpp
documentation_of: math/binomial.hpp
layout: document
title: "Binomial (\u4E8C\u9805\u4FC2\u6570)"
---

## 概要
二項係数を前計算する

## コンストラクタ
```cpp
Binomial<T>(unsigned n)
```
- サイズnのテーブルを作成する

### 計算量
逆元の計算を$O(\log{M})$，その他の演算を$O(1)$として<br>
- $O(n+\log{M})$

## p
```cpp
T p(int a, int b)
```
順列の総数${}_a P_b$を返す
### 計算量
- $O(1)$

## c
```cpp
T c(int a, int b)
```
組み合わせの総数${}_a C_b$を返す
### 計算量
- $O(1)$

## h
```cpp
T h(int a, int b)
```
重複組み合わせの総数${}_a H_b$を返す
### 計算量
- $O(1)$
