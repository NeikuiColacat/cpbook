struct cut_edge {
    const i32 N;
    i32 cnt = 0;
    std::vector<std::vector<i32>> g;
    std::vector<i32> dfn, low;
    std::vector<std::pair<i32, i32>> bridge;
    void dfs(i32 u, i32 fa) {
        cnt++;
        dfn[u] = low[u] = cnt;
        for (i32 i : g[u]) {
            if (!dfn[i]) {
                dfs(i, u);
                low[u] = std::min(low[u], low[i]);
                if (low[i] > dfn[u]) { bridge.push_back({u, i}); }
            } else if (i != fa) {
                low[u] = std::min(low[u], dfn[i]);
            }
        }
    }
    cut_edge(i32 siz, std::vector<std::vector<i32>> graph)
        : N(siz),
          g(graph),
          dfn(std::vector<i32>(N + 1)),
          low(std::vector<i32>(N + 1)) {
        for (i32 i = 1; i <= N; i++) {
            if (!dfn[i]) { dfs(i, i); }
        }
    }
};