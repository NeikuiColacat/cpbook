template <typename T, T(*op)(T, T)>
struct ST {
	const int N;
	std::vector<std::vector<T>> st;
	ST(const std::vector<T>& a) : N((int)a.size() - 1), st(std::vector<std::vector<T>>(N + 1, std::vector<T>(31))){
		for (int i = 1; i <= N; i++) {
			st[i][0] = a[i];
		}

		for (int i = 1; i <= std::__lg(N); i++) {
			for (int j = 1; j + (1 << i) - 1 <= N; j++) {
				st[j][i] = op(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
			}
		}
	}

	T qry(int l, int r) {
        int lglen = std::__lg(r - l + 1);
		return op(st[l][lglen], st[r - (1 << lglen) + 1][lglen]);
	}
};