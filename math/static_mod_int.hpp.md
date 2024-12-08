---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/matrix.test.cpp
    title: test/math/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Static Mod Int
    links: []
  bundledCode: "#line 2 \"math/static_mod_int.hpp\"\n\nnamespace ku {\n/**\n * @brief\
    \ Static Mod Int\n */\ntemplate <unsigned M> class StaticModInt {\n    static_assert(0\
    \ < M, \"M must be positive.\");\n\n  private:\n    unsigned v;\n\n  public:\n\
    \    constexpr StaticModInt() noexcept : v(0) {}\n    explicit constexpr StaticModInt(const\
    \ unsigned long long _v) noexcept\n        : v(static_cast<unsigned>(_v % M))\
    \ {}\n\n    static constexpr StaticModInt raw(const unsigned _v) noexcept {\n\
    \        StaticModInt res;\n        res.v = _v;\n\n        return res;\n    }\n\
    \n    static constexpr unsigned mod() noexcept { return M; }\n\n    constexpr\
    \ unsigned val() const noexcept { return v; }\n\n    friend constexpr bool operator==(const\
    \ StaticModInt& lhs,\n                                     const StaticModInt&\
    \ rhs) noexcept {\n        return lhs.v == rhs.v;\n    }\n\n    friend constexpr\
    \ bool operator!=(const StaticModInt& lhs,\n                                 \
    \    const StaticModInt& rhs) noexcept {\n        return lhs.v != rhs.v;\n   \
    \ }\n\n    constexpr StaticModInt& operator+=(const StaticModInt& rhs) noexcept\
    \ {\n        v += rhs.val();\n        if (M <= v) {\n            v -= M;\n   \
    \     }\n\n        return *this;\n    }\n\n    constexpr StaticModInt& operator-=(const\
    \ StaticModInt& rhs) noexcept {\n        if (v < rhs.val()) {\n            v +=\
    \ M;\n        }\n        v -= rhs.val();\n\n        return *this;\n    }\n\n \
    \   constexpr StaticModInt& operator*=(const StaticModInt& rhs) noexcept {\n \
    \       v = static_cast<unsigned>(\n            (static_cast<unsigned long long>(v)\
    \ * rhs.val()) % M);\n\n        return *this;\n    }\n\n    constexpr StaticModInt&\
    \ operator/=(const StaticModInt& rhs) noexcept {\n        assert(rhs.val() !=\
    \ 0);\n\n        return *this *= rhs.inv();\n    }\n\n    friend constexpr StaticModInt\
    \ operator+(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) noexcept {\n        return StaticModInt(lhs) +=\
    \ rhs;\n    }\n\n    friend constexpr StaticModInt operator-(const StaticModInt&\
    \ lhs,\n                                            const StaticModInt& rhs) noexcept\
    \ {\n        return StaticModInt(lhs) -= rhs;\n    }\n\n    friend constexpr StaticModInt\
    \ operator*(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) noexcept {\n        return StaticModInt(lhs) *=\
    \ rhs;\n    }\n\n    friend constexpr StaticModInt operator/(const StaticModInt&\
    \ lhs,\n                                            const StaticModInt& rhs) noexcept\
    \ {\n        return StaticModInt(lhs) /= rhs;\n    }\n\n    constexpr StaticModInt\
    \ pow(unsigned y) const noexcept {\n        StaticModInt res = raw(1);\n     \
    \   StaticModInt x = *this;\n\n        while (0 < y) {\n            if (y & 1U)\
    \ {\n                res *= x;\n            }\n\n            x *= x;\n       \
    \     y >>= 1U;\n        }\n\n        return res;\n    }\n\n    constexpr StaticModInt\
    \ inv() const noexcept { return pow(M - 2); }\n};\n};  // namespace ku\n"
  code: "#pragma once\n\nnamespace ku {\n/**\n * @brief Static Mod Int\n */\ntemplate\
    \ <unsigned M> class StaticModInt {\n    static_assert(0 < M, \"M must be positive.\"\
    );\n\n  private:\n    unsigned v;\n\n  public:\n    constexpr StaticModInt() noexcept\
    \ : v(0) {}\n    explicit constexpr StaticModInt(const unsigned long long _v)\
    \ noexcept\n        : v(static_cast<unsigned>(_v % M)) {}\n\n    static constexpr\
    \ StaticModInt raw(const unsigned _v) noexcept {\n        StaticModInt res;\n\
    \        res.v = _v;\n\n        return res;\n    }\n\n    static constexpr unsigned\
    \ mod() noexcept { return M; }\n\n    constexpr unsigned val() const noexcept\
    \ { return v; }\n\n    friend constexpr bool operator==(const StaticModInt& lhs,\n\
    \                                     const StaticModInt& rhs) noexcept {\n  \
    \      return lhs.v == rhs.v;\n    }\n\n    friend constexpr bool operator!=(const\
    \ StaticModInt& lhs,\n                                     const StaticModInt&\
    \ rhs) noexcept {\n        return lhs.v != rhs.v;\n    }\n\n    constexpr StaticModInt&\
    \ operator+=(const StaticModInt& rhs) noexcept {\n        v += rhs.val();\n  \
    \      if (M <= v) {\n            v -= M;\n        }\n\n        return *this;\n\
    \    }\n\n    constexpr StaticModInt& operator-=(const StaticModInt& rhs) noexcept\
    \ {\n        if (v < rhs.val()) {\n            v += M;\n        }\n        v -=\
    \ rhs.val();\n\n        return *this;\n    }\n\n    constexpr StaticModInt& operator*=(const\
    \ StaticModInt& rhs) noexcept {\n        v = static_cast<unsigned>(\n        \
    \    (static_cast<unsigned long long>(v) * rhs.val()) % M);\n\n        return\
    \ *this;\n    }\n\n    constexpr StaticModInt& operator/=(const StaticModInt&\
    \ rhs) noexcept {\n        assert(rhs.val() != 0);\n\n        return *this *=\
    \ rhs.inv();\n    }\n\n    friend constexpr StaticModInt operator+(const StaticModInt&\
    \ lhs,\n                                            const StaticModInt& rhs) noexcept\
    \ {\n        return StaticModInt(lhs) += rhs;\n    }\n\n    friend constexpr StaticModInt\
    \ operator-(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) noexcept {\n        return StaticModInt(lhs) -=\
    \ rhs;\n    }\n\n    friend constexpr StaticModInt operator*(const StaticModInt&\
    \ lhs,\n                                            const StaticModInt& rhs) noexcept\
    \ {\n        return StaticModInt(lhs) *= rhs;\n    }\n\n    friend constexpr StaticModInt\
    \ operator/(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) noexcept {\n        return StaticModInt(lhs) /=\
    \ rhs;\n    }\n\n    constexpr StaticModInt pow(unsigned y) const noexcept {\n\
    \        StaticModInt res = raw(1);\n        StaticModInt x = *this;\n\n     \
    \   while (0 < y) {\n            if (y & 1U) {\n                res *= x;\n  \
    \          }\n\n            x *= x;\n            y >>= 1U;\n        }\n\n    \
    \    return res;\n    }\n\n    constexpr StaticModInt inv() const noexcept { return\
    \ pow(M - 2); }\n};\n};  // namespace ku\n"
  dependsOn: []
  isVerificationFile: false
  path: math/static_mod_int.hpp
  requiredBy: []
  timestamp: '2024-12-08 12:23:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix.test.cpp
documentation_of: math/static_mod_int.hpp
layout: document
redirect_from:
- /library/math/static_mod_int.hpp
- /library/math/static_mod_int.hpp.html
title: Static Mod Int
---
