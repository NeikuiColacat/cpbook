struct mint {
    const int num , mod = 998244353;
    mint(int num) : num(num) {}
    mint(int num, int mod) : num(num), mod(mod) {}

    int operator+(const mint & other) {
        return ((long long)num + other.num )% mod;
    }
    int operator-(const mint& other) {
        return ((long long)num - other.num + mod) % mod;
    }
    int operator*(const mint& other) {
        return (long long)num * other.num % mod;
    }
};