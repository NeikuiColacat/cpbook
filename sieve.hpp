struct sieve {
    const int N;
    std::vector<int> prime , mnfac;
    sieve(int siz) : N(siz), mnfac(std::vector<int>(N + 10)) {
        for (int i = 2;i <= N;i++) {
            if (!mnfac[i]) {
                prime.push_back(i);
                mnfac[i] = i;
            }
            for (int j = 0;(long long)prime[j] * i <= N;j++) {
                mnfac[prime[j] * i] = prime[j];
                if (i % prime[j] == 0)break;
            }
        }
    }
};