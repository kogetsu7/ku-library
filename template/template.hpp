#pragma once

#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

constexpr int INF32 = INT_MAX / 2;
constexpr ll INF64 = 1LL << 60;
constexpr array<int, 8> DX = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr array<int, 8> DY = {-1, 0, 1, 0, -1, 1, 1, -1};
constexpr char LF = '\n';
const ld PI = acos(-1);

#define overload4(a, b, c, d, e, ...) e

#define rep1(i, a, b) for (ll i = (ll)(a); (i) < (ll)(b); (i)++)
#define rep2(i, a, b, c) for (ll i = (ll)(a); (i) < (ll)(b); (i) += (ll)(c))
#define rep(...) overload4(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

#define rrep1(i, a, b) for (ll i = (ll)(a); (i) >= (ll)(b); (i)--)
#define rrep2(i, a, b, c) for (ll i = (ll)(a); (i) >= (ll)(b); (i) -= (ll)(c))
#define rrep(...) overload4(__VA_ARGS__, rrep2, rrep1)(__VA_ARGS__)

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef LOCAL
#define IF_LOCAL if constexpr (true)
#else
#define IF_LOCAL if constexpr (false)
#endif

template <class T> bool chmin(T& a, const T& b) {
    return (a > b) ? (a = b, true) : false;
}
template <class T> bool chmax(T& a, const T& b) {
    return (a < b) ? (a = b, true) : false;
}
