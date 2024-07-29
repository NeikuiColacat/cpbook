#include <bits/stdc++.h>
using i32 = int;
struct cut_vertex{
    const i32 N;
    i32 cnt = 0;
    std::vector<std::vector<i32>> g;
    std::vector<i32> dfn, low, in_stk, stk, cut_ver;

    void dfs(i32 u , i32 fa){
        cnt++;
        stk.push_back(u);
        in_stk[u] = 1;
        dfn[u] = low[u] = cnt;
        i32 is_cut_ver = 0 , son = 0;
        for (i32 i : g[u]) {
            if (!dfn[i]) {
                dfs(i , u);
                low[u] = std::min(low[u], low[i]);
                is_cut_ver |= (low[i] >= dfn[u]);
                son++;
            } else if (in_stk[i]) {
                low[u] = std::min(low[u], dfn[i]);
            }
        }
        if (low[u] == dfn[u]) {
            while (stk.back() != u) {
                i32 i = stk.back();
                stk.pop_back();
                in_stk[i] = 0;
            }
            in_stk[u] = 0;
            stk.pop_back();
        }
        if((is_cut_ver && fa != u)|| (son >= 2 && u == fa)){
            cut_ver.push_back(u);
        }
    }
    cut_vertex(i32 siz, std::vector<std::vector<i32>> graph)
        : N(siz),
          g(graph),
          dfn(std::vector<i32>(N + 1)),
          low(std::vector<i32>(N + 1)),
          in_stk(std::vector<i32>(N + 1)) {
        for (i32 i = 1; i <= N; i++) {
            if (!dfn[i]) { dfs(i, i); }
        }
    }
};