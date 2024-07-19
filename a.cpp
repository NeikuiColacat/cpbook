/**
 *  author: NeikuiColacat
 *  created: 19.07.2024 22:38:13
**/
#include <bits/stdc++.h>
#define fi first
#define se second
#define si(x) ((i32)x.size())
using std::cout, std::cin, std::endl;
using std::max, std::min, std::swap, std::vector, std::string;
using i32 = int32_t;
using i64 = int64_t;
using P = std::pair<i32,i32>;

void solve() {
    i32 n;cin >> n;

    vector a(n+1 , 0);
    for (i32 i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    vector dp(n + 1 , 0ll);
    dp[n] = a[n] > 0 ? 0 : 1;

    auto chk = [&](i32 mid) {

    };

    for (i32 i = n; i >= 1; i--) {
        i32 lo = i , hi = n;
        while (lo < hi) {
            i32 mid = (lo + hi + 1) >> 1;

            if (chk(mid)) lo = mid;
            else hi = mid - 1;


        }
    }
}

signed main() {
    std ::ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    i32 t;cin >> t;
    while (t--) solve();
    return 0;
}