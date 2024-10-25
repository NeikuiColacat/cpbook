struct SCC{
    const i32 N;
    i32 cnt = 0;
    vector<vector<i32>> g;
    vector<vector<i32>> scc;
    vector<i32> dfn, low, in_stk, stk;

    void dfs(i32 u) {
        cnt++;
        stk.push_back(u);
        in_stk[u] = 1;
        dfn[u] = low[u] = cnt;
        for (i32 i : g[u]) {
            if (!dfn[i]) {
                dfs(i);
                low[u] = min(low[u], low[i]);
            } else if (in_stk[i]) {
                low[u] = min(low[u], dfn[i]);
            }
        }
        if (low[u] == dfn[u]) {
            scc.push_back(vector<i32>());
            while (stk.back() != u) {
                i32 i = stk.back();
                stk.pop_back();
                in_stk[i] = 0;
                scc.back().push_back(i);
            }
            scc.back().push_back(u);
            in_stk[u] = 0;
            stk.pop_back();
        }
    }
    SCC(i32 siz, vector<vector<i32>> graph)
        : N(siz),
          g(graph),
          dfn(vector<i32>(N + 1)),
          low(vector<i32>(N + 1)),
          in_stk(vector<i32>(N + 1)) {
        for (i32 i = 1; i <= N; i++) {
            if (!dfn[i]) { dfs(i); }
        }
    }
};