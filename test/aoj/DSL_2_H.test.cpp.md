---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/ordered_map_and_range_query.hpp
    title: Ordered Map and Range Query
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
  bundledCode: "#line 1 \"test/aoj/DSL_2_H.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\n\n// #define\
    \ _GLIBCXX_DEBUG\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"\
    data_structure/ordered_map_and_range_query.hpp\"\n\n/**\n * @brief Ordered Map\
    \ and Range Query\n */\ntemplate <class K,\n          bool (*compare)(K, K),\n\
    \          class S,\n          S (*op)(S, S),\n          S (*e)(),\n         \
    \ class F,\n          S (*mapping)(F, S),\n          F (*composition)(F, F),\n\
    \          F (*id)()>\nclass OrderedMapAndRangeQuery {\n  private:\n    class\
    \ Node {\n      public:\n        int size;\n        Node *left, *right;\n    \
    \    K key;\n        S value, sum;\n        F lazy;\n\n        Node(K _key) :\
    \ Node(_key, e()) {}\n        Node(K _key, S _value) : Node(_key, _value, id())\
    \ {}\n        Node(K _key, S _value, F _lazy)\n            : size(1),\n      \
    \        left(nullptr),\n              right(nullptr),\n              key(_key),\n\
    \              value(_value),\n              sum(_value),\n              lazy(_lazy)\
    \ {}\n    };\n\n    Node* root;\n\n    int size(Node* node) {\n        if (node\
    \ == nullptr) return 0;\n        return node->size;\n    }\n\n    S value(Node*\
    \ node) {\n        if (node == nullptr) return e();\n        return node->value;\n\
    \    }\n\n    S sum(Node* node) {\n        if (node == nullptr) return e();\n\
    \        return node->sum;\n    }\n\n    F lazy(Node* node) {\n        if (node\
    \ == nullptr) return id();\n        return node->lazy;\n    }\n\n    void propagate(Node*\
    \ node, F f) {\n        if (node == nullptr) return;\n        node->value = mapping(f,\
    \ value(node));\n        node->sum = mapping(f, sum(node));\n        node->lazy\
    \ = composition(f, lazy(node));\n    }\n\n    void push(Node* node) {\n      \
    \  if (node == nullptr) return;\n        if (lazy(node) != id()) {\n         \
    \   propagate(node->left, lazy(node));\n            propagate(node->right, lazy(node));\n\
    \            node->lazy = id();\n        }\n    }\n\n    void update(Node* node)\
    \ {\n        push(node);\n        if (node == nullptr) return;\n        node->sum\
    \ = op(op(sum(node->left), value(node)), sum(node->right));\n        node->size\
    \ = size(node->left) + 1 + size(node->right);\n    }\n\n    int lower_bound(Node*\
    \ node, K k) {\n        push(node);\n        if (node == nullptr) return 0;\n\
    \        if (compare(node->key, k)) {\n            return size(node->left) + lower_bound(node->right,\
    \ k) + 1;\n        }\n        return lower_bound(node->left, k);\n    }\n\n  \
    \  int upper_bound(Node* node, K k) {\n        push(node);\n        if (node ==\
    \ nullptr) return 0;\n        if (compare(k, node->key)) {\n            return\
    \ upper_bound(node->left, k);\n        }\n        return size(node->left) + upper_bound(node->right,\
    \ k) + 1;\n    }\n\n    pair<K, S> get(Node* node, int i) {\n        push(node);\n\
    \        assert(node != nullptr);\n        if (i == size(node->left)) return make_pair(node->key,\
    \ value(node));\n        if (i < size(node->left)) return get(node->left, i);\n\
    \        return get(node->right, i - size(node->left) - 1);\n    }\n\n    unsigned\
    \ xor128() {\n        static unsigned x = 123'456'789, y = 362'436'069, z = 521'288'629,\n\
    \                        w = 88'675'123;\n        unsigned t = x ^ (x << 11);\n\
    \        x = y, y = z, z = w, w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n        return\
    \ w;\n    }\n\n    Node* merge(Node* l, Node* r) {\n        push(l), push(r);\n\
    \        if (l == nullptr) return r;\n        if (r == nullptr) return l;\n  \
    \      if (xor128() % (size(l) + size(r)) < unsigned(size(l))) {\n           \
    \ l->right = merge(l->right, r);\n            update(l);\n            return l;\n\
    \        }\n        r->left = merge(l, r->left);\n        update(r);\n       \
    \ return r;\n    }\n\n    pair<Node*, Node*> split(Node* node, int i) {\n    \
    \    push(node);\n        if (node == nullptr) return make_pair(nullptr, nullptr);\n\
    \        if (i <= size(node->left)) {\n            pair<Node*, Node*> s = split(node->left,\
    \ i);\n            node->left = s.second;\n            update(node);\n       \
    \     return make_pair(s.first, node);\n        }\n        pair<Node*, Node*>\
    \ s = split(node->right, i - size(node->left) - 1);\n        node->right = s.first;\n\
    \        update(node);\n        return make_pair(node, s.second);\n    }\n\n \
    \ public:\n    OrderedMapAndRangeQuery() : root(nullptr) {}\n\n    int size()\
    \ { return size(root); }\n\n    int lower_bound(K k) { return lower_bound(root,\
    \ k); }\n\n    int upper_bound(K k) { return upper_bound(root, k); }\n\n    bool\
    \ count(K k) { return upper_bound(k) != lower_bound(k); }\n\n    pair<K, S> get(int\
    \ i) { return get(root, i); }\n\n    void erase(K k) {\n        if (!count(k))\
    \ return;\n        pair<Node*, Node*> s = split(root, lower_bound(k));\n     \
    \   pair<Node*, Node*> t = split(s.second, 1);\n        delete t.first;\n    \
    \    root = merge(s.first, t.second);\n    }\n\n    void insert(K k, S v) {\n\
    \        if (count(k)) erase(k);\n        pair<Node*, Node*> s = split(root, lower_bound(k));\n\
    \        root = merge(merge(s.first, new Node(k, v)), s.second);\n    }\n\n  \
    \  S prod(int a, int b) {\n        pair<Node*, Node*> s = split(root, a);\n  \
    \      pair<Node*, Node*> t = split(s.second, b - a);\n        S res = sum(t.first);\n\
    \        root = merge(s.first, merge(t.first, t.second));\n        return res;\n\
    \    }\n\n    void apply(int a, int b, F f) {\n        pair<Node*, Node*> s =\
    \ split(root, a);\n        pair<Node*, Node*> t = split(s.second, b - a);\n  \
    \      propagate(t.first, f);\n        root = merge(s.first, merge(t.first, t.second));\n\
    \    }\n};\n#line 9 \"test/aoj/DSL_2_H.test.cpp\"\n\nusing ll = long long;\nconstexpr\
    \ ll INF64 = 1LL << 60;\n\nusing K = ll;\nbool compare(K a, K b) { return a <\
    \ b; }\n\nusing S = ll;\nS op(S a, S b) { return min(a, b); }\nS e() { return\
    \ INF64; }\n\nusing F = ll;\nS mapping(F f, S a) { return a + f; }\nF composition(F\
    \ f, F g) { return f + g; }\nF id() { return 0LL; }\n\nint main() {\n    int N,\
    \ Q;\n    cin >> N >> Q;\n\n    OrderedMapAndRangeQuery<K, compare, S, op, e,\
    \ F, mapping, composition, id>\n        rbst;\n    rbst.insert(-INF64, 0LL);\n\
    \    rbst.insert(INF64, 0LL);\n\n    for (; Q--;) {\n        int t;\n        cin\
    \ >> t;\n        if (t == 0) {\n            int l, r;\n            cin >> l >>\
    \ r;\n            r++;\n            ll x;\n            cin >> x;\n           \
    \ if (!rbst.count(l)) {\n                rbst.insert(l, rbst.get(rbst.lower_bound(l)\
    \ - 1).second);\n            }\n            if (!rbst.count(r)) {\n          \
    \      rbst.insert(r, rbst.get(rbst.lower_bound(r) - 1).second);\n           \
    \ }\n            rbst.apply(rbst.lower_bound(l), rbst.lower_bound(r), x);\n  \
    \      } else {\n            int l, r;\n            cin >> l >> r;\n         \
    \   r++;\n            S ans = rbst.prod(rbst.upper_bound(l) - 1, rbst.lower_bound(r));\n\
    \            if (ans == e())\n                cout << 0LL << endl;\n         \
    \   else\n                cout << ans << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n// #define _GLIBCXX_DEBUG\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#include \"../../data_structure/ordered_map_and_range_query.hpp\"\n\nusing ll\
    \ = long long;\nconstexpr ll INF64 = 1LL << 60;\n\nusing K = ll;\nbool compare(K\
    \ a, K b) { return a < b; }\n\nusing S = ll;\nS op(S a, S b) { return min(a, b);\
    \ }\nS e() { return INF64; }\n\nusing F = ll;\nS mapping(F f, S a) { return a\
    \ + f; }\nF composition(F f, F g) { return f + g; }\nF id() { return 0LL; }\n\n\
    int main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    OrderedMapAndRangeQuery<K,\
    \ compare, S, op, e, F, mapping, composition, id>\n        rbst;\n    rbst.insert(-INF64,\
    \ 0LL);\n    rbst.insert(INF64, 0LL);\n\n    for (; Q--;) {\n        int t;\n\
    \        cin >> t;\n        if (t == 0) {\n            int l, r;\n           \
    \ cin >> l >> r;\n            r++;\n            ll x;\n            cin >> x;\n\
    \            if (!rbst.count(l)) {\n                rbst.insert(l, rbst.get(rbst.lower_bound(l)\
    \ - 1).second);\n            }\n            if (!rbst.count(r)) {\n          \
    \      rbst.insert(r, rbst.get(rbst.lower_bound(r) - 1).second);\n           \
    \ }\n            rbst.apply(rbst.lower_bound(l), rbst.lower_bound(r), x);\n  \
    \      } else {\n            int l, r;\n            cin >> l >> r;\n         \
    \   r++;\n            S ans = rbst.prod(rbst.upper_bound(l) - 1, rbst.lower_bound(r));\n\
    \            if (ans == e())\n                cout << 0LL << endl;\n         \
    \   else\n                cout << ans << endl;\n        }\n    }\n}\n"
  dependsOn:
  - data_structure/ordered_map_and_range_query.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_H.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_H.test.cpp
- /verify/test/aoj/DSL_2_H.test.cpp.html
title: test/aoj/DSL_2_H.test.cpp
---
