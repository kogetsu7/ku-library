---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"data_structure/segment_tree.hpp\"\n\n/**\n *\
    \ @brief Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n */\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> class SegmentTree {\n  private:\n    int n;\n  \
    \  vector<S> v;\n\n    void update(int i) { v[i] = op(v[i << 1], v[(i << 1) |\
    \ 1]); }\n\n  public:\n    SegmentTree() : SegmentTree(0) {}\n    SegmentTree(int\
    \ _n) : SegmentTree(vector<S>(_n, e())) {}\n    SegmentTree(const vector<S>& _v)\
    \ {\n        n = (int)_v.size();\n        v.assign(2 * n, e());\n        for (int\
    \ i = 0; i < n; i++) v[n + i] = _v[i];\n        for (int i = n - 1; i >= 1; i--)\
    \ update(i);\n    }\n\n    S get(int i) const {\n        i += n;\n        return\
    \ v[i];\n    }\n\n    S prod(int l, int r) const {\n        l += n, r += n;\n\
    \        S v_l = e(), v_r = e();\n        while (l < r) {\n            if (l &\
    \ 1) v_l = op(v_l, v[l++]);\n            if (r & 1) v_r = op(v[--r], v_r);\n \
    \           l >>= 1, r >>= 1;\n        }\n        return op(v_l, v_r);\n    }\n\
    \n    void set(int i, S x) {\n        i += n;\n        v[i] = x;\n        while\
    \ (1 < i) {\n            i >>= 1;\n            update(i);\n        }\n    }\n\
    };\n#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n/**\n * @brief Heavy Light\
    \ Decomposition (HL\u5206\u89E3)\n */\nclass HeavyLightDecomposition {\n  private:\n\
    \    bool init;\n    int n;\n    vector<vector<int>> g;\n    vector<int> siz,\
    \ par, dep, top, in, out;\n\n    void dfs_siz(int v, int p) {\n        par[v]\
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
    \    }\n    }\n};\n#line 8 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\n\n\
    long long op(long long a, long long b) { return a + b; }\n\nlong long e() { return\
    \ 0LL; }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long>\
    \ A(N);\n    for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n  \
    \  HeavyLightDecomposition hld(N);\n    for (int i = 1; i < N; i++) {\n      \
    \  int p;\n        cin >> p;\n        hld.add_edge(i, p);\n    }\n\n    hld.build();\n\
    \n    SegmentTree<long long, op, e> seg(N);\n    for (int i = 0; i < N; i++) {\n\
    \        hld.node_query(i, [&](int j) -> void {\n            seg.set(j, A[i]);\n\
    \            return;\n        });\n    }\n\n    for (; Q--;) {\n        int t;\n\
    \        cin >> t;\n        if (t == 0) {\n            int i;\n            cin\
    \ >> i;\n            long long x;\n            cin >> x;\n            hld.node_query(i,\
    \ [&](int j) -> void {\n                seg.set(j, seg.get(j) + x);\n        \
    \        return;\n            });\n        } else {\n            int i;\n    \
    \        cin >> i;\n            long long ans{};\n            hld.subtree_query(i,\
    \ [&](int l, int r) -> void {\n                ans += seg.prod(l, r);\n      \
    \          return;\n            });\n            cout << ans << endl;\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/segment_tree.hpp\"\
    \n#include \"../../tree/heavy_light_decomposition.hpp\"\n\nlong long op(long long\
    \ a, long long b) { return a + b; }\n\nlong long e() { return 0LL; }\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    HeavyLightDecomposition\
    \ hld(N);\n    for (int i = 1; i < N; i++) {\n        int p;\n        cin >> p;\n\
    \        hld.add_edge(i, p);\n    }\n\n    hld.build();\n\n    SegmentTree<long\
    \ long, op, e> seg(N);\n    for (int i = 0; i < N; i++) {\n        hld.node_query(i,\
    \ [&](int j) -> void {\n            seg.set(j, A[i]);\n            return;\n \
    \       });\n    }\n\n    for (; Q--;) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int i;\n            cin >> i;\n          \
    \  long long x;\n            cin >> x;\n            hld.node_query(i, [&](int\
    \ j) -> void {\n                seg.set(j, seg.get(j) + x);\n                return;\n\
    \            });\n        } else {\n            int i;\n            cin >> i;\n\
    \            long long ans{};\n            hld.subtree_query(i, [&](int l, int\
    \ r) -> void {\n                ans += seg.prod(l, r);\n                return;\n\
    \            });\n            cout << ans << endl;\n        }\n    }\n}\n"
  dependsOn:
  - data_structure/segment_tree.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.test.cpp
---
