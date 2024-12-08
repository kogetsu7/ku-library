---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <iostream>\n#include <vector>\nusing namespace std;\n\n#line 2 \"\
    data_structure/union_find.hpp\"\n\nnamespace _UnionFind {\nusing S = bool;\nS\
    \ op(S a, S b) { return a ^ b; }\nS e() { return false; }\n};  // namespace _UnionFind\n\
    \n/**\n * @brief Union Find\n */\ntemplate <class S = _UnionFind::S,\n       \
    \   S (*op)(S, S) = _UnionFind::op,\n          S (*e)() = _UnionFind::e>\nclass\
    \ UnionFind {\n  private:\n    int n, siz;\n    vector<int> par;\n    vector<S>\
    \ val;\n\n  public:\n    UnionFind(const int _n = 0) : n(_n), siz(_n), par(_n,\
    \ -1), val(_n, e()) {}\n\n    int size() const { return siz; }\n\n    int size(int\
    \ x) { return -par[leader(x)]; }\n\n    int leader(int x) {\n        if (par[x]\
    \ < 0) return x;\n        return par[x] = leader(par[x]);\n    }\n\n    bool same(int\
    \ x, int y) { return leader(x) == leader(y); }\n\n    bool merge(int x, int y)\
    \ {\n        x = leader(x);\n        y = leader(y);\n        if (x == y) return\
    \ false;\n\n        if (par[x] > par[y]) swap(x, y);\n\n        siz--;\n     \
    \   par[x] += par[y];\n        par[y] = x;\n        val[x] = op(val[x], val[y]);\n\
    \n        return true;\n    }\n\n    vector<vector<int>> groups() {\n        vector<vector<int>>\
    \ mem(n), res;\n\n        for (int i = 0; i < n; i++) {\n            mem[leader(i)].emplace_back(i);\n\
    \        }\n\n        for (int i = 0; i < n; i++) {\n            if (!mem[i].empty())\
    \ {\n                res.emplace_back(mem[i]);\n            }\n        }\n\n \
    \       return res;\n    }\n\n    void set(int x, S v) {\n        val[leader(x)]\
    \ = v;\n\n        return;\n    }\n\n    S get(int x) { return val[leader(x)];\
    \ }\n};\n#line 8 \"test/yosupo/unionfind.test.cpp\"\n\nint main() {\n    int N,\
    \ Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n    for (; Q--;) {\n       \
    \ int t, u, v;\n        cin >> t >> u >> v;\n        if (t == 0) {\n         \
    \   uf.merge(u, v);\n        } else {\n            cout << (uf.same(u, v) ? 1\
    \ : 0) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include <vector>\nusing namespace std;\n\n#include \"../../data_structure/union_find.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n\
    \    for (; Q--;) {\n        int t, u, v;\n        cin >> t >> u >> v;\n     \
    \   if (t == 0) {\n            uf.merge(u, v);\n        } else {\n           \
    \ cout << (uf.same(u, v) ? 1 : 0) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - data_structure/union_find.hpp
  isVerificationFile: true
  path: test/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-09-21 23:31:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/unionfind.test.cpp
- /verify/test/yosupo/unionfind.test.cpp.html
title: test/yosupo/unionfind.test.cpp
---
