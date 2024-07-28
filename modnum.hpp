template<const i32 mod>
struct modnum {
    i32 num = 0;
    modnum(){}
    modnum(i64 num) : num((num % mod + mod)%mod) {}

    modnum operator+(const modnum & other) {
        i32 res = ((i64)num + other.num )% mod;
        return modnum(res);
    }
    modnum operator-(const modnum& other) {
        i32 res = ((i64)num - other.num + mod) % mod;
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
        num = ((i64)num + other.num) % mod;
        return modnum(num);
    }
    modnum operator-=(const modnum& other) {
        num = ((i64)num - other.num + mod) % mod;
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