#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    string s1, s2; cin >> s1 >> s2;
    s1 = " " + s1, s2 = " " + s2;
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<m; j++) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n-1][m-1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}