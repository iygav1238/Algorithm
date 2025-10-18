#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define V vector

const int MOD = 998244353;
const int INF = 1000000000000000002LL;


void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> a(n+1, V<int>(m+1));
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) cin >> a[i][j];
    }

    int res = -INF;
    V<V<V<int>>> dp(n+2, V<V<int>>(m+2, {-INF, -INF, -INF}));
    dp[1][1] = {a[1][1], a[1][1], a[1][1]};
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if (i == 1 && j == 1) continue;
            int up = max({dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2]});
            if (up != -INF) dp[i][j][0] = up + a[i][j];

            int l = max(dp[i][j-1][0], dp[i][j-1][1]);
            if (l != -INF) dp[i][j][1] = l + a[i][j];
        }

        for (int j = m; j>=1; j--) {
            int r = max(dp[i][j + 1][0], dp[i][j + 1][2]);
            if (r != -INF)  dp[i][j][2] = r + a[i][j];
        }

        for (int j = 1; j<=m; j++) {
            int mx = max({dp[i][j][0], dp[i][j][1], dp[i][j][2]});
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = mx;
        }
    }

    res = max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}