---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Rolling Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
      \u30E5)"
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n\n/**\n * @brief Rolling Hash\
    \ (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)\n */\nclass RollingHash\
    \ {\n    using ll = long long;\n\n  private:\n    static const ll mod1 = 888888901,\
    \ mod2 = 987654323;\n    ll base1, base2;\n    int n;\n    vector<ll> hash1, hash2,\
    \ pow1, pow2;\n\n  public:\n    RollingHash() {}\n    RollingHash(const string&\
    \ s, const ll _base1 = 2525, const ll _base2 = 4649)\n        : base1(_base1),\
    \ base2(_base2) {\n        n = s.length();\n        hash1.assign(n + 1, 0);\n\
    \        hash2.assign(n + 1, 0);\n        pow1.assign(n + 1, 1);\n        pow2.assign(n\
    \ + 1, 1);\n        for (int i = 0; i < n; i++) {\n            hash1[i + 1] =\
    \ (hash1[i] * base1 + s[i]) % mod1;\n            hash2[i + 1] = (hash2[i] * base2\
    \ + s[i]) % mod2;\n            pow1[i + 1] = (pow1[i] * base1) % mod1;\n     \
    \       pow2[i + 1] = (pow2[i] * base2) % mod2;\n        }\n    }\n\n    pair<ll,\
    \ ll> get(const int l, const int r) const {\n        ll fi = hash1[r] - (hash1[l]\
    \ * pow1[r - l] % mod1);\n        if (fi < 0) fi += mod1;\n        ll se = hash2[r]\
    \ - (hash2[l] * pow2[r - l] % mod2);\n        if (se < 0) se += mod2;\n      \
    \  return make_pair(fi, se);\n    }\n\n    pair<ll, ll> merge(const pair<ll, ll>\
    \ a,\n                       const pair<ll, ll> b,\n                       const\
    \ int b_len) const {\n        ll fi = ((a.first * pow1[b_len]) % mod1 + b.first)\
    \ % mod1;\n        ll se = ((a.second * pow2[b_len]) % mod2 + b.second) % mod2;\n\
    \        return make_pair(fi, se);\n    }\n\n    int lcp(const int a, const int\
    \ b) const {\n        int ok = 0, ng = min(n + 1 - a, n + 1 - b);\n        while\
    \ (1 < ng - ok) {\n            int mid = (ok + ng) / 2;\n            if (get(a,\
    \ a + mid) == get(b, b + mid))\n                ok = mid;\n            else\n\
    \                ng = mid;\n        }\n        return ok;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Rolling Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5)\n */\nclass RollingHash {\n    using ll = long long;\n\
    \n  private:\n    static const ll mod1 = 888888901, mod2 = 987654323;\n    ll\
    \ base1, base2;\n    int n;\n    vector<ll> hash1, hash2, pow1, pow2;\n\n  public:\n\
    \    RollingHash() {}\n    RollingHash(const string& s, const ll _base1 = 2525,\
    \ const ll _base2 = 4649)\n        : base1(_base1), base2(_base2) {\n        n\
    \ = s.length();\n        hash1.assign(n + 1, 0);\n        hash2.assign(n + 1,\
    \ 0);\n        pow1.assign(n + 1, 1);\n        pow2.assign(n + 1, 1);\n      \
    \  for (int i = 0; i < n; i++) {\n            hash1[i + 1] = (hash1[i] * base1\
    \ + s[i]) % mod1;\n            hash2[i + 1] = (hash2[i] * base2 + s[i]) % mod2;\n\
    \            pow1[i + 1] = (pow1[i] * base1) % mod1;\n            pow2[i + 1]\
    \ = (pow2[i] * base2) % mod2;\n        }\n    }\n\n    pair<ll, ll> get(const\
    \ int l, const int r) const {\n        ll fi = hash1[r] - (hash1[l] * pow1[r -\
    \ l] % mod1);\n        if (fi < 0) fi += mod1;\n        ll se = hash2[r] - (hash2[l]\
    \ * pow2[r - l] % mod2);\n        if (se < 0) se += mod2;\n        return make_pair(fi,\
    \ se);\n    }\n\n    pair<ll, ll> merge(const pair<ll, ll> a,\n              \
    \         const pair<ll, ll> b,\n                       const int b_len) const\
    \ {\n        ll fi = ((a.first * pow1[b_len]) % mod1 + b.first) % mod1;\n    \
    \    ll se = ((a.second * pow2[b_len]) % mod2 + b.second) % mod2;\n        return\
    \ make_pair(fi, se);\n    }\n\n    int lcp(const int a, const int b) const {\n\
    \        int ok = 0, ng = min(n + 1 - a, n + 1 - b);\n        while (1 < ng -\
    \ ok) {\n            int mid = (ok + ng) / 2;\n            if (get(a, a + mid)\
    \ == get(b, b + mid))\n                ok = mid;\n            else\n         \
    \       ng = mid;\n        }\n        return ok;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/zalgorithm.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: "Rolling Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
---
