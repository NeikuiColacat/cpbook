struct tarjan{
    const i32 N;
    i32 cnt = 0;
    std::vector<std::vector<i32>> g;
    std::vector<std::vector<i32>> scc;
    std::vector<i32> dfn , low , in_stk , stk;

    void dfs(i32 u){
        cnt++;
        stk.push_back(u);
        in_stk[u] = 1;
        dfn[u] = low[u] = cnt;
        for (i32 i : g[u]) {
            if (!dfn[i]) {
                dfs(i);
                low[u] = std::min(low[u], low[i]);
            } else if (in_stk[i]) {
                low[u] = std::min(low[u], dfn[i]);
            }
        }
        if (low[u] == dfn[u]) {
            std::vector<i32> one_scc;
            while (stk.back() != u) {
                i32 i = stk.back();
                stk.pop_back();
                in_stk[i] = 0;
                one_scc.push_back(i);
            }
            one_scc.push_back(u);
            in_stk[u] = 0;
            stk.pop_back();
            scc.push_back(one_scc);
        }
    }
    tarjan(i32 siz, std::vector<std::vector<i32>> graph)
        : N(siz),
          g(graph),
          dfn(std::vector<i32>(N + 1)),
          low(std::vector<i32>(N + 1)),
          in_stk(std::vector<i32>(N + 1)) {
        for (i32 i = 1; i <= N; i++) {
            if (!dfn[i]) { dfs(i); }
        }
    }
};