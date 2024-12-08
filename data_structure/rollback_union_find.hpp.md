---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Rollback Union Find (Rollback\u4ED8\u304DUnion Find)"
    links: []
  bundledCode: "#line 2 \"data_structure/rollback_union_find.hpp\"\n\n/**\n * @brief\
    \ Rollback Union Find (Rollback\u4ED8\u304DUnion Find)\n */\nclass RollbackUnionFind\
    \ {\n  private:\n    int n, comp;\n    vector<int> par;\n    stack<pair<int, int>>\
    \ his;\n\n  public:\n    RollbackUnionFind() : RollbackUnionFind(0) {}\n    RollbackUnionFind(const\
    \ int _n) : n(_n), comp(_n), par(_n, -1), his() {}\n\n    int size(int x) const\
    \ { return -par[leader(x)]; }\n\n    int component() const { return comp; }\n\n\
    \    int leader(int x) const {\n        if (par[x] < 0) return x;\n        return\
    \ leader(par[x]);\n    }\n\n    bool same(int x, int y) const { return leader(x)\
    \ == leader(y); }\n\n    bool merge(int x, int y) {\n        x = leader(x), y\
    \ = leader(y);\n        his.push(make_pair(x, par[x]));\n        his.push(make_pair(y,\
    \ par[y]));\n        if (x == y) return false;\n        comp--;\n        if (par[x]\
    \ > par[y]) swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n    \
    \    return true;\n    }\n\n    bool undo() {\n        if (his.empty()) return\
    \ false;\n        vector<int> x(2);\n        for (int i = 0; i < 2; i++) {\n \
    \           auto [v, p] = his.top();\n            his.pop();\n            x[i]\
    \ = v;\n            par[v] = p;\n        }\n        if (x[0] != x[1]) comp++;\n\
    \        return true;\n    }\n\n    void snapshot() {\n        while (!his.empty())\
    \ his.pop();\n    }\n\n    void rollback() {\n        while (!his.empty()) undo();\n\
    \    }\n\n    vector<vector<int>> groups() const {\n        vector<vector<int>>\
    \ member(n), res;\n        for (int i = 0; i < n; i++) {\n            member[leader(i)].push_back(i);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            if (!member[i].empty())\
    \ {\n                res.push_back(member[i]);\n            }\n        }\n   \
    \     return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Rollback Union Find (Rollback\u4ED8\u304D\
    Union Find)\n */\nclass RollbackUnionFind {\n  private:\n    int n, comp;\n  \
    \  vector<int> par;\n    stack<pair<int, int>> his;\n\n  public:\n    RollbackUnionFind()\
    \ : RollbackUnionFind(0) {}\n    RollbackUnionFind(const int _n) : n(_n), comp(_n),\
    \ par(_n, -1), his() {}\n\n    int size(int x) const { return -par[leader(x)];\
    \ }\n\n    int component() const { return comp; }\n\n    int leader(int x) const\
    \ {\n        if (par[x] < 0) return x;\n        return leader(par[x]);\n    }\n\
    \n    bool same(int x, int y) const { return leader(x) == leader(y); }\n\n   \
    \ bool merge(int x, int y) {\n        x = leader(x), y = leader(y);\n        his.push(make_pair(x,\
    \ par[x]));\n        his.push(make_pair(y, par[y]));\n        if (x == y) return\
    \ false;\n        comp--;\n        if (par[x] > par[y]) swap(x, y);\n        par[x]\
    \ += par[y];\n        par[y] = x;\n        return true;\n    }\n\n    bool undo()\
    \ {\n        if (his.empty()) return false;\n        vector<int> x(2);\n     \
    \   for (int i = 0; i < 2; i++) {\n            auto [v, p] = his.top();\n    \
    \        his.pop();\n            x[i] = v;\n            par[v] = p;\n        }\n\
    \        if (x[0] != x[1]) comp++;\n        return true;\n    }\n\n    void snapshot()\
    \ {\n        while (!his.empty()) his.pop();\n    }\n\n    void rollback() {\n\
    \        while (!his.empty()) undo();\n    }\n\n    vector<vector<int>> groups()\
    \ const {\n        vector<vector<int>> member(n), res;\n        for (int i = 0;\
    \ i < n; i++) {\n            member[leader(i)].push_back(i);\n        }\n    \
    \    for (int i = 0; i < n; i++) {\n            if (!member[i].empty()) {\n  \
    \              res.push_back(member[i]);\n            }\n        }\n        return\
    \ res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/rollback_union_find.hpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: data_structure/rollback_union_find.hpp
layout: document
redirect_from:
- /library/data_structure/rollback_union_find.hpp
- /library/data_structure/rollback_union_find.hpp.html
title: "Rollback Union Find (Rollback\u4ED8\u304DUnion Find)"
---
