struct tree_decomposition{
    const int N , root;
    i32 cnt = 0;
    vector<vector<i32>> g;
    vector<i32> fa, dep, siz, son, top, dfn, rnk;

    void dfs1(i32 u) {
        if(u == root) fa[u] = u;
        son[u] = -1, siz[u] = 1;
        for (i32 i : g[u]) {
            if(siz[i]) continue;
            dep[i] = dep[u] + 1;
            fa[i] = u;
            dfs1(i);
            siz[u] += siz[i];
            if (son[u] == -1 || siz[i] > siz[son[u]]) son[u] = i;
        }
    }
    void dfs2(i32 u, i32 t) {
        cnt++;
        top[u] = t;
        dfn[u] = cnt;
        rnk[cnt] = u;
        if (son[u] == -1) return;
        dfs2(son[u], t);
        for (i32 i : g[u]) {
            if (i != fa[u] && i != son[u]) { dfs2(i, i); }
        }
    }
    tree_decomposition(i32 siz, i32 rt, vector<vector<i32>> graph)
        : N(siz),
          root(rt),
          g(graph),
          fa(vector<i32>(N + 1)),
          dep(vector<i32>(N + 1)),
          siz(vector<i32>(N + 1)),
          son(vector<i32>(N + 1)),
          top(vector<i32>(N + 1)),
          dfn(vector<i32>(N + 1)),
          rnk(vector<i32>(N + 1)) {
        dfs1(root);
        dfs2(root , root);
    }
};