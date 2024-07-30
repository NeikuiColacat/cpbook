struct cut_vertex{
    const i32 N;
    i32 cnt = 0;
    std::vector<std::vector<i32>> g;
    std::vector<i32> dfn, low, cut_ver;

    void dfs(i32 u, i32 fa) {
        cnt++;
        dfn[u] = low[u] = cnt;
        i32 is_cut_ver = 0, son = 0;
        for (i32 i : g[u]) {
            if (!dfn[i]) {
                dfs(i, u);
                low[u] = std::min(low[u], low[i]);
                is_cut_ver |= (low[i] >= dfn[u]);
                son++;
            } else if (i != fa) {
                low[u] = std::min(low[u], dfn[i]);
            }
        }
        if ((is_cut_ver && fa != u) || (son >= 2 && u == fa)) {
            cut_ver.push_back(u);
        }
    }
    cut_vertex(i32 siz, std::vector<std::vector<i32>> graph)
        : N(siz),
          g(graph),
          dfn(std::vector<i32>(N + 1)),
          low(std::vector<i32>(N + 1)) {
        for (i32 i = 1; i <= N; i++) {
            if (!dfn[i]) { dfs(i, i); }
        }
    }
};