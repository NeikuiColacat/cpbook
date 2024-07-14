template<const int mod>
struct modnum {
    int num = 0;
    modnum(){}
    modnum(long long num) : num((num % mod + mod)%mod) {}
    modnum(const modnum & other) : num(other.num) {}

    modnum operator+(const modnum & other) {
        int res = ((long long)num + other.num )% mod;
        return modnum(res);
    }
    modnum operator-(const modnum& other) {
        int res = ((long long)num - other.num + mod) % mod;
        return modnum(res);
    }
    modnum operator*(const modnum& other) {
        int res = (long long)num * other.num % mod;
        return modnum(res);
    }
    modnum operator*=(const modnum& other) {
        num = (long long)num * other.num % mod;
        return modnum(num);
    }
    modnum operator+=(const modnum & other) {
        num = ((long long)num + other.num) % mod;
        return modnum(num);
    }
    modnum operator-=(const modnum& other) {
        num = ((long long)num - other.num + mod) % mod;
        return modnum(num);
    }
    bool operator==(const modnum& other) {
        return num == other.num;
    }
    bool operator!=(const modnum& other) {
        return num != other.num;
    }

    modnum inv() {
        int x, y;
        exgcd(num, mod, x, y);
        return modnum((x%mod + mod)%mod);
    }
    void exgcd(int a, int b, int& x, int& y) {
        if (b == 0) {
            x = 1, y = 0;
            return;
        }
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    friend std::istream& operator>>(std::istream& is, modnum& modNumber) {
        is >> modNumber.num;
        modNumber.num = (modNumber.num % mod + mod) % mod;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modnum& modNumber) {
        os << modNumber.num;
        return os;
    }
};