#pragma once

#include <cassert>
#include <queue>
#include <vector>

namespace ku {
/**
 * @brief Topological Sort (トポロジカルソート)
 */
class TopologicalSort {
  private:
    bool init;
    bool dag;
    size_t n;
    std::vector<std::vector<int>> g;
    std::vector<int> p;

  public:
    TopologicalSort() noexcept : TopologicalSort(0) {}
    explicit TopologicalSort(const size_t _n) noexcept
        : init(false), dag(false), n(_n), g(_n), p() {}
    explicit TopologicalSort(const std::vector<std::vector<int>>& _g) noexcept
        : init(false), dag(false), n(_g.size()), g(_g), p() {
        build();
    }

    void add_edge(const int u, const int v) noexcept {
        assert(!init);
        assert(0 <= u);
        assert(u < static_cast<int>(n));
        assert(0 <= v);
        assert(v < static_cast<int>(n));

        g[u].push_back(v);
    }

    void build() noexcept {
        assert(!init);
        init = true;

        std::vector<int> cnt(n);
        for (size_t v = 0; v < n; v++) {
            for (int nv : g[v]) {
                cnt[nv]++;
            }
        }

        std::queue<int> que;
        for (size_t v = 0; v < n; v++) {
            if (cnt[v] == 0) {
                que.push(static_cast<int>(v));
            }
        }

        while (!que.empty()) {
            const auto v = que.front();
            que.pop();
            p.push_back(v);
            for (const auto nv : g[v]) {
                cnt[nv]--;
                if (cnt[nv] == 0) {
                    que.push(nv);
                }
            }
        }

        dag = (n == p.size());

        if (!dag) {
            p.clear();
        }

        return;
    }

    bool is_dag() const noexcept {
        assert(init);

        return dag;
    }

    int get(const size_t i) const noexcept {
        assert(init);
        assert(dag);
        assert(i < n);

        return p[i];
    }
};
};  // namespace ku
