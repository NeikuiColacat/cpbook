template<const int mod>
struct mint {
    int num = 0;
    mint(){}
    mint(long long num) : num(num) {}
    mint(long long num, int mod) : num(num), mod(mod) {}
    mint(const mint & other) : num(other.num) {}

    mint operator+(const mint & other) {
        int res = ((long long)num + other.num )% mod;
        return mint(res);
    }
    mint operator-(const mint& other) {
        int res = ((long long)num - other.num + mod) % mod;
        return mint(res);
    }
    mint operator*(const mint& other) {
        int res = (long long)num * other.num % mod;
        return mint(res);
    }
    mint operator*=(const mint& other) {
        num = (long long)num * other.num % mod;
        return mint(num);
    }
    mint operator+=(const mint & other) {
        num = ((long long)num + other.num) % mod;
        return mint(num);
    }
    mint operator-=(const mint& other) {
        num = ((long long)num - other.num + mod) % mod;
        return mint(num);
    }
    bool operator==(const mint& other) {
        return num == other.num;
    }
    bool operator!=(const mint& other) {
        return num != other.num;
    }

    friend std::istream& operator>>(std::istream& is, mint& modNumber) {
        is >> modNumber.num;
        modNumber.num = (modNumber.num % modNumber.mod + modNumber.mod) % modNumber.mod;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& modNumber) {
        os << modNumber.num;
        return os;
    }
};