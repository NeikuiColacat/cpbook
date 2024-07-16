template<typename T> 
struct fenwick_tree {
    const i32 N;
    T e;
    std::vector<T> tr;
    fenwick_tree(i32 siz , T e) : N(siz) , tr(std::vector<T>(N+1)) , e(e) {}

    void add(i32 pos, T val) {
        for (i32 i = pos;i<=N;i += i & -i) {
            tr[i] += val;
        }
    }

    T qry(i32 pos) {
        T res = e;
        for (i32 i = pos;i;i -= i & -i) {
            res += tr[i];
        }
        return res;
    }

    T qry(i32 l, i32 r) {
        return qry(r) - qry(l - 1);
    }
};