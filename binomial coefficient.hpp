constexpr i32 mod = 1e9+7 , N = 1e5 + 10;
std::vector<i32> pw(N+1) , pwinv(N+1);
i32 fp(i32 a, i32 n, i32 mod) {
    i32 res = 1;
    while (n) {
        if (n % 2) res = (long long)res * a % mod;
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return res;
}
i32 inv(i32 x, i32 mod = mod) { return fp(x, mod - 2, mod); }
i32 C(i32 a, i32 b) {
    if (pw[0] == 0) {
        pwinv[0] = pw[0] = 1;
        for (i32 i = 1;i <= N;i++) {
            pw[i] = (long long)pw[i - 1] * i % mod;
            pwinv[i] = inv(pw[i]);
        }
    }
    if (a < b) return 0;
    return (long long)pw[a] * pwinv[b] % mod * pwinv[a-b] % mod;
}