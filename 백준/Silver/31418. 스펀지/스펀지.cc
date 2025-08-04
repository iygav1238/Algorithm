#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int w, h, k, t;
    cin >> w >> h >> k >> t;

    int res = 1;
    for (int _ = 0; _<k; _++) {
        int x, y; cin >> x >> y;
        int l = min(x-1, t);
        int r = min(w-x, t);
        int u = min(y-1, t);
        int d = min(h-y, t);
        int low = l+r+1;
        int high = u+d+1;
        res *= (low*high)%MOD;
        res %= MOD;
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}