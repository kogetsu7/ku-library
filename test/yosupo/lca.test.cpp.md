---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: "Heavy Light Decomposition (HL\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\n/**\n * @brief Heavy Light Decomposition (HL\u5206\u89E3)\n */\nclass HeavyLightDecomposition\
    \ {\n  private:\n    bool init;\n    int n;\n    vector<vector<int>> g;\n    vector<int>\
    \ siz, par, dep, top, in, out;\n\n    void dfs_siz(int v, int p) {\n        par[v]\
    \ = p;\n        for (int& nv : g[v]) {\n            if (nv == p) {\n         \
    \       if (nv == g[v].back()) break;\n                swap(nv, g[v].back());\n\
    \            }\n            dfs_siz(nv, v);\n            siz[v] += siz[nv];\n\
    \            if (siz[nv] > siz[g[v][0]]) {\n                swap(nv, g[v][0]);\n\
    \            }\n        }\n    }\n\n    void dfs_hld(int v, int p, int& i) {\n\
    \        in[v] = i++;\n        for (int& nv : g[v]) {\n            if (nv == p)\
    \ continue;\n            dep[nv] = dep[v] + 1;\n            if (nv == g[v][0])\n\
    \                top[nv] = top[v];\n            else\n                top[nv]\
    \ = nv;\n            dfs_hld(nv, v, i);\n        }\n        out[v] = i;\n    }\n\
    \n  public:\n    HeavyLightDecomposition() {}\n    HeavyLightDecomposition(const\
    \ int _n)\n        : init(false),\n          g(_n),\n          siz(_n, 1),\n \
    \         par(_n, -1),\n          dep(_n),\n          top(_n),\n          in(_n),\n\
    \          out(_n) {}\n\n    void add_edge(int u, int v) {\n        assert(!init);\n\
    \n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\n    void build()\
    \ {\n        assert(!init);\n        init = true;\n\n        dfs_siz(0, -1);\n\
    \        int i{};\n        dfs_hld(0, -1, i);\n    }\n\n    int depth(int v) const\
    \ {\n        assert(init);\n\n        return dep[v];\n    }\n\n    int lca(int\
    \ u, int v) const {\n        assert(init);\n\n        while (true) {\n       \
    \     if (in[u] > in[v]) swap(u, v);\n            if (top[u] == top[v]) return\
    \ u;\n            v = par[top[v]];\n        }\n    }\n\n    void node_query(int\
    \ v, const function<void(int)>& func) const {\n        assert(init);\n\n     \
    \   func(in[v]);\n    }\n\n    void subtree_query(int v, const function<void(int,\
    \ int)>& func) const {\n        assert(init);\n\n        func(in[v], out[v]);\n\
    \    }\n\n    void path_query(int u, int v, const function<void(int, int)>& func)\
    \ const {\n        assert(init);\n\n        while (true) {\n            if (in[u]\
    \ > in[v]) swap(u, v);\n            func(max(in[u], in[top[v]]), in[v] + 1);\n\
    \            if (top[u] == top[v]) break;\n            v = par[top[v]];\n    \
    \    }\n    }\n};\n#line 7 \"test/yosupo/lca.test.cpp\"\n\nint main() {\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    HeavyLightDecomposition hld(N);\n    for (int\
    \ i = 1; i < N; i++) {\n        int p;\n        cin >> p;\n        hld.add_edge(i,\
    \ p);\n    }\n\n    hld.build();\n\n    for (; Q--;) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        cout << hld.lca(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../tree/heavy_light_decomposition.hpp\"\n\
    \nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    HeavyLightDecomposition\
    \ hld(N);\n    for (int i = 1; i < N; i++) {\n        int p;\n        cin >> p;\n\
    \        hld.add_edge(i, p);\n    }\n\n    hld.build();\n\n    for (; Q--;) {\n\
    \        int u, v;\n        cin >> u >> v;\n        cout << hld.lca(u, v) << endl;\n\
    \    }\n}\n"
  dependsOn:
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/yosupo/lca.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.test.cpp
- /verify/test/yosupo/lca.test.cpp.html
title: test/yosupo/lca.test.cpp
---
