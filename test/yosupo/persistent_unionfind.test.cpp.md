---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/rollback_union_find.hpp
    title: "Rollback Union Find (Rollback\u4ED8\u304DUnion Find)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"data_structure/rollback_union_find.hpp\"\n\n\
    /**\n * @brief Rollback Union Find (Rollback\u4ED8\u304DUnion Find)\n */\nclass\
    \ RollbackUnionFind {\n  private:\n    int n, comp;\n    vector<int> par;\n  \
    \  stack<pair<int, int>> his;\n\n  public:\n    RollbackUnionFind() : RollbackUnionFind(0)\
    \ {}\n    RollbackUnionFind(const int _n) : n(_n), comp(_n), par(_n, -1), his()\
    \ {}\n\n    int size(int x) const { return -par[leader(x)]; }\n\n    int component()\
    \ const { return comp; }\n\n    int leader(int x) const {\n        if (par[x]\
    \ < 0) return x;\n        return leader(par[x]);\n    }\n\n    bool same(int x,\
    \ int y) const { return leader(x) == leader(y); }\n\n    bool merge(int x, int\
    \ y) {\n        x = leader(x), y = leader(y);\n        his.push(make_pair(x, par[x]));\n\
    \        his.push(make_pair(y, par[y]));\n        if (x == y) return false;\n\
    \        comp--;\n        if (par[x] > par[y]) swap(x, y);\n        par[x] +=\
    \ par[y];\n        par[y] = x;\n        return true;\n    }\n\n    bool undo()\
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
    \ res;\n    }\n};\n#line 7 \"test/yosupo/persistent_unionfind.test.cpp\"\n\nint\
    \ main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<vector<int>> g(Q + 1);\n\
    \    vector<int> t(Q), k(Q), u(Q), v(Q);\n    for (int i = 0; i < Q; i++) {\n\
    \        cin >> t[i] >> k[i] >> u[i] >> v[i];\n        g[k[i] + 1].push_back(i\
    \ + 1);\n    }\n\n    RollbackUnionFind uf(N);\n    vector<bool> ans(Q);\n   \
    \ auto dfs = [&](auto& self, int now) -> void {\n        now--;\n        if (now\
    \ != -1) {\n            if (t[now] == 0) {\n                uf.merge(u[now], v[now]);\n\
    \            } else {\n                ans[now] = uf.same(u[now], v[now]);\n \
    \           }\n        }\n        for (int nxt : g[now + 1]) {\n            self(self,\
    \ nxt);\n        }\n        if (now != -1 && t[now] == 0) {\n            uf.undo();\n\
    \        }\n    };\n\n    dfs(dfs, 0);\n\n    for (int i = 0; i < Q; i++) {\n\
    \        if (t[i] == 1) {\n            cout << (ans[i] ? 1 : 0) << endl;\n   \
    \     }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/rollback_union_find.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<vector<int>> g(Q\
    \ + 1);\n    vector<int> t(Q), k(Q), u(Q), v(Q);\n    for (int i = 0; i < Q; i++)\
    \ {\n        cin >> t[i] >> k[i] >> u[i] >> v[i];\n        g[k[i] + 1].push_back(i\
    \ + 1);\n    }\n\n    RollbackUnionFind uf(N);\n    vector<bool> ans(Q);\n   \
    \ auto dfs = [&](auto& self, int now) -> void {\n        now--;\n        if (now\
    \ != -1) {\n            if (t[now] == 0) {\n                uf.merge(u[now], v[now]);\n\
    \            } else {\n                ans[now] = uf.same(u[now], v[now]);\n \
    \           }\n        }\n        for (int nxt : g[now + 1]) {\n            self(self,\
    \ nxt);\n        }\n        if (now != -1 && t[now] == 0) {\n            uf.undo();\n\
    \        }\n    };\n\n    dfs(dfs, 0);\n\n    for (int i = 0; i < Q; i++) {\n\
    \        if (t[i] == 1) {\n            cout << (ans[i] ? 1 : 0) << endl;\n   \
    \     }\n    }\n}\n"
  dependsOn:
  - data_structure/rollback_union_find.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.test.cpp
- /verify/test/yosupo/persistent_unionfind.test.cpp.html
title: test/yosupo/persistent_unionfind.test.cpp
---
