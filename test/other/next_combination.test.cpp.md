---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/next_combination.hpp
    title: Next Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2561
    links:
    - https://yukicoder.me/problems/no/2561
  bundledCode: "#line 1 \"test/other/next_combination.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/2561\"\n\n#line 2 \"other/next_combination.hpp\"\
    \n\n#include <algorithm>\n#include <iterator>\n\nnamespace ku {\n/**\n * @brief\
    \ Next Combination\n */\ntemplate <class I>\nbool NextCombination(const I& begin,\
    \ const I& end, const size_t k) {\n    const I sub = std::next(begin, k);\n\n\
    \    if (begin == end || begin == sub || end == sub) {\n        return false;\n\
    \    }\n\n    I src = sub;\n    while (begin != src) {\n        std::advance(src,\
    \ -1);\n\n        if (*src < *std::prev(end, 1)) {\n            I dst = sub;\n\
    \            while (*dst <= *src) {\n                std::advance(dst, 1);\n \
    \           }\n\n            std::iter_swap(src, dst);\n            std::rotate(std::next(src,\
    \ 1), std::next(dst, 1), end);\n            std::rotate(sub, std::next(sub, std::distance(dst,\
    \ end) - 1), end);\n\n            return true;\n        }\n    }\n\n    std::rotate(begin,\
    \ sub, end);\n\n    return false;\n}\n};  // namespace ku\n#line 4 \"test/other/next_combination.test.cpp\"\
    \n\n#include <iostream>\n#include <numeric>\n#include <vector>\n\nint main() {\n\
    int N, K;\n    std::cin >> N >> K;\n    std::vector<long long> A(N);\n    for\
    \ (int i = 0; i < N; i++) {\n        std::cin >> A[i];\n    }\n\n    std::vector<int>\
    \ id(N);\n    std::iota(id.begin(), id.end(), 0);\n\n    int ans = 0;\n    do\
    \ {\n        long long s1 = 0, s2 = 0;\n        for (int i = 0; i < K; i++) {\n\
    \            s1 = (s1 + A[id[i]]) % 998;\n            s2 = (s2 + A[id[i]]) % 998244353;\n\
    \        }\n\n        if (s2 <= s1) {\n            ans = (ans + 1) % 998;\n  \
    \      }\n    } while (ku::NextCombination(id.begin(), id.end(), K));\n\n    std::cout\
    \ << ans << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2561\"\n\n#include \"\
    ../../other/next_combination.hpp\"\n\n#include <iostream>\n#include <numeric>\n\
    #include <vector>\n\nint main() {\nint N, K;\n    std::cin >> N >> K;\n    std::vector<long\
    \ long> A(N);\n    for (int i = 0; i < N; i++) {\n        std::cin >> A[i];\n\
    \    }\n\n    std::vector<int> id(N);\n    std::iota(id.begin(), id.end(), 0);\n\
    \n    int ans = 0;\n    do {\n        long long s1 = 0, s2 = 0;\n        for (int\
    \ i = 0; i < K; i++) {\n            s1 = (s1 + A[id[i]]) % 998;\n            s2\
    \ = (s2 + A[id[i]]) % 998244353;\n        }\n\n        if (s2 <= s1) {\n     \
    \       ans = (ans + 1) % 998;\n        }\n    } while (ku::NextCombination(id.begin(),\
    \ id.end(), K));\n\n    std::cout << ans << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - other/next_combination.hpp
  isVerificationFile: true
  path: test/other/next_combination.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 12:57:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/other/next_combination.test.cpp
layout: document
redirect_from:
- /verify/test/other/next_combination.test.cpp
- /verify/test/other/next_combination.test.cpp.html
title: test/other/next_combination.test.cpp
---
