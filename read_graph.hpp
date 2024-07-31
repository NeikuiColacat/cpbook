vector<vector<i32>> g(n + 1);
for (i32 i = 1; i <= n; i++) {
    i32 u, v;cin >> u >> v;
    g[u].push_back(v);g[v].push_back(u);
}