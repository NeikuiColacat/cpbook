template<const i32 mod>
struct modnum {
    i32 num = 0;
    modnum(){}
    modnum(i64 num) : num((num % mod + mod)%mod) {}

    modnum operator+(const modnum & other) {
        i32 res = (num + other.num )% mod;
        return modnum(res);
    }
    modnum operator-(const modnum& other) {
        i32 res = (num - other.num + mod) % mod;
        return modnum(res);
    }
    modnum operator*(const modnum& other) {
        i32 res = (i64)num * other.num % mod;
        return modnum(res);
    }
    modnum operator*=(const modnum& other) {
        num = (i64)num * other.num % mod;
        return modnum(num);
    }
    modnum operator+=(const modnum & other) {
        num = (num + other.num) % mod;
        return modnum(num);
    }
    modnum operator-=(const modnum& other) {
        num = (num - other.num + mod) % mod;
        return modnum(num);
    }
    bool operator==(const modnum& other) {
        return num == other.num;
    }
    bool operator!=(const modnum& other) {
        return num != other.num;
    }

    modnum inv() {
        i32 x, y;
        exgcd(num, mod, x, y);
        return modnum((x%mod + mod)%mod);
    }
    void exgcd(i32 a, i32 b, i32& x, i32& y) {
        if (b == 0) {
            x = 1, y = 0;
            return;
        }
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    friend istream& operator>>(istream& is, modnum& modNumber) {
        i64 tmp;cin >> tmp;
        modNumber.num = (tmp % mod + mod) % mod;
        return is;
    }
    friend ostream& operator<<(ostream& os, const modnum& modNumber) {
        os << modNumber.num;
        return os;
    }
};