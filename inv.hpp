int inv(int x, int mod) {
    int res = 1;
    int expo = mod - 2;
    while (expo) {
        if (expo % 2) res = (long long)res * x % mod;
        x = (long long)x * x % mod;
        expo >>= 1;
    }
    return res;
}