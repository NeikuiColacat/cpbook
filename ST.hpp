template<typename T , T(*op)(T,T)>
struct ST {
    const int N,lglen;
    std::vector<std::vector<T>> st;
    ST(const std::vector<T>& a) : N((int)a.size() - 1), st(std::vector<std::vector<T>>(N, std::vector<T>(31))) {
        for (int i = 1;i <= N:i++) {
            st[i][0] = a[i];
        }
        for(int i = 1;)
    }
};