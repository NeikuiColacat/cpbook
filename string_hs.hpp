struct string_hs {
    const i32 modnum, P;
    vector<i32> hs, pw;
    string_hs(i32 siz, string s, i32 MOD = 1e9 + 7, i32 pp = 131)
        : hs(siz + 1), pw(siz + 1, 1), modnum(MOD), P(pp) {
        for (i32 i = 1; i <= siz; i++) {
            pw[i] = (i64)pw[i - 1] * P % modnum;
            hs[i] = ((i64)hs[i - 1] * P + s[i]) % modnum;
        }
    }

    i32 qry(i32 l, i32 r) {
        return (hs[r] - (i64)hs[l - 1] * pw[r - l + 1] % modnum + modnum) %
               modnum;
    }
};