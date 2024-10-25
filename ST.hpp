template <typename T, T(*op)(T, T)>
struct ST {
	const i32 N;
	vector<vector<T>> st;
    ST(i32 siz, const vector<T>& a)
        : N(siz), st(N + 1, vector<T>(31)) {
        for (i32 i = 1; i <= N; i++) { st[i][0] = a[i]; }

        for (i32 i = 1; i <= log2(N); i++) {
            for (i32 j = 1; j + (1 << i) - 1 <= N; j++) {
                st[j][i] = op(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
            }
        }
    }

    T qry(i32 l, i32 r) {
        i32 lglen = log2(r - l + 1);
		return op(st[l][lglen], st[r - (1 << lglen) + 1][lglen]);
	}
};