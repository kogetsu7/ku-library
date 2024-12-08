---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/weighted_union_find.hpp
    title: "Weighted Union Find (\u91CD\u307F\u4ED8\u304DUnion Find)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/aoj/DSL_1_B.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data_structure/weighted_union_find.hpp\"\
    \n\n/**\n * @brief Weighted Union Find (\u91CD\u307F\u4ED8\u304DUnion Find)\n\
    \ */\ntemplate <class T> class WeightedUnionFind {\n  private:\n    int n, comp;\n\
    \    vector<int> par, rank;\n    vector<T> wei;\n\n  public:\n    WeightedUnionFind(const\
    \ int _n = 0, const T _e = 0)\n        : n(_n), comp(_n), par(_n, -1), rank(_n),\
    \ wei(n, _e) {}\n\n    int component() const { return comp; }\n\n    int size(int\
    \ x) { return -par[leader(x)]; }\n\n    int leader(int x) {\n        if (par[x]\
    \ < 0) return x;\n        int rx = leader(par[x]);\n        wei[x] += wei[par[x]];\n\
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
    \    }\n};\n#line 8 \"test/aoj/DSL_1_B.test.cpp\"\n\nint main() {\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    WeightedUnionFind<int> uf(N);\n    for (; Q--;)\
    \ {\n        int t, x, y;\n        cin >> t >> x >> y;\n        if (t == 0) {\n\
    \            int z;\n            cin >> z;\n            uf.merge(x, y, z);\n \
    \       } else {\n            if (uf.same(x, y)) {\n                cout << uf.diff(x,\
    \ y) << endl;\n            } else {\n                cout << '?' << endl;\n  \
    \          }\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/weighted_union_find.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    WeightedUnionFind<int>\
    \ uf(N);\n    for (; Q--;) {\n        int t, x, y;\n        cin >> t >> x >> y;\n\
    \        if (t == 0) {\n            int z;\n            cin >> z;\n          \
    \  uf.merge(x, y, z);\n        } else {\n            if (uf.same(x, y)) {\n  \
    \              cout << uf.diff(x, y) << endl;\n            } else {\n        \
    \        cout << '?' << endl;\n            }\n        }\n    }\n}\n"
  dependsOn:
  - data_structure/weighted_union_find.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_B.test.cpp
- /verify/test/aoj/DSL_1_B.test.cpp.html
title: test/aoj/DSL_1_B.test.cpp
---
