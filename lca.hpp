struct lca{
    const i32 N , M = 30;
    std::vector<std::vector<i32>> g , f;
    std::vector<i32> dep;
    void dfs(i32 u, i32 fa) {
        f[u][0] = fa;
        dep[u] = dep[fa] + 1;
        for (i32 i = 1; i < M; i++) { f[u][i] = f[f[u][i - 1]][i - 1]; }
        for (i32 i : g[u]) {
            if (i == fa) continue;
            dfs(i, u);
        }
    }
    lca(i32 siz , i32 root , std::vector<std::vector<i32>> graph)
        : N(siz),
          g(graph),
          f(std::vector<std::vector<i32>>(N + 1, std::vector<i32>(M))),
          dep(std::vector<i32>(N + 1)) {
        dfs(root, root);
    }
    i32 qry(i32 u , i32 v){
        if(dep[u] > dep[v]) std::swap(u , v);
        i32 D = dep[v] - dep[u];
        for(i32 i = 0;i<M;i++){
            if(D >> i & 1){
                v = f[v][i];
            }
        } 

        if(u == v) return u;

        for(i32 i = M - 1;i>=0;i--){
            if(f[u][i] != f[v][i]){
                u = f[u][i];
                v = f[v][i];
            }
        }

        return f[u][0];
    }
};