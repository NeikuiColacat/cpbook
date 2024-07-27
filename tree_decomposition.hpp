#include <bits/stdc++.h>
using i32 = int;
struct tree_decomposition{
    const int N , root;
    i32 cnt = 0;
    std::vector<std::vector<i32>> g;
    std::vector<i32> fa, dep, siz, son, top, dfn, rnk;

    void dfs1(i32 u) {
        son[u] = -1, siz[u] = 1;
        for (i32 i : g[u]) {
            if(dep[i]) continue;
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
    tree_decomposition(i32 siz, i32 rt, std::vector<std::vector<i32>> graph)
        : N(siz),
          root(rt),
          g(graph),
          fa(std::vector<i32>(N + 1)),
          dep(std::vector<i32>(N + 1)),
          siz(std::vector<i32>(N + 1)),
          son(std::vector<i32>(N + 1)),
          top(std::vector<i32>(N + 1)),
          dfn(std::vector<i32>(N + 1)),
          rnk(std::vector<i32>(N + 1)) {
            
          }
};