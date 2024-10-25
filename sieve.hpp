struct sieve {
    const i32 N;
    vector<i32> prime , mnfac;
    sieve(i32 siz) : N(siz), mnfac(vector<i32>(N + 10)) {
        for (i32 i = 2;i <= N;i++) {
            if (!mnfac[i]) {
                prime.push_back(i);
                mnfac[i] = i;
            }
            for (i32 j = 0;(i64)prime[j] * i <= N;j++) {
                mnfac[prime[j] * i] = prime[j];
                if (i % prime[j] == 0)break;
            }
        }
    }
};