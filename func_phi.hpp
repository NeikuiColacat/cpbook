struct func_phi{
    // phi(n) = n * PI (p_i-1) / (p_i)
    const i32 N;
    vector<i32> prime , mnfac , phi;
    func_phi(i32 siz) : N(siz), mnfac(N + 1), phi(N + 1) {
        phi[1] = 1;
        for (i32 i = 2; i <= N; i++) {
            if (!mnfac[i]) {
                prime.push_back(i);
                mnfac[i] = i;
                phi[i] = i - 1;
            }
            for (i64 j : prime) {
                if (j * i > N) break;
                mnfac[j * i] = j;
                if (i % j == 0) {
                    phi[i * j] = phi[i] * j;
                    break;
                } else {
                    phi[i * j] = phi[i] * (j - 1);
                }
            }
        }
    }
    static i64 PHI(i64 num) {
        i64 ans = num;
        for (i64 i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                ans = ans / i * (i - 1);
                while (num % i == 0) num /= i;
            }
        }
        if (num > 1) ans = ans / num * (num - 1);
        return ans;
    }
};