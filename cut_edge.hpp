struct cut_edge {
    const i32 N;
    i32 cnt = 0;
    vector<vector<i32>> g;
    vector<i32> dfn, low;
    vector<pair<i32, i32>> bridge;
    void dfs(i32 u, i32 fa) {
        cnt++;
        dfn[u] = low[u] = cnt;
        for (i32 i : g[u]) {
            if (!dfn[i]) {
                dfs(i, u);
                low[u] = min(low[u], low[i]);
                if (low[i] > dfn[u]) { bridge.push_back({u, i}); }
            } else if (i != fa) {
                low[u] = min(low[u], dfn[i]);
            }
        }
    }
    cut_edge(i32 siz, vector<vector<i32>> graph)
        : N(siz),
          g(graph),
          dfn(N+1),
          low(N+1) {
        for (i32 i = 1; i <= N; i++) {
            if (!dfn[i]) { dfs(i, i); }
        }
    }
};