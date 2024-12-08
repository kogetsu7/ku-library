---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Low Link
    links: []
  bundledCode: "#line 2 \"graph/low_link.hpp\"\n\n/**\n * @brief Low Link\n */\nclass\
    \ LowLink {\n  private:\n    bool init;\n    int n, comp;\n    vector<vector<int>>\
    \ g;\n    vector<bool> seen;\n    vector<int> ord, low, art;\n    set<pair<int,\
    \ int>> bri;\n\n    void dfs(int v, int p, int& i) {\n        seen[v] = true;\n\
    \        ord[v] = low[v] = i++;\n        for (const int& nv : g[v]) {\n      \
    \      if (seen[nv]) {\n                if (nv != p) {\n                    low[v]\
    \ = min(low[v], ord[nv]);\n                }\n            } else {\n         \
    \       dfs(nv, v, i);\n                low[v] = min(low[v], low[nv]);\n     \
    \           if (ord[v] <= low[nv]) art[v]++;\n                if (ord[v] < low[nv])\n\
    \                    bri.insert(make_pair(min(v, nv), max(v, nv)));\n        \
    \    }\n        }\n        if (p == -1) art[v]--;\n    }\n\n  public:\n    LowLink()\
    \ {}\n    LowLink(const int _n)\n        : init(false),\n          n(_n),\n  \
    \        comp(0),\n          g(_n),\n          seen(_n),\n          ord(_n),\n\
    \          low(_n),\n          art(_n) {}\n\n    void add_edge(int u, int v) {\n\
    \        assert(!init);\n\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n\n    void build() {\n        assert(!init);\n        init = true;\n\n\
    \        for (int v = 0; v < n; v++)\n            if (!seen[v]) {\n          \
    \      comp++;\n                int i{};\n                dfs(v, -1, i);\n   \
    \         }\n    }\n\n    int component() const {\n        assert(init);\n\n \
    \       return comp;\n    }\n\n    int get_art(int v) const {\n        assert(init);\n\
    \n        return art[v];\n    }\n\n    bool is_art(int v) const {\n        assert(init);\n\
    \n        return 0 < get_art(v);\n    }\n\n    bool is_bridge(int u, int v) const\
    \ {\n        assert(init);\n\n        return bri.count(make_pair(min(u, v), max(u,\
    \ v)));\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Low Link\n */\nclass LowLink {\n  private:\n\
    \    bool init;\n    int n, comp;\n    vector<vector<int>> g;\n    vector<bool>\
    \ seen;\n    vector<int> ord, low, art;\n    set<pair<int, int>> bri;\n\n    void\
    \ dfs(int v, int p, int& i) {\n        seen[v] = true;\n        ord[v] = low[v]\
    \ = i++;\n        for (const int& nv : g[v]) {\n            if (seen[nv]) {\n\
    \                if (nv != p) {\n                    low[v] = min(low[v], ord[nv]);\n\
    \                }\n            } else {\n                dfs(nv, v, i);\n   \
    \             low[v] = min(low[v], low[nv]);\n                if (ord[v] <= low[nv])\
    \ art[v]++;\n                if (ord[v] < low[nv])\n                    bri.insert(make_pair(min(v,\
    \ nv), max(v, nv)));\n            }\n        }\n        if (p == -1) art[v]--;\n\
    \    }\n\n  public:\n    LowLink() {}\n    LowLink(const int _n)\n        : init(false),\n\
    \          n(_n),\n          comp(0),\n          g(_n),\n          seen(_n),\n\
    \          ord(_n),\n          low(_n),\n          art(_n) {}\n\n    void add_edge(int\
    \ u, int v) {\n        assert(!init);\n\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n\n    void build() {\n        assert(!init);\n        init = true;\n\n\
    \        for (int v = 0; v < n; v++)\n            if (!seen[v]) {\n          \
    \      comp++;\n                int i{};\n                dfs(v, -1, i);\n   \
    \         }\n    }\n\n    int component() const {\n        assert(init);\n\n \
    \       return comp;\n    }\n\n    int get_art(int v) const {\n        assert(init);\n\
    \n        return art[v];\n    }\n\n    bool is_art(int v) const {\n        assert(init);\n\
    \n        return 0 < get_art(v);\n    }\n\n    bool is_bridge(int u, int v) const\
    \ {\n        assert(init);\n\n        return bri.count(make_pair(min(u, v), max(u,\
    \ v)));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/low_link.hpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/GRL_3_B.test.cpp
documentation_of: graph/low_link.hpp
layout: document
redirect_from:
- /library/graph/low_link.hpp
- /library/graph/low_link.hpp.html
title: Low Link
---
