template<const int mod>
struct modnum {
    int num = 0;
    modnum(){}
    modnum(long long num) : num(num) {}
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

    friend std::istream& operator>>(std::istream& is, modnum& modNumber) {
        is >> modNumber.num;
        modNumber.num = (modNumber.num % modNumber.mod + modNumber.mod) % modNumber.mod;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modnum& modNumber) {
        os << modNumber.num;
        return os;
    }
};