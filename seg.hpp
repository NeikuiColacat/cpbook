template <typename T>
struct seg {
    const i32 N;
    const T Te;
    vector<T> tr;
    seg(i32 siz, T te) : N(siz), Te(te), tr((N + 10) << 2, Te) {}
    T mer(T a, T b) {
        // TODO
    }
    void apply(T& a, T b) {
        // TODO
    }
    void up(i32 u) { 
        tr[u] = mer(tr[u << 1], tr[u << 1 | 1]); 
    }
    void down(i32 u) {
        apply(tr[u << 1], tr[u]);
        apply(tr[u << 1 | 1], tr[u]);
    }
    void modify(i32 u, i32 l, i32 r, const i32 ql, const i32 qr,T val) {
        if (ql <= l && r <= qr) {
            apply(tr[u], val);
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