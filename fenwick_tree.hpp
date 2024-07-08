template<typename T> 
struct fenwick_tree {
    const int N;
    T e;
    std::vector<T> tr;
    fenwick_tree(int siz , T e) : N(siz) , tr(std::vector<T>(N+1)) , e(e) {}

    void add(int pos, T val) {
        for (int i = pos;i<=N;i += i & -i) {
            tr[i] += val;
        }
    }

    T qry(int pos) {
        T res = e;
        for (int i = pos;i;i -= i & -i) {
            res += tr[i];
        }
        return res;
    }

    T qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }
};