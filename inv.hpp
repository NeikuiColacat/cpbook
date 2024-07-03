int fp(int a, int n, int mod) {
    int res = 1;
    while (n) {
        if (n % 2) res = (long long)res * a % mod;
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return res;
}
int inv(int x, int mod) { return fp(x, mod - 2, mod); }