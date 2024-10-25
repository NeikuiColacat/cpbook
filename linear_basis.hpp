struct linear_basis{
    vector<i64> bvec;
    void insert(i64 ai){
        for (i32 i = 63; i >= 0; i--) {
            if (ai >> i & 1) {
                if (bvec[i]) ai ^= bvec[i];
                else {
                    bvec[i] = ai;
                    break;
                }
            }
        }
    }
    i64 qrymx(){
        i64 res = 0;
        for(i32 i = 63;i>=0;i--){
            res = max(res , bvec[i] ^ res);
        }
        return res;
    }
    i64 qrymn(){
        i64 res = 0;
        for(i32 i = 0;i<=64;i++){
            if(bvec[i]) return res;
        }
        return res;
    }
    linear_basis() : bvec(64) {}
};