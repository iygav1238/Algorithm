#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i<=n; i++) cin >> a[i];

    vector<vector<int>> dp(n+1, {-INF, -INF, -INF, -INF});
    dp[0][0] = 0;
    for (int i = 1; i<=n; i++) {
        dp[i][0] = max(dp[i-1][3], dp[i-1][0]) + a[i];
        dp[i][1] = max(dp[i-1][3], dp[i-1][0]) + 2*a[i];
        if (i >= 2) dp[i][2] = dp[i-1][1] + 2*a[i];
        if (i >= 3) dp[i][3] = dp[i-1][2] + 2*a[i];
    }
    int res = *max_element(dp[n].begin(), dp[n].end());
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}