---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/other/next_combination.test.cpp
    title: test/other/next_combination.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Next Combination
    links: []
  bundledCode: "#line 2 \"other/next_combination.hpp\"\n\n#include <algorithm>\n#include\
    \ <iterator>\n\nnamespace ku {\n/**\n * @brief Next Combination\n */\ntemplate\
    \ <class I>\nbool NextCombination(const I& begin, const I& end, const size_t k)\
    \ {\n    const I sub = std::next(begin, k);\n\n    if (begin == end || begin ==\
    \ sub || end == sub) {\n        return false;\n    }\n\n    I src = sub;\n   \
    \ while (begin != src) {\n        std::advance(src, -1);\n\n        if (*src <\
    \ *std::prev(end, 1)) {\n            I dst = sub;\n            while (*dst <=\
    \ *src) {\n                std::advance(dst, 1);\n            }\n\n          \
    \  std::iter_swap(src, dst);\n            std::rotate(std::next(src, 1), std::next(dst,\
    \ 1), end);\n            std::rotate(sub, std::next(sub, std::distance(dst, end)\
    \ - 1), end);\n\n            return true;\n        }\n    }\n\n    std::rotate(begin,\
    \ sub, end);\n\n    return false;\n}\n};  // namespace ku\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <iterator>\n\nnamespace ku\
    \ {\n/**\n * @brief Next Combination\n */\ntemplate <class I>\nbool NextCombination(const\
    \ I& begin, const I& end, const size_t k) {\n    const I sub = std::next(begin,\
    \ k);\n\n    if (begin == end || begin == sub || end == sub) {\n        return\
    \ false;\n    }\n\n    I src = sub;\n    while (begin != src) {\n        std::advance(src,\
    \ -1);\n\n        if (*src < *std::prev(end, 1)) {\n            I dst = sub;\n\
    \            while (*dst <= *src) {\n                std::advance(dst, 1);\n \
    \           }\n\n            std::iter_swap(src, dst);\n            std::rotate(std::next(src,\
    \ 1), std::next(dst, 1), end);\n            std::rotate(sub, std::next(sub, std::distance(dst,\
    \ end) - 1), end);\n\n            return true;\n        }\n    }\n\n    std::rotate(begin,\
    \ sub, end);\n\n    return false;\n}\n};  // namespace ku\n"
  dependsOn: []
  isVerificationFile: false
  path: other/next_combination.hpp
  requiredBy: []
  timestamp: '2024-12-08 12:57:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/other/next_combination.test.cpp
documentation_of: other/next_combination.hpp
layout: document
redirect_from:
- /library/other/next_combination.hpp
- /library/other/next_combination.hpp.html
title: Next Combination
---
