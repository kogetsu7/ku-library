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
  bundledCode: "#line 2 \"math/static_mod_int.hpp\"\n\nnamespace Ku {\n/**\n * @brief\
    \ Static Mod Int\n */\ntemplate <unsigned M> class StaticModInt {\n    static_assert(0\
    \ < M, \"M must be positive.\");\n\n  private:\n    unsigned v;\n\n  public:\n\
    \    constexpr StaticModInt() : StaticModInt(0) {}\n    constexpr explicit StaticModInt(const\
    \ unsigned long long _v)\n        : v(static_cast<unsigned>(_v % M)) {}\n\n  \
    \  constexpr static unsigned mod() { return M; }\n\n    constexpr unsigned val()\
    \ const { return v; }\n\n    constexpr friend bool operator==(const StaticModInt&\
    \ lhs,\n                                     const StaticModInt& rhs) {\n    \
    \    return lhs.v == rhs.v;\n    }\n\n    constexpr friend bool operator!=(const\
    \ StaticModInt& lhs,\n                                     const StaticModInt&\
    \ rhs) {\n        return lhs.v != rhs.v;\n    }\n\n    constexpr StaticModInt&\
    \ operator+=(const StaticModInt& rhs) {\n        v += rhs.val();\n        if (M\
    \ <= v) {\n            v -= M;\n        }\n\n        return *this;\n    }\n\n\
    \    constexpr StaticModInt& operator-=(const StaticModInt& rhs) {\n        if\
    \ (v < rhs.val()) {\n            v += M;\n        }\n        v -= rhs.val();\n\
    \n        return *this;\n    }\n\n    constexpr StaticModInt& operator*=(const\
    \ StaticModInt& rhs) {\n        v = static_cast<unsigned>(\n            (static_cast<unsigned\
    \ long long>(v) * rhs.val()) % M);\n\n        return *this;\n    }\n\n    constexpr\
    \ StaticModInt& operator/=(const StaticModInt& rhs) {\n        return *this *=\
    \ rhs.inv();\n    }\n\n    constexpr friend StaticModInt operator+(const StaticModInt&\
    \ lhs,\n                                            const StaticModInt& rhs) {\n\
    \        return StaticModInt(lhs) += rhs;\n    }\n\n    constexpr friend StaticModInt\
    \ operator-(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) {\n        return StaticModInt(lhs) -= rhs;\n \
    \   }\n\n    constexpr friend StaticModInt operator*(const StaticModInt& lhs,\n\
    \                                            const StaticModInt& rhs) {\n    \
    \    return StaticModInt(lhs) *= rhs;\n    }\n\n    constexpr friend StaticModInt\
    \ operator/(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) {\n        return StaticModInt(lhs) /= rhs;\n \
    \   }\n\n    constexpr StaticModInt pow(unsigned y) const {\n        StaticModInt\
    \ res{1U}, x{*this};\n        while (0 < y) {\n            if (y & 1U) {\n   \
    \             res *= x;\n            }\n\n            x *= x;\n            y >>=\
    \ 1U;\n        }\n\n        return res;\n    }\n\n    constexpr StaticModInt inv()\
    \ const { return pow(M - 2); }\n};\n};  // namespace Ku\n"
  code: "#pragma once\n\nnamespace Ku {\n/**\n * @brief Static Mod Int\n */\ntemplate\
    \ <unsigned M> class StaticModInt {\n    static_assert(0 < M, \"M must be positive.\"\
    );\n\n  private:\n    unsigned v;\n\n  public:\n    constexpr StaticModInt() :\
    \ StaticModInt(0) {}\n    constexpr explicit StaticModInt(const unsigned long\
    \ long _v)\n        : v(static_cast<unsigned>(_v % M)) {}\n\n    constexpr static\
    \ unsigned mod() { return M; }\n\n    constexpr unsigned val() const { return\
    \ v; }\n\n    constexpr friend bool operator==(const StaticModInt& lhs,\n    \
    \                                 const StaticModInt& rhs) {\n        return lhs.v\
    \ == rhs.v;\n    }\n\n    constexpr friend bool operator!=(const StaticModInt&\
    \ lhs,\n                                     const StaticModInt& rhs) {\n    \
    \    return lhs.v != rhs.v;\n    }\n\n    constexpr StaticModInt& operator+=(const\
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
    \    return StaticModInt(lhs) += rhs;\n    }\n\n    constexpr friend StaticModInt\
    \ operator-(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) {\n        return StaticModInt(lhs) -= rhs;\n \
    \   }\n\n    constexpr friend StaticModInt operator*(const StaticModInt& lhs,\n\
    \                                            const StaticModInt& rhs) {\n    \
    \    return StaticModInt(lhs) *= rhs;\n    }\n\n    constexpr friend StaticModInt\
    \ operator/(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) {\n        return StaticModInt(lhs) /= rhs;\n \
    \   }\n\n    constexpr StaticModInt pow(unsigned y) const {\n        StaticModInt\
    \ res{1U}, x{*this};\n        while (0 < y) {\n            if (y & 1U) {\n   \
    \             res *= x;\n            }\n\n            x *= x;\n            y >>=\
    \ 1U;\n        }\n\n        return res;\n    }\n\n    constexpr StaticModInt inv()\
    \ const { return pow(M - 2); }\n};\n};  // namespace Ku\n"
  dependsOn: []
  isVerificationFile: false
  path: math/static_mod_int.hpp
  requiredBy: []
  timestamp: '2024-12-01 16:12:45+09:00'
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
