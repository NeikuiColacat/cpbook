i32 fp(i32 a, i32 n, i32 mod) {
    i32 res = 1;
    while (n) {
        if (n % 2) res = (long long)res * a % mod;
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return res;
}
i32 inv(i32 x, i32 mod) { return fp(x, mod - 2, mod); }