template <typename T, T(*op)(T, T)>
struct ST {
	const i32 N;
	std::vector<std::vector<T>> st;
    ST(i32 siz, const std::vector<T>& a)
        : N(siz), st(std::vector<std::vector<T>>(N + 1, std::vector<T>(31))) {
        for (i32 i = 1; i <= N; i++) { st[i][0] = a[i]; }

        for (i32 i = 1; i <= std::log2(N); i++) {
            for (i32 j = 1; j + (1 << i) - 1 <= N; j++) {
                st[j][i] = op(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
            }
        }
    }

    T qry(i32 l, i32 r) {
        i32 lglen = std::log2(r - l + 1);
		return op(st[l][lglen], st[r - (1 << lglen) + 1][lglen]);
	}
};