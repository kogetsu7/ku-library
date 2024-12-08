---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2426.test.cpp
    title: test/aoj/2426.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Merge Sort Tree
    links: []
  bundledCode: "#line 2 \"data_structure/merge_sort_tree.hpp\"\n\n/**\n * @brief Merge\
    \ Sort Tree\n */\ntemplate <class T> class MergeSortTree {\n  private:\n    int\
    \ n;\n    vector<vector<T>> v, s;\n\n    void update(int i) {\n        v[i].clear();\n\
    \        v[i].reserve(v[i << 1].size() + v[(i << 1) | 1].size());\n\n        merge(v[i\
    \ << 1].begin(), v[i << 1].end(), v[(i << 1) | 1].begin(),\n              v[(i\
    \ << 1) | 1].end(), back_inserter(v[i]));\n\n        s[i] = vector<T>(v[i].size()\
    \ + 1);\n        for (int j = 0; j < int(v[i].size()); j++) {\n            s[i][j\
    \ + 1] = s[i][j] + v[i][j];\n        }\n    }\n\n  public:\n    MergeSortTree(const\
    \ vector<T>& _v, const T& inf) {\n        n = 1;\n        while (n < int(_v.size()))\
    \ {\n            n <<= 1;\n        }\n\n        v = vector<vector<T>>(n * 2);\n\
    \        s = vector<vector<T>>(n * 2);\n\n        for (int i = 0; i < n; i++)\
    \ {\n            if (i < int(_v.size())) {\n                v[n + i] = vector<T>({_v[i]});\n\
    \                s[n + i] = vector<T>({T(0), _v[i]});\n            } else {\n\
    \                v[n + i] = vector<T>({inf});\n                s[n + i] = vector<T>({T(0),\
    \ inf});\n            }\n        }\n\n        for (int i = n - 1; i >= 1; i--)\
    \ {\n            update(i);\n        }\n    }\n\n    /**\n     * @brief [l, r)\u306B\
    \u542B\u307E\u308C\u308Ba\u4EE5\u4E0B\u306E\u6570\u306E\u7DCF\u548C\n     */\n\
    \    T sum(int l, int r, const T& a) const {\n        l += n;\n        r += n;\n\
    \        T res = 0;\n        while (l < r) {\n            if (l & 1) {\n     \
    \           int t = upper_bound(v[l].begin(), v[l].end(), a) - v[l].begin();\n\
    \                res += s[l][t];\n                l++;\n            }\n      \
    \      if (r & 1) {\n                r--;\n                int t = upper_bound(v[r].begin(),\
    \ v[r].end(), a) - v[r].begin();\n                res += s[r][t];\n          \
    \  }\n            l >>= 1;\n            r >>= 1;\n        }\n\n        return\
    \ res;\n    }\n\n    /**\n     * @brief [l, r)\u306B\u542B\u307E\u308C\u308Ba\u4EE5\
    \u4E0B\u306E\u6570\u306E\u500B\u6570\n     */\n    int count(int l, int r, const\
    \ T& a) const {\n        l += n;\n        r += n;\n\n        int res = 0;\n  \
    \      while (l < r) {\n            if (l & 1) {\n                int t = upper_bound(v[l].begin(),\
    \ v[l].end(), a) - v[l].begin();\n                res += t;\n                l++;\n\
    \            }\n            if (r & 1) {\n                r--;\n             \
    \   int t = upper_bound(v[r].begin(), v[r].end(), a) - v[r].begin();\n       \
    \         res += t;\n            }\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Merge Sort Tree\n */\ntemplate <class T> class\
    \ MergeSortTree {\n  private:\n    int n;\n    vector<vector<T>> v, s;\n\n   \
    \ void update(int i) {\n        v[i].clear();\n        v[i].reserve(v[i << 1].size()\
    \ + v[(i << 1) | 1].size());\n\n        merge(v[i << 1].begin(), v[i << 1].end(),\
    \ v[(i << 1) | 1].begin(),\n              v[(i << 1) | 1].end(), back_inserter(v[i]));\n\
    \n        s[i] = vector<T>(v[i].size() + 1);\n        for (int j = 0; j < int(v[i].size());\
    \ j++) {\n            s[i][j + 1] = s[i][j] + v[i][j];\n        }\n    }\n\n \
    \ public:\n    MergeSortTree(const vector<T>& _v, const T& inf) {\n        n =\
    \ 1;\n        while (n < int(_v.size())) {\n            n <<= 1;\n        }\n\n\
    \        v = vector<vector<T>>(n * 2);\n        s = vector<vector<T>>(n * 2);\n\
    \n        for (int i = 0; i < n; i++) {\n            if (i < int(_v.size())) {\n\
    \                v[n + i] = vector<T>({_v[i]});\n                s[n + i] = vector<T>({T(0),\
    \ _v[i]});\n            } else {\n                v[n + i] = vector<T>({inf});\n\
    \                s[n + i] = vector<T>({T(0), inf});\n            }\n        }\n\
    \n        for (int i = n - 1; i >= 1; i--) {\n            update(i);\n       \
    \ }\n    }\n\n    /**\n     * @brief [l, r)\u306B\u542B\u307E\u308C\u308Ba\u4EE5\
    \u4E0B\u306E\u6570\u306E\u7DCF\u548C\n     */\n    T sum(int l, int r, const T&\
    \ a) const {\n        l += n;\n        r += n;\n        T res = 0;\n        while\
    \ (l < r) {\n            if (l & 1) {\n                int t = upper_bound(v[l].begin(),\
    \ v[l].end(), a) - v[l].begin();\n                res += s[l][t];\n          \
    \      l++;\n            }\n            if (r & 1) {\n                r--;\n \
    \               int t = upper_bound(v[r].begin(), v[r].end(), a) - v[r].begin();\n\
    \                res += s[r][t];\n            }\n            l >>= 1;\n      \
    \      r >>= 1;\n        }\n\n        return res;\n    }\n\n    /**\n     * @brief\
    \ [l, r)\u306B\u542B\u307E\u308C\u308Ba\u4EE5\u4E0B\u306E\u6570\u306E\u500B\u6570\
    \n     */\n    int count(int l, int r, const T& a) const {\n        l += n;\n\
    \        r += n;\n\n        int res = 0;\n        while (l < r) {\n          \
    \  if (l & 1) {\n                int t = upper_bound(v[l].begin(), v[l].end(),\
    \ a) - v[l].begin();\n                res += t;\n                l++;\n      \
    \      }\n            if (r & 1) {\n                r--;\n                int\
    \ t = upper_bound(v[r].begin(), v[r].end(), a) - v[r].begin();\n             \
    \   res += t;\n            }\n            l >>= 1;\n            r >>= 1;\n   \
    \     }\n\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/merge_sort_tree.hpp
  requiredBy: []
  timestamp: '2024-09-11 22:00:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2426.test.cpp
documentation_of: data_structure/merge_sort_tree.hpp
layout: document
redirect_from:
- /library/data_structure/merge_sort_tree.hpp
- /library/data_structure/merge_sort_tree.hpp.html
title: Merge Sort Tree
---
