---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Weighted Union Find (\u91CD\u307F\u4ED8\u304DUnion Find)"
    links: []
  bundledCode: "#line 2 \"data_structure/weighted_union_find.hpp\"\n\n/**\n * @brief\
    \ Weighted Union Find (\u91CD\u307F\u4ED8\u304DUnion Find)\n */\ntemplate <class\
    \ T> class WeightedUnionFind {\n  private:\n    int n, comp;\n    vector<int>\
    \ par, rank;\n    vector<T> wei;\n\n  public:\n    WeightedUnionFind(const int\
    \ _n = 0, const T _e = 0)\n        : n(_n), comp(_n), par(_n, -1), rank(_n), wei(n,\
    \ _e) {}\n\n    int component() const { return comp; }\n\n    int size(int x)\
    \ { return -par[leader(x)]; }\n\n    int leader(int x) {\n        if (par[x] <\
    \ 0) return x;\n        int rx = leader(par[x]);\n        wei[x] += wei[par[x]];\n\
    \        return par[x] = rx;\n    }\n\n    T weight(int x) {\n        leader(x);\n\
    \        return wei[x];\n    }\n\n    bool same(int x, int y) { return leader(x)\
    \ == leader(y); }\n\n    bool merge(int x, int y, T w) {\n        w += weight(x)\
    \ - weight(y);\n        x = leader(x), y = leader(y);\n        if (x == y) return\
    \ false;\n        comp--;\n        if (rank[x] < rank[y]) {\n            swap(x,\
    \ y);\n            w = -w;\n        }\n        if (rank[x] == rank[y]) rank[x]++;\n\
    \        par[x] += par[y];\n        par[y] = x;\n        wei[y] = w;\n       \
    \ return true;\n    }\n\n    T diff(int x, int y) {\n        assert(same(x, y));\n\
    \        return weight(y) - weight(x);\n    }\n\n    vector<vector<int>> groups()\
    \ {\n        vector<vector<int>> member(n), res;\n        for (int i = 0; i <\
    \ n; i++) {\n            member[leader(i)].push_back(i);\n        }\n        for\
    \ (int i = 0; i < n; i++) {\n            if (!member[i].empty()) {\n         \
    \       res.push_back(member[i]);\n            }\n        }\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Weighted Union Find (\u91CD\u307F\u4ED8\u304D\
    Union Find)\n */\ntemplate <class T> class WeightedUnionFind {\n  private:\n \
    \   int n, comp;\n    vector<int> par, rank;\n    vector<T> wei;\n\n  public:\n\
    \    WeightedUnionFind(const int _n = 0, const T _e = 0)\n        : n(_n), comp(_n),\
    \ par(_n, -1), rank(_n), wei(n, _e) {}\n\n    int component() const { return comp;\
    \ }\n\n    int size(int x) { return -par[leader(x)]; }\n\n    int leader(int x)\
    \ {\n        if (par[x] < 0) return x;\n        int rx = leader(par[x]);\n   \
    \     wei[x] += wei[par[x]];\n        return par[x] = rx;\n    }\n\n    T weight(int\
    \ x) {\n        leader(x);\n        return wei[x];\n    }\n\n    bool same(int\
    \ x, int y) { return leader(x) == leader(y); }\n\n    bool merge(int x, int y,\
    \ T w) {\n        w += weight(x) - weight(y);\n        x = leader(x), y = leader(y);\n\
    \        if (x == y) return false;\n        comp--;\n        if (rank[x] < rank[y])\
    \ {\n            swap(x, y);\n            w = -w;\n        }\n        if (rank[x]\
    \ == rank[y]) rank[x]++;\n        par[x] += par[y];\n        par[y] = x;\n   \
    \     wei[y] = w;\n        return true;\n    }\n\n    T diff(int x, int y) {\n\
    \        assert(same(x, y));\n        return weight(y) - weight(x);\n    }\n\n\
    \    vector<vector<int>> groups() {\n        vector<vector<int>> member(n), res;\n\
    \        for (int i = 0; i < n; i++) {\n            member[leader(i)].push_back(i);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            if (!member[i].empty())\
    \ {\n                res.push_back(member[i]);\n            }\n        }\n   \
    \     return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_B.test.cpp
documentation_of: data_structure/weighted_union_find.hpp
layout: document
redirect_from:
- /library/data_structure/weighted_union_find.hpp
- /library/data_structure/weighted_union_find.hpp.html
title: "Weighted Union Find (\u91CD\u307F\u4ED8\u304DUnion Find)"
---
