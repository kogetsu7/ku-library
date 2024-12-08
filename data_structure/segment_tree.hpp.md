---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_min.test.cpp
    title: test/yosupo/static_range_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
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
    document_title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree.hpp\"\n\n/**\n * @brief Segment\
    \ Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n */\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> class SegmentTree {\n  private:\n    int n;\n    vector<S> v;\n\
    \n    void update(int i) { v[i] = op(v[i << 1], v[(i << 1) | 1]); }\n\n  public:\n\
    \    SegmentTree() : SegmentTree(0) {}\n    SegmentTree(int _n) : SegmentTree(vector<S>(_n,\
    \ e())) {}\n    SegmentTree(const vector<S>& _v) {\n        n = (int)_v.size();\n\
    \        v.assign(2 * n, e());\n        for (int i = 0; i < n; i++) v[n + i] =\
    \ _v[i];\n        for (int i = n - 1; i >= 1; i--) update(i);\n    }\n\n    S\
    \ get(int i) const {\n        i += n;\n        return v[i];\n    }\n\n    S prod(int\
    \ l, int r) const {\n        l += n, r += n;\n        S v_l = e(), v_r = e();\n\
    \        while (l < r) {\n            if (l & 1) v_l = op(v_l, v[l++]);\n    \
    \        if (r & 1) v_r = op(v[--r], v_r);\n            l >>= 1, r >>= 1;\n  \
    \      }\n        return op(v_l, v_r);\n    }\n\n    void set(int i, S x) {\n\
    \        i += n;\n        v[i] = x;\n        while (1 < i) {\n            i >>=\
    \ 1;\n            update(i);\n        }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728)\n */\ntemplate <class S, S (*op)(S, S), S (*e)()> class SegmentTree {\n\
    \  private:\n    int n;\n    vector<S> v;\n\n    void update(int i) { v[i] = op(v[i\
    \ << 1], v[(i << 1) | 1]); }\n\n  public:\n    SegmentTree() : SegmentTree(0)\
    \ {}\n    SegmentTree(int _n) : SegmentTree(vector<S>(_n, e())) {}\n    SegmentTree(const\
    \ vector<S>& _v) {\n        n = (int)_v.size();\n        v.assign(2 * n, e());\n\
    \        for (int i = 0; i < n; i++) v[n + i] = _v[i];\n        for (int i = n\
    \ - 1; i >= 1; i--) update(i);\n    }\n\n    S get(int i) const {\n        i +=\
    \ n;\n        return v[i];\n    }\n\n    S prod(int l, int r) const {\n      \
    \  l += n, r += n;\n        S v_l = e(), v_r = e();\n        while (l < r) {\n\
    \            if (l & 1) v_l = op(v_l, v[l++]);\n            if (r & 1) v_r = op(v[--r],\
    \ v_r);\n            l >>= 1, r >>= 1;\n        }\n        return op(v_l, v_r);\n\
    \    }\n\n    void set(int i, S x) {\n        i += n;\n        v[i] = x;\n   \
    \     while (1 < i) {\n            i >>= 1;\n            update(i);\n        }\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_min.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/static_range_sum.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.hpp
- /library/data_structure/segment_tree.hpp.html
title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
