---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"data_structure/union_find.hpp\"\n\nnamespace _UnionFind\
    \ {\nusing S = bool;\nS op(S a, S b) { return a ^ b; }\nS e() { return false;\
    \ }\n};  // namespace _UnionFind\n\n/**\n * @brief Union Find\n */\ntemplate <class\
    \ S = _UnionFind::S,\n          S (*op)(S, S) = _UnionFind::op,\n          S (*e)()\
    \ = _UnionFind::e>\nclass UnionFind {\n  private:\n    int n, siz;\n    vector<int>\
    \ par;\n    vector<S> val;\n\n  public:\n    UnionFind(const int _n = 0) : n(_n),\
    \ siz(_n), par(_n, -1), val(_n, e()) {}\n\n    int size() const { return siz;\
    \ }\n\n    int size(int x) { return -par[leader(x)]; }\n\n    int leader(int x)\
    \ {\n        if (par[x] < 0) return x;\n        return par[x] = leader(par[x]);\n\
    \    }\n\n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n \
    \   bool merge(int x, int y) {\n        x = leader(x);\n        y = leader(y);\n\
    \        if (x == y) return false;\n\n        if (par[x] > par[y]) swap(x, y);\n\
    \n        siz--;\n        par[x] += par[y];\n        par[y] = x;\n        val[x]\
    \ = op(val[x], val[y]);\n\n        return true;\n    }\n\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> mem(n), res;\n\n        for (int i =\
    \ 0; i < n; i++) {\n            mem[leader(i)].emplace_back(i);\n        }\n\n\
    \        for (int i = 0; i < n; i++) {\n            if (!mem[i].empty()) {\n \
    \               res.emplace_back(mem[i]);\n            }\n        }\n\n      \
    \  return res;\n    }\n\n    void set(int x, S v) {\n        val[leader(x)] =\
    \ v;\n\n        return;\n    }\n\n    S get(int x) { return val[leader(x)]; }\n\
    };\n"
  code: "#pragma once\n\nnamespace _UnionFind {\nusing S = bool;\nS op(S a, S b) {\
    \ return a ^ b; }\nS e() { return false; }\n};  // namespace _UnionFind\n\n/**\n\
    \ * @brief Union Find\n */\ntemplate <class S = _UnionFind::S,\n          S (*op)(S,\
    \ S) = _UnionFind::op,\n          S (*e)() = _UnionFind::e>\nclass UnionFind {\n\
    \  private:\n    int n, siz;\n    vector<int> par;\n    vector<S> val;\n\n  public:\n\
    \    UnionFind(const int _n = 0) : n(_n), siz(_n), par(_n, -1), val(_n, e()) {}\n\
    \n    int size() const { return siz; }\n\n    int size(int x) { return -par[leader(x)];\
    \ }\n\n    int leader(int x) {\n        if (par[x] < 0) return x;\n        return\
    \ par[x] = leader(par[x]);\n    }\n\n    bool same(int x, int y) { return leader(x)\
    \ == leader(y); }\n\n    bool merge(int x, int y) {\n        x = leader(x);\n\
    \        y = leader(y);\n        if (x == y) return false;\n\n        if (par[x]\
    \ > par[y]) swap(x, y);\n\n        siz--;\n        par[x] += par[y];\n       \
    \ par[y] = x;\n        val[x] = op(val[x], val[y]);\n\n        return true;\n\
    \    }\n\n    vector<vector<int>> groups() {\n        vector<vector<int>> mem(n),\
    \ res;\n\n        for (int i = 0; i < n; i++) {\n            mem[leader(i)].emplace_back(i);\n\
    \        }\n\n        for (int i = 0; i < n; i++) {\n            if (!mem[i].empty())\
    \ {\n                res.emplace_back(mem[i]);\n            }\n        }\n\n \
    \       return res;\n    }\n\n    void set(int x, S v) {\n        val[leader(x)]\
    \ = v;\n\n        return;\n    }\n\n    S get(int x) { return val[leader(x)];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2024-09-21 23:31:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind.test.cpp
documentation_of: data_structure/union_find.hpp
layout: document
redirect_from:
- /library/data_structure/union_find.hpp
- /library/data_structure/union_find.hpp.html
title: Union Find
---
