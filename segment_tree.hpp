template <typename T, T(*merT)(T, T)>
struct lazyseg {
    const int N;
    const T Te;
    std::vector<T> tr;
    lazyseg(int siz, T te) : N(siz), Te(te){
        tr.assign((N + 10) << 2, Te);
    }
    lazyseg(int siz, T te , const std::vector<T>& a) : N(siz), Te(te){
        tr.resize((N + 10) << 2);
        build(1, 1, N, a);
    }
    void pull(int u) {
        tr[u] = merT(tr[u << 1], tr[u << 1 | 1]);
    }
    void build(int u, int l, int r, const std::vector<T>& a) {
        if (l == r) {
            tr[u] = a[l];
        }
        else {
            int mid = l + r >> 1;
            build(u << 1, l, mid, a);build(u << 1 | 1, mid + 1, r, a);
            pull(u);
        }
    }
    void set(int u, int l, int r, const int pos, const T val) {
        if (l == r) {
            tr[u] = val;
        }
        else {
            int mid = l + r >> 1;
            if (pos <= mid) set(u << 1, l, mid, pos, val);
            else set(u << 1 | 1, mid + 1, r, pos, val);
            pull(u);
        }
    }
    T qry(int u, int l, int r, const int ql, const int qr) {
        if (ql <= l && r <= qr) {
            return tr[u];
        }
        int mid = l + r >> 1;
        T res = Te;
        if (ql <= mid) res = merT(res, qry(u << 1, l, mid, ql, qr));
        if (qr > mid) res = merT(res, qry(u << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
    void set(const int pos, const T val) { set(1, 1, N, pos, val); }
    T qry(const int ql, const int qr) { return qry(1, 1, N, ql, qr); }
};