#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int tot = accumulate(a.begin(), a.end(), 0LL);
    int ave = tot/n;

    for (int i = 0; i<n; i++) a.push_back(a[i]);

    int res = 0, cur = 0;
    for (int i = 0; i<2*n; i++) {
        int d = a[i]-ave;
        if (d > 0) {
            cur += d;
            if (i < n) a[i+n] = ave;
        } else {
            if (i < n) a[i+n] += min(cur, abs(d));
            cur -= min(cur, abs(d));
        }
        res += cur;
    }
    cout << res << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}