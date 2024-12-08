#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include "../../graph/topological_sort.hpp"

#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    ku::TopologicalSort ts(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        ts.add_edge(u, v);
    }

    ts.build();

    std::cout << (ts.is_dag() ? 0 : 1) << "\n";

    return 0;
}
