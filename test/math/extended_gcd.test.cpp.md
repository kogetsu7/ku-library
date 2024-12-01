---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extended_gcd.hpp
    title: "Extended Euclidean Algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
      \u30C9\u306E\u4E92\u9664\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/math/extended_gcd.test.cpp\"\n#define PROBLEM \\\n\
    \    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\n\n\
    #include <iostream>\n\n#line 2 \"math/extended_gcd.hpp\"\n\nnamespace Ku {\n/**\n\
    \ * @brief Extended Euclidean Algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
    \u30C9\u306E\u4E92\u9664\u6CD5)\n */\ntemplate <class T> T ExtendedGCD(T a, T\
    \ b, T& x, T& y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n      \
    \  return a;\n    }\n\n    T res = ExtendedGCD(b, a % b, y, x);\n    y -= (a /\
    \ b) * x;\n\n    return res;\n}\n};  // namespace Ku\n#line 7 \"test/math/extended_gcd.test.cpp\"\
    \n\nint main() {\n    long long a, b;\n    std::cin >> a >> b;\n\n    long long\
    \ x, y;\n    Ku::ExtendedGCD(a, b, x, y);\n\n    std::cout << x << \" \" << y\
    \ << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n\n#include \"../../math/extended_gcd.hpp\"\n\nint main()\
    \ {\n    long long a, b;\n    std::cin >> a >> b;\n\n    long long x, y;\n   \
    \ Ku::ExtendedGCD(a, b, x, y);\n\n    std::cout << x << \" \" << y << \"\\n\"\
    ;\n\n    return 0;\n}\n"
  dependsOn:
  - math/extended_gcd.hpp
  isVerificationFile: true
  path: test/math/extended_gcd.test.cpp
  requiredBy: []
  timestamp: '2024-12-01 13:41:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/extended_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/math/extended_gcd.test.cpp
- /verify/test/math/extended_gcd.test.cpp.html
title: test/math/extended_gcd.test.cpp
---
