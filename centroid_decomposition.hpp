/**
 *  author: NeikuiColacat
 *  created: 10.08.2024 00:19:17
**/
#include <bits/stdc++.h>
#include <vector>
#define x first
#define y second
#define si(x) ((i32)x.size())
using std::cout, std::cin, std::cerr, std::endl;
using std::max, std::min, std::swap, std::vector, std::string;
using i32 = signed int;
using i64 = long long;
using P = std::pair<i32,i32>;
template<typename T> void cmax(T & a , T b){a = max(a,b);}
template<typename T> void cmin(T & a , T b){a = min(a,b);}

struct centroid_decomposition{
    const i32 N;
    i32 root = 1;
    std::vector<std::vector<P>> g;
    std::vector<i32> del , dist , siz , sub_max , dd;
    std::set<i32> tf;

    void cal_siz(i32 u , i32 fa){
        siz[u] = 1, sub_max[u] = 0;
        for(auto [w,v] : g[u]){
            if (v == fa || del[v]) continue;
            cmax(sub_max[u] , siz[v]);
            siz[u] += siz[v];
        }
        cmax(sub_max[u] , N - siz[u]);
        if (sub_max[u] < sub_max[root]) root = u;
    }
    void cal_dist(i32 u , i32 fa){
        dd.push_back(dist[u]);
        for(auto [w,v] : g[u]){
            if(v == fa || del[v]) continue;
            dist[v] = dist[u] + w;
            cal_dist(v, u);
        }
    }
    void DAC(i32 u , i32 fa){
        tf.insert(0);
        del[u] = true;
        for(auto [w,v] : g[u]){
            if (v == fa || del[v]) continue;
            dist[v] = w;
            cal_dist(v, u);
            
            for(i32 k = 1;k<si(dd);k++){
                for(i32 i = 1;)
            }
        }

    }    

    centroid_decomposition(i32 siz, std::vector<std::vector<P>> graph)
        : N(siz),
          g(graph),
          del(std::vector<i32>(N + 1)),
          dist(std::vector<i32>(N + 1)),
          siz(std::vector<i32>(N + 1)),
          sub_max(std::vector<i32>(N + 1, 1e9)) , dd(std::vector<i32>(1)){}
};
void solve() {

}

signed main() {
    std :: ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    i32 t;
    cin >> t;
    while (t--) solve();
    return 0;
}