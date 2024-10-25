i32 fp(i32 a, i32 n, i32 mod) {
    i32 res = 1;
    while (n) {
        if (n % 2) res = (i64)res * a % mod;
        a = (i64)a * a % mod;
        n >>= 1;
    }
    return res;
}