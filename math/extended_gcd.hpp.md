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
    links: []
  bundledCode: "#line 2 \"math/extended_gcd.hpp\"\n\nnamespace Ku {\n/**\n * @brief\
    \ Extended Euclidean Algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
    \u306E\u4E92\u9664\u6CD5)\n */\ntemplate <class T> T ExtendedGCD(T a, T b, T&\
    \ x, T& y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return\
    \ a;\n    }\n\n    T res = ExtendedGCD(b, a % b, y, x);\n    y -= (a / b) * x;\n\
    \n    return res;\n}\n};  // namespace Ku\n"
  code: "#pragma once\n\nnamespace Ku {\n/**\n * @brief Extended Euclidean Algorithm\
    \ (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n\
    \ */\ntemplate <class T> T ExtendedGCD(T a, T b, T& x, T& y) {\n    if (b == 0)\
    \ {\n        x = 1;\n        y = 0;\n        return a;\n    }\n\n    T res = ExtendedGCD(b,\
    \ a % b, y, x);\n    y -= (a / b) * x;\n\n    return res;\n}\n};  // namespace\
    \ Ku\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extended_gcd.hpp
  requiredBy: []
  timestamp: '2024-12-01 13:41:40+09:00'
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
