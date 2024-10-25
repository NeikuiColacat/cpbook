template <typename T>
struct seg {
    const i32 N;
    const T Te;
    vector<T> tr;
    seg(i32 siz, T te) : N(siz), Te(te), tr((N + 10) << 2, Te) {}
    T mer(T a, T b) {

    }
    void down(i32 u) {

    }
    void build(i32 u , i32 l , i32 r){
        if(l == r){

        } else{
            i32 mi = l + r >> 1;
            build(u<<1,l,mi) , build(u<<1|1,mi+1,r);
            up(u);
        }
    }
    void up(i32 u) { 
        tr[u] = mer(tr[u << 1], tr[u << 1 | 1]); 
    }
    void modify(i32 u, i32 l, i32 r, const i32 ql, const i32 qr,T val) {
        if (ql <= l && r <= qr) {

        }
        else {
            down(u);
            i32 mid = l + r >> 1;
            if (ql <= mid) modify(u << 1, l, mid, ql, qr, val);
            if (qr > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, val);
            up(u);
        }
    };
    T qry(i32 u, i32 l, i32 r, const i32 ql, const i32 qr) {
        if (ql <= l && r <= qr) {
            return tr[u];
        }
        down(u);
        i32 mid = l + r >> 1;
        T res = Te;
        if (ql <= mid) res = mer(res, qry(u << 1, l, mid, ql, qr));
        if (qr > mid) res = mer(res, qry(u << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
};