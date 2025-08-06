#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define Vec vector

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m; cin >> n >> m;
    Vec<Vec<int>> a(n+1, Vec<int>(m+1, 0));
    for (int i = 1; i<=n; i++) {
        string s; cin >> s;
        for (int j = 0; j<m; j++) a[i][j+1] = s[j]-'0';
    }

    int res = 0;
    Vec<Vec<int>> dp(n+1, Vec<int>(m+1, 0));
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if (a[i][j]) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            } else dp[i][j] = 0;
            res = max(res, dp[i][j]);
        }
    }
    cout << res*res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}