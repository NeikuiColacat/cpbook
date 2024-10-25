struct dsu {
    const i32 N;
    vector<i32> p , siz;
    dsu(i32 siz) : N(siz), p(N+1) , siz(N+1 , 1) {
        iota(p.begin()+1,p.end(),1);
    }

    i32 find(i32 u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }

    void mer(i32 u, i32 v) {
        u = find(u) , v = find(v);        
        if(u != v){
            if (siz[u] > siz[v]) swap(u, v);
            p[u] = v;
            siz[v] += siz[u];
        }
    }
};