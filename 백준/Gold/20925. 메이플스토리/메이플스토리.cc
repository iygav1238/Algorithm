#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, T; cin >> n >> T;
    vector<pair<int, int>> a(n);
    for (int i = 0; i<n; i++) cin >> a[i].first >> a[i].second;

    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cin >> dist[i][j];
    }

    vector<vector<int>> dp(T+1, vector<int>(n, -1));
    for (int i = 0; i<n; i++) {
        if (a[i].first == 0) dp[0][i] = 0;
    }

    for (int i = 0; i<T; i++) {
        for (int j = 0; j<n; j++) {
            if (dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[j].second);
            for (int k = 0; k<n; k++) {
                if (a[k].first > dp[i][j]) continue;
                int time = i + dist[j][k];
                if (time <= T) dp[time][k] = max(dp[time][k], dp[i][j]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i<n; i++) {
        if (dp[T][i] == -1) continue;
        res = max(res, dp[T][i]);
    }
    cout << res << endl;

    return 0;
}