#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../data_structure/union_find.hpp"
#include "../../template/template.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0) {
            uf.merge(u, v);
        } else {
            cout << (uf.same(u, v) ? 1 : 0) << LF;
        }
    }

    return 0;
}
