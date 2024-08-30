struct trie{
    i32 root = 0 , idx = 0;
    std::vector<vector<i32>> nex;
    std::vector<i32> cnt;

    trie(i32 siz)
        : nex(std::vector<std::vector<i32>>(siz + 10, std::vector<i32>(26))),
          cnt(std::vector<i32>(siz + 10)){}

    void add(string s) {
        i32 n = si(s) - 1, p = root;
        for (i32 i = 1; i <= n; i++) {
            i32 c = s[i] - 'a';
            if (nex[p][c] == 0) nex[p][c] = ++idx;
            p = nex[p][c];
            cnt[p]++;
        }
    }
};