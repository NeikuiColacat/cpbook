constexpr int mod = 1e9+7 , N = 1e5 + 10;
std::vector<int> pw(N+1) , pwinv(N+1);
int fp(int a, int n, int mod) {
    int res = 1;
    while (n) {
        if (n % 2) res = (long long)res * a % mod;
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return res;
}
int inv(int x, int mod = mod) { return fp(x, mod - 2, mod); }
int C(int a, int b) {
    if (pw[0] == 0) {
        pwinv[0] = pw[0] = 1;
        for (int i = 1;i <= N;i++) {
            pw[i] = (long long)pw[i - 1] * i % mod;
            pwinv[i] = inv(pw[i]);
        }
    }
    if (a < b) return 0;
    return (long long)pw[a] * pwinv[b] % mod * pwinv[a-b] % mod;
}