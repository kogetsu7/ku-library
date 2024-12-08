---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Heavy Light Decomposition (HL\u5206\u89E3)"
    links: []
  bundledCode: "#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n/**\n * @brief Heavy\
    \ Light Decomposition (HL\u5206\u89E3)\n */\nclass HeavyLightDecomposition {\n\
    \  private:\n    bool init;\n    int n;\n    vector<vector<int>> g;\n    vector<int>\
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
    \    }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Heavy Light Decomposition (HL\u5206\u89E3\
    )\n */\nclass HeavyLightDecomposition {\n  private:\n    bool init;\n    int n;\n\
    \    vector<vector<int>> g;\n    vector<int> siz, par, dep, top, in, out;\n\n\
    \    void dfs_siz(int v, int p) {\n        par[v] = p;\n        for (int& nv :\
    \ g[v]) {\n            if (nv == p) {\n                if (nv == g[v].back())\
    \ break;\n                swap(nv, g[v].back());\n            }\n            dfs_siz(nv,\
    \ v);\n            siz[v] += siz[nv];\n            if (siz[nv] > siz[g[v][0]])\
    \ {\n                swap(nv, g[v][0]);\n            }\n        }\n    }\n\n \
    \   void dfs_hld(int v, int p, int& i) {\n        in[v] = i++;\n        for (int&\
    \ nv : g[v]) {\n            if (nv == p) continue;\n            dep[nv] = dep[v]\
    \ + 1;\n            if (nv == g[v][0])\n                top[nv] = top[v];\n  \
    \          else\n                top[nv] = nv;\n            dfs_hld(nv, v, i);\n\
    \        }\n        out[v] = i;\n    }\n\n  public:\n    HeavyLightDecomposition()\
    \ {}\n    HeavyLightDecomposition(const int _n)\n        : init(false),\n    \
    \      g(_n),\n          siz(_n, 1),\n          par(_n, -1),\n          dep(_n),\n\
    \          top(_n),\n          in(_n),\n          out(_n) {}\n\n    void add_edge(int\
    \ u, int v) {\n        assert(!init);\n\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n\n    void build() {\n        assert(!init);\n        init = true;\n\n\
    \        dfs_siz(0, -1);\n        int i{};\n        dfs_hld(0, -1, i);\n    }\n\
    \n    int depth(int v) const {\n        assert(init);\n\n        return dep[v];\n\
    \    }\n\n    int lca(int u, int v) const {\n        assert(init);\n\n       \
    \ while (true) {\n            if (in[u] > in[v]) swap(u, v);\n            if (top[u]\
    \ == top[v]) return u;\n            v = par[top[v]];\n        }\n    }\n\n   \
    \ void node_query(int v, const function<void(int)>& func) const {\n        assert(init);\n\
    \n        func(in[v]);\n    }\n\n    void subtree_query(int v, const function<void(int,\
    \ int)>& func) const {\n        assert(init);\n\n        func(in[v], out[v]);\n\
    \    }\n\n    void path_query(int u, int v, const function<void(int, int)>& func)\
    \ const {\n        assert(init);\n\n        while (true) {\n            if (in[u]\
    \ > in[v]) swap(u, v);\n            func(max(in[u], in[top[v]]), in[v] + 1);\n\
    \            if (top[u] == top[v]) break;\n            v = par[top[v]];\n    \
    \    }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/tree/heavy_light_decomposition.hpp
- /library/tree/heavy_light_decomposition.hpp.html
title: "Heavy Light Decomposition (HL\u5206\u89E3)"
---
