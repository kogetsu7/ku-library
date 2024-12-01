---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.hpp
    title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/468
    links:
    - https://yukicoder.me/problems/no/468
  bundledCode: "#line 1 \"test/graph/topological_sort.get.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/468\"\n\n#include <algorithm>\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"graph/topological_sort.hpp\"\
    \n\n#include <cassert>\n#include <queue>\n#line 6 \"graph/topological_sort.hpp\"\
    \n\nnamespace Ku {\n/**\n * @brief Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\
    \u30EB\u30BD\u30FC\u30C8)\n */\nclass TopologicalSort {\n  private:\n    bool\
    \ init;\n    bool dag;\n    size_t n;\n    std::vector<std::vector<int>> g;\n\
    \    std::vector<int> p;\n\n  public:\n    TopologicalSort() : TopologicalSort(0)\
    \ {}\n    explicit TopologicalSort(const size_t _n)\n        : init(false), dag(false),\
    \ n(_n), g(_n), p() {}\n    explicit TopologicalSort(const std::vector<std::vector<int>>&\
    \ _g)\n        : init(false), dag(false), n(_g.size()), g(_g), p() {\n       \
    \ build();\n    }\n\n    void add_edge(const int u, const int v) {\n        assert(!init);\n\
    \        assert(0 <= u);\n        assert(u < static_cast<int>(n));\n        assert(0\
    \ <= v);\n        assert(v < static_cast<int>(n));\n\n        g[u].push_back(v);\n\
    \    }\n\n    void build() {\n        assert(!init);\n        init = true;\n\n\
    \        std::vector<int> cnt(n);\n        for (size_t v = 0; v < n; v++) {\n\
    \            for (int nv : g[v]) {\n                cnt[nv]++;\n            }\n\
    \        }\n\n        std::queue<int> que;\n        for (size_t v = 0; v < n;\
    \ v++) {\n            if (cnt[v] == 0) {\n                que.push(static_cast<int>(v));\n\
    \            }\n        }\n\n        while (!que.empty()) {\n            const\
    \ auto v = que.front();\n            que.pop();\n            p.push_back(v);\n\
    \            for (const auto nv : g[v]) {\n                cnt[nv]--;\n      \
    \          if (cnt[nv] == 0) {\n                    que.push(nv);\n          \
    \      }\n            }\n        }\n\n        dag = (n == p.size());\n\n     \
    \   if (!dag) {\n            p.clear();\n        }\n\n        return;\n    }\n\
    \n    bool is_dag() const {\n        assert(init);\n\n        return dag;\n  \
    \  }\n\n    int get(const size_t i) const {\n        assert(init);\n        assert(dag);\n\
    \        assert(i < n);\n\n        return p[i];\n    }\n};\n};  // namespace Ku\n\
    #line 9 \"test/graph/topological_sort.get.test.cpp\"\n\nint main() {\n    int\
    \ N, M;\n    std::cin >> N >> M;\n\n    std::vector<std::vector<std::pair<int,\
    \ int>>> g(N);\n    Ku::TopologicalSort ts(N);\n    Ku::TopologicalSort ts_inv(N);\n\
    \n    for (int i = 0; i < M; i++) {\n        int u, v, w;\n        std::cin >>\
    \ u >> v >> w;\n\n        g[u].emplace_back(v, w);\n        ts.add_edge(u, v);\n\
    \        ts_inv.add_edge(v, u);\n    }\n\n    ts.build();\n    ts_inv.build();\n\
    \n    assert(ts.is_dag());\n    assert(ts_inv.is_dag());\n\n    std::vector<int>\
    \ dp(N, 0);\n    std::vector<int> ep(N, 1 << 30);\n    ep[0] = 0;\n\n    for (int\
    \ i = 0; i < N; i++) {\n        int v = ts.get(i);\n        for (auto [nv, co]\
    \ : g[v]) {\n            dp[nv] = std::max(dp[nv], dp[v] + co);\n        }\n \
    \   }\n\n    ep[N - 1] = dp[N - 1];\n\n    for (int i = 0; i < N; i++) {\n   \
    \     int v = ts_inv.get(i);\n        for (auto [nv, co] : g[v]) {\n         \
    \   ep[v] = std::min(ep[v], ep[nv] - co);\n        }\n    }\n\n    int cnt = N;\n\
    \    for (int i = 0; i < N; i++) {\n        if (dp[i] == ep[i]) {\n          \
    \  cnt--;\n        }\n    }\n\n    std::cout << dp[N - 1] << ' ' << cnt << '/'\
    \ << N << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/468\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"../../graph/topological_sort.hpp\"\
    \n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n\n    std::vector<std::vector<std::pair<int,\
    \ int>>> g(N);\n    Ku::TopologicalSort ts(N);\n    Ku::TopologicalSort ts_inv(N);\n\
    \n    for (int i = 0; i < M; i++) {\n        int u, v, w;\n        std::cin >>\
    \ u >> v >> w;\n\n        g[u].emplace_back(v, w);\n        ts.add_edge(u, v);\n\
    \        ts_inv.add_edge(v, u);\n    }\n\n    ts.build();\n    ts_inv.build();\n\
    \n    assert(ts.is_dag());\n    assert(ts_inv.is_dag());\n\n    std::vector<int>\
    \ dp(N, 0);\n    std::vector<int> ep(N, 1 << 30);\n    ep[0] = 0;\n\n    for (int\
    \ i = 0; i < N; i++) {\n        int v = ts.get(i);\n        for (auto [nv, co]\
    \ : g[v]) {\n            dp[nv] = std::max(dp[nv], dp[v] + co);\n        }\n \
    \   }\n\n    ep[N - 1] = dp[N - 1];\n\n    for (int i = 0; i < N; i++) {\n   \
    \     int v = ts_inv.get(i);\n        for (auto [nv, co] : g[v]) {\n         \
    \   ep[v] = std::min(ep[v], ep[nv] - co);\n        }\n    }\n\n    int cnt = N;\n\
    \    for (int i = 0; i < N; i++) {\n        if (dp[i] == ep[i]) {\n          \
    \  cnt--;\n        }\n    }\n\n    std::cout << dp[N - 1] << ' ' << cnt << '/'\
    \ << N << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - graph/topological_sort.hpp
  isVerificationFile: true
  path: test/graph/topological_sort.get.test.cpp
  requiredBy: []
  timestamp: '2024-12-01 15:52:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/topological_sort.get.test.cpp
layout: document
redirect_from:
- /verify/test/graph/topological_sort.get.test.cpp
- /verify/test/graph/topological_sort.get.test.cpp.html
title: test/graph/topological_sort.get.test.cpp
---
