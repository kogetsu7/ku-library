---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/topological_sort.get.test.cpp
    title: test/graph/topological_sort.get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/topological_sort.is_dag.test.cpp
    title: test/graph/topological_sort.is_dag.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
      \u30C8)"
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n\n#include <cassert>\n#include\
    \ <queue>\n#include <vector>\n\nnamespace Ku {\n/**\n * @brief Topological Sort\
    \ (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)\n */\nclass TopologicalSort\
    \ {\n  private:\n    bool init;\n    bool dag;\n    size_t n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> p;\n\n  public:\n    TopologicalSort() : TopologicalSort(0)\
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
    \        assert(i < n);\n\n        return p[i];\n    }\n};\n};  // namespace Ku\n"
  code: "#pragma once\n\n#include <cassert>\n#include <queue>\n#include <vector>\n\
    \nnamespace Ku {\n/**\n * @brief Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\
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
    \        assert(i < n);\n\n        return p[i];\n    }\n};\n};  // namespace Ku\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/topological_sort.get.test.cpp
  - test/graph/topological_sort.is_dag.test.cpp
documentation_of: graph/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/topological_sort.hpp
- /library/graph/topological_sort.hpp.html
title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---
