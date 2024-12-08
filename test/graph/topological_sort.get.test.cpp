#define PROBLEM "https://yukicoder.me/problems/no/468"

#include "../../graph/topological_sort.hpp"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> g(N);
    ku::TopologicalSort ts(N);
    ku::TopologicalSort ts_inv(N);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        ts.add_edge(u, v);
        ts_inv.add_edge(v, u);
    }

    ts.build();
    ts_inv.build();

    assert(ts.is_dag());
    assert(ts_inv.is_dag());

    std::vector<int> dp(N, 0);
    std::vector<int> ep(N, 1 << 30);
    ep[0] = 0;

    for (int i = 0; i < N; i++) {
        int v = ts.get(i);
        for (auto [nv, co] : g[v]) {
            dp[nv] = std::max(dp[nv], dp[v] + co);
        }
    }

    ep[N - 1] = dp[N - 1];

    for (int i = 0; i < N; i++) {
        int v = ts_inv.get(i);
        for (auto [nv, co] : g[v]) {
            ep[v] = std::min(ep[v], ep[nv] - co);
        }
    }

    int cnt = N;
    for (int i = 0; i < N; i++) {
        if (dp[i] == ep[i]) {
            cnt--;
        }
    }

    std::cout << dp[N - 1] << ' ' << cnt << '/' << N << "\n";

    return 0;
}
