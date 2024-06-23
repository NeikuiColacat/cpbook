template<typename T , T(*op)(T,T)>
struct ST {
    const int N,lglen;
    std::vector<std::vector<T>> st;
    ST(const std::vector<T>& a) : N((int)a.size() - 1), st(std::vector<std::vector<T>>(N+1, std::vector<T>(31))) {
        lglen = std::__lg(N) + 1;
        for (int i = 1;i <= N:i++) {
            st[i][0] = a[i];
        }

        for (int i = 1;i <= lglen;i++) {
            for (int j = 1;j + (1 << i) - 1 <= N;j++) {
                st[j][i] = op(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
            }
        }
    }

    T qry(int l, int r) {
        int len = std::__lg(r - l + 1);
        return op(st[l][len], st[r - (1 << len) + 1][len]);
    }
};