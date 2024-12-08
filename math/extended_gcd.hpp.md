---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/extended_gcd.test.cpp
    title: test/math/extended_gcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Extended Euclidean Algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
      \u30C3\u30C9\u306E\u4E92\u9664\u6CD5)"
    links:
    - https://qiita.com/drken/items/b97ff231e43bce50199a
  bundledCode: "#line 2 \"math/extended_gcd.hpp\"\n\n#include <type_traits>\n\nnamespace\
    \ ku {\n/**\n * @brief Extended Euclidean Algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n * @note \u53C2\u8003\uFF1Ahttps://qiita.com/drken/items/b97ff231e43bce50199a\n\
    \ */\ntemplate <class T> T ExtendedGCD(T a, T b, T& x, T& y) {\n    static_assert(!std::is_floating_point_v<T>,\
    \ \"T must not be floating point\");\n\n    if (b == T(0)) {\n        x = T(1);\n\
    \        y = T(0);\n        return a;\n    }\n\n    T res = ExtendedGCD(b, a %\
    \ b, y, x);\n    y -= (a / b) * x;\n\n    return res;\n}\n};  // namespace ku\n"
  code: "#pragma once\n\n#include <type_traits>\n\nnamespace ku {\n/**\n * @brief\
    \ Extended Euclidean Algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
    \u306E\u4E92\u9664\u6CD5)\n * @note \u53C2\u8003\uFF1Ahttps://qiita.com/drken/items/b97ff231e43bce50199a\n\
    \ */\ntemplate <class T> T ExtendedGCD(T a, T b, T& x, T& y) {\n    static_assert(!std::is_floating_point_v<T>,\
    \ \"T must not be floating point\");\n\n    if (b == T(0)) {\n        x = T(1);\n\
    \        y = T(0);\n        return a;\n    }\n\n    T res = ExtendedGCD(b, a %\
    \ b, y, x);\n    y -= (a / b) * x;\n\n    return res;\n}\n};  // namespace ku\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extended_gcd.hpp
  requiredBy: []
  timestamp: '2024-12-08 15:50:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/extended_gcd.test.cpp
documentation_of: math/extended_gcd.hpp
layout: document
redirect_from:
- /library/math/extended_gcd.hpp
- /library/math/extended_gcd.hpp.html
title: "Extended Euclidean Algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
  \u306E\u4E92\u9664\u6CD5)"
---
