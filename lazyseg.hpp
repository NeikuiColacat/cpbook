template <typename T, typename LZ, T(*merT)(T, T), LZ(*merLZ)(LZ, LZ), T(*setag)(T, LZ)>
struct lazyseg {
    std::vector<T> tr;
    std::vector<LZ> lz;
    const int N;
    const T Te;
    const LZ LZe;
    lazyseg(int siz, T te, LZ lze) : N(siz), Te(te), LZe(lze) {
        tr.assign((N + 10) << 2, Te);
        lz.assign((N + 10) << 2, LZe);
    }
    lazyseg(int siz, T te , LZ lze , const std::vector<T>& a) : N(siz), Te(te), LZe(lze) {
        tr.resize((N + 10) << 2);
        lz.assign((N + 10) << 2, LZe);
        build(1, 1, N, a);
    }
    void pull(int u) {
        tr[u] = merT(tr[u << 1], tr[u << 1 | 1]);
    }
    void down(int u) {
        tr[u << 1] = setag(tr[u << 1], lz[u]);
        tr[u << 1 | 1] = setag(tr[u << 1 | 1], lz[u]);
        lz[u << 1] = merLZ(lz[u << 1], lz[u]);
        lz[u << 1 | 1] = merLZ(lz[u << 1 | 1], lz[u]);
        lz[u] = LZe;
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
    void modify(int u, int l, int r, const int ql, const int qr, const LZ val) {
        if (ql <= l && r <= qr) {
            tr[u] = setag(tr[u], val);
            lz[u] = merLZ(lz[u], val);
        }
        else {
            down(u);
            int mid = l + r >> 1;
            if (ql <= mid) modify(u << 1, l, mid, ql, qr, val);
            if (qr > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, val);
            pull(u);
        }
    };
    void set(int u, int l, int r, const int pos, const T val) {
        if (l == r) {
            tr[u] = val;
        }
        else {
            down(u);
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
        down(u);
        T res = Te;
        if (ql <= mid) res = merT(res, qry(u << 1, l, mid, ql, qr));
        if (qr > mid) res = merT(res, qry(u << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
};