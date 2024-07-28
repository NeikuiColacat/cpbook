template <typename T, T(*merT)(T, T)>
struct seg {
    const i32 N;
    const T Te;
    std::vector<T> tr;
    seg(i32 siz, T te) : N(siz), Te(te){
        tr.assign((N + 10) << 2, Te);
    }
    seg(i32 siz, T te , const std::vector<T>& a) : N(siz), Te(te){
        tr.resize((N + 10) << 2);
        build(1, 1, N, a);
    }
    void pull(i32 u) {
        tr[u] = merT(tr[u << 1], tr[u << 1 | 1]);
    }
    void build(i32 u, i32 l, i32 r, const std::vector<T>& a) {
        if (l == r) {
            tr[u] = a[l];
        }
        else {
            i32 mid = l + r >> 1;
            build(u << 1, l, mid, a);build(u << 1 | 1, mid + 1, r, a);
            pull(u);
        }
    }
    void set(i32 u, i32 l, i32 r, const i32 pos, const T val) {
        if (l == r) {
            tr[u] = val;
        }
        else {
            i32 mid = l + r >> 1;
            if (pos <= mid) set(u << 1, l, mid, pos, val);
            else set(u << 1 | 1, mid + 1, r, pos, val);
            pull(u);
        }
    }
    T qry(i32 u, i32 l, i32 r, const i32 ql, const i32 qr) {
        if (ql <= l && r <= qr) {
            return tr[u];
        }
        i32 mid = l + r >> 1;
        T res = Te;
        if (ql <= mid) res = merT(res, qry(u << 1, l, mid, ql, qr));
        if (qr > mid) res = merT(res, qry(u << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
    void set(const i32 pos, const T val) { set(1, 1, N, pos, val); }
    T qry(const i32 ql, const i32 qr) { return qry(1, 1, N, ql, qr); }
};