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
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 1; i<=n; i++) {
        for (int l = 0; l+i-1 < n; l++) {
            int r = l+i-1;
            if (l == r) {
                dp[l][r] = ((n & 1) ? a[l] : 0);
            } else {
                int turn = ((r-l+1)%2 == n%2);
                if (turn) {
                    dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r]);
                } else {
                    dp[l][r] = min(dp[l+1][r], dp[l][r-1]);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}