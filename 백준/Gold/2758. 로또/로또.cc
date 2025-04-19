/*
    Author : iygav1238
    let dp[i][j] = i번째 수가 j인 경우의 수
    dp 전이 : i-1번째 수가 1인 경우의 수 + 2인 경우의 수 + ... + j/2인 경우의 수
    dp[i][j] = sum(dp[i-1][k])(1 <= k <= j/2), 누적합으로 최적화 총 O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    vector<int> pre(m+1, 0);
    for (int i = 1; i<=m; i++) {
        dp[0][i] = 1;
        pre[i] = pre[i-1] + dp[0][i];
    }
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<=m; j++) dp[i][j] = pre[j/2];
        for (int j = 1; j<=m; j++) pre[j] = pre[j-1] + dp[i][j];
    }
    cout << pre[m] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}