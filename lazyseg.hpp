template <typename T, typename LZ, T(*merT)(T, T), LZ(*merLZ)(LZ, LZ), T(*setag)(T, LZ)>
struct lazyseg {
    const i32 N;
    const T Te;
    const LZ LZe;
    std::vector<T> tr;
    std::vector<LZ> lz;
    lazyseg(i32 siz, T te, LZ lze) : N(siz), Te(te), LZe(lze) {
        tr.assign((N + 10) << 2, Te);
        lz.assign((N + 10) << 2, LZe);
    }
    lazyseg(i32 siz, T te , LZ lze , const std::vector<T>& a) : N(siz), Te(te), LZe(lze) {
        tr.resize((N + 10) << 2);
        lz.assign((N + 10) << 2, LZe);
        build(1, 1, N, a);
    }
    void pull(i32 u) {
        tr[u] = merT(tr[u << 1], tr[u << 1 | 1]);
    }
    void down(i32 u) {
        tr[u << 1] = setag(tr[u << 1], lz[u]);
        tr[u << 1 | 1] = setag(tr[u << 1 | 1], lz[u]);
        lz[u << 1] = merLZ(lz[u << 1], lz[u]);
        lz[u << 1 | 1] = merLZ(lz[u << 1 | 1], lz[u]);
        lz[u] = LZe;
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
    void modify(i32 u, i32 l, i32 r, const i32 ql, const i32 qr, const LZ val) {
        if (ql <= l && r <= qr) {
            tr[u] = setag(tr[u], val);
            lz[u] = merLZ(lz[u], val);
        }
        else {
            down(u);
            i32 mid = l + r >> 1;
            if (ql <= mid) modify(u << 1, l, mid, ql, qr, val);
            if (qr > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, val);
            pull(u);
        }
    };
    void set(i32 u, i32 l, i32 r, const i32 pos, const T val) {
        if (l == r) {
            tr[u] = val;
        }
        else {
            down(u);
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
        down(u);
        T res = Te;
        if (ql <= mid) res = merT(res, qry(u << 1, l, mid, ql, qr));
        if (qr > mid) res = merT(res, qry(u << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
    void modify(const i32 ql, const i32 qr, const LZ val) { modify(1, 1, N, ql, qr, val); }
    void set(const i32 pos, const T val) { set(1, 1, N, pos, val); }
    T qry(const i32 ql, const i32 qr) { return qry(1, 1, N, ql, qr); }
};