#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define FOR(i, a, b, c) for (int i = a; (c > 0 ? i<=b : i>=b); i+=c)

#define heap priority_queue
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define viii vector<vector<vector<int>>>
#define vpii vector<pair<int, int>>

#define YES "YES"
#define NO "NO"

const int MOD = 1e9+9;
const int INF = 1e18+2;

void solve() {
    int n, m; cin >> n >> m;
    vii dp(n+1, vi(m+1)), dist(n+1, vi(m+1, INF));
    dp[1][1] = 1, dist[1][1] = 0;

    vi dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    vi dy = {-1, -2, -2, -1, 1, 2, 2, 1};
    
    heap<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push({0, 1, 1});
    while (!pq.empty()) {
        auto [c, i, j] = pq.top(); pq.pop();
        if (dist[i][j] < c) continue;
        FOR(d, 0, 7, 1) {
            int x = i+dx[d], y = j+dy[d];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (dist[x][y] > c+1) {
                dist[x][y] = c+1;
                dp[x][y] = dp[i][j];
                pq.push({c+1, x, y});
            } else if (dist[x][y] == c+1) dp[x][y] = (dp[x][y] + dp[i][j])%MOD;
        }
    }

    if (dp[n][m] == 0) cout << "None" << endl;
    else cout << dist[n][m] << " " << dp[n][m] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}