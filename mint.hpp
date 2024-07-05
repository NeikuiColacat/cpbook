struct mint {
    int num , mod = 998244353;
    mint(int num) : num(num) {}
    mint(int num, int mod) : num(num), mod(mod) {}

    mint operator+(const mint & other) {
        return ((long long)num + other.num )% mod;
    }
    mint operator-(const mint& other) {
        return ((long long)num - other.num + mod) % mod;
    }
    mint operator*(const mint& other) {
        return (long long)num * other.num % mod;
    }
    mint operator*=(const mint& other) {
        return num = (long long)num * other.num % mod;
    }
    mint operator+=(const mint & other) {
        return num = ((long long)num + other.num) % mod;
    }
    mint operator-=(const mint& other) {
        return num = ((long long)num - other.num + mod) % mod;
    }
    mint operator=(const int& val) {
        num = val;
    }
    mint operator=(const mint& other) {
        num = other.num;
    }
    friend std::istream& operator>>(std::istream& is, mint& modNumber) {
        is >> modNumber.num;
        modNumber.num %= modNumber.mod;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& modNumber) {
        os << modNumber.num;
        return os;
    }
};