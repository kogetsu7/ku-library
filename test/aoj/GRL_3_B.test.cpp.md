---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: Low Link
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"test/aoj/GRL_3_B.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"graph/low_link.hpp\"\n\n\
    /**\n * @brief Low Link\n */\nclass LowLink {\n  private:\n    bool init;\n  \
    \  int n, comp;\n    vector<vector<int>> g;\n    vector<bool> seen;\n    vector<int>\
    \ ord, low, art;\n    set<pair<int, int>> bri;\n\n    void dfs(int v, int p, int&\
    \ i) {\n        seen[v] = true;\n        ord[v] = low[v] = i++;\n        for (const\
    \ int& nv : g[v]) {\n            if (seen[nv]) {\n                if (nv != p)\
    \ {\n                    low[v] = min(low[v], ord[nv]);\n                }\n \
    \           } else {\n                dfs(nv, v, i);\n                low[v] =\
    \ min(low[v], low[nv]);\n                if (ord[v] <= low[nv]) art[v]++;\n  \
    \              if (ord[v] < low[nv])\n                    bri.insert(make_pair(min(v,\
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
    \ v)));\n    }\n};\n#line 8 \"test/aoj/GRL_3_B.test.cpp\"\n\nint main() {\n  \
    \  int N, M;\n    cin >> N >> M;\n    LowLink lo(N);\n    vector<pair<int, int>>\
    \ edge(M);\n    for (int i = 0; i < M; i++) {\n        int u, v;\n        cin\
    \ >> u >> v;\n        edge[i] = make_pair(min(u, v), max(u, v));\n        lo.add_edge(u,\
    \ v);\n    }\n\n    lo.build();\n\n    vector<pair<int, int>> ans;\n    for (auto\
    \ [u, v] : edge) {\n        if (lo.is_bridge(u, v)) {\n            ans.push_back(make_pair(u,\
    \ v));\n        }\n    }\n\n    sort(ans.begin(), ans.end());\n\n    for (auto\
    \ [u, v] : ans) {\n        cout << u << ' ' << v << endl;\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/low_link.hpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    LowLink lo(N);\n    vector<pair<int,\
    \ int>> edge(M);\n    for (int i = 0; i < M; i++) {\n        int u, v;\n     \
    \   cin >> u >> v;\n        edge[i] = make_pair(min(u, v), max(u, v));\n     \
    \   lo.add_edge(u, v);\n    }\n\n    lo.build();\n\n    vector<pair<int, int>>\
    \ ans;\n    for (auto [u, v] : edge) {\n        if (lo.is_bridge(u, v)) {\n  \
    \          ans.push_back(make_pair(u, v));\n        }\n    }\n\n    sort(ans.begin(),\
    \ ans.end());\n\n    for (auto [u, v] : ans) {\n        cout << u << ' ' << v\
    \ << endl;\n    }\n}\n"
  dependsOn:
  - graph/low_link.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_B.test.cpp
- /verify/test/aoj/GRL_3_B.test.cpp.html
title: test/aoj/GRL_3_B.test.cpp
---
