---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <iostream>\n\
    #include <vector>\nusing namespace std;\n\n#line 2 \"data_structure/segment_tree.hpp\"\
    \n\n/**\n * @brief Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n */\n\
    template <class S, S (*op)(S, S), S (*e)()> class SegmentTree {\n  private:\n\
    \    int n;\n    vector<S> v;\n\n    void update(int i) { v[i] = op(v[i << 1],\
    \ v[(i << 1) | 1]); }\n\n  public:\n    SegmentTree() : SegmentTree(0) {}\n  \
    \  SegmentTree(int _n) : SegmentTree(vector<S>(_n, e())) {}\n    SegmentTree(const\
    \ vector<S>& _v) {\n        n = (int)_v.size();\n        v.assign(2 * n, e());\n\
    \        for (int i = 0; i < n; i++) v[n + i] = _v[i];\n        for (int i = n\
    \ - 1; i >= 1; i--) update(i);\n    }\n\n    S get(int i) const {\n        i +=\
    \ n;\n        return v[i];\n    }\n\n    S prod(int l, int r) const {\n      \
    \  l += n, r += n;\n        S v_l = e(), v_r = e();\n        while (l < r) {\n\
    \            if (l & 1) v_l = op(v_l, v[l++]);\n            if (r & 1) v_r = op(v[--r],\
    \ v_r);\n            l >>= 1, r >>= 1;\n        }\n        return op(v_l, v_r);\n\
    \    }\n\n    void set(int i, S x) {\n        i += n;\n        v[i] = x;\n   \
    \     while (1 < i) {\n            i >>= 1;\n            update(i);\n        }\n\
    \    }\n};\n#line 8 \"test/yosupo/static_range_sum.test.cpp\"\n\nlong long op(long\
    \ long a, long long b) { return a + b; }\n\nlong long e() { return 0LL; }\n\n\
    int main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long> A(N);\n\
    \    for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    SegmentTree<long\
    \ long, op, e> seg(A);\n    for (; Q--;) {\n        int l, r;\n        cin >>\
    \ l >> r;\n        cout << seg.prod(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\nusing namespace std;\n\n#include \"../../data_structure/segment_tree.hpp\"\
    \n\nlong long op(long long a, long long b) { return a + b; }\n\nlong long e()\
    \ { return 0LL; }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<long\
    \ long> A(N);\n    for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\
    \n    SegmentTree<long long, op, e> seg(A);\n    for (; Q--;) {\n        int l,\
    \ r;\n        cin >> l >> r;\n        cout << seg.prod(l, r) << endl;\n    }\n\
    }\n"
  dependsOn:
  - data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_sum.test.cpp
- /verify/test/yosupo/static_range_sum.test.cpp.html
title: test/yosupo/static_range_sum.test.cpp
---
