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

const int MOD = 998244353;
const int INF = 1e18+2;

void solve() {
    int n, c; cin >> n >> c;
    vi d(n+1), w(n+1), graph[n+1];
    FOR(i, 1, n, 1) cin >> d[i];
    FOR(i, 1, n, 1) cin >> w[i];
    FOR(i, 1, n-1, 1) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vii dp(n+1, vi(13));
    function<void(int, int)> dfs = [&](int u, int p) {
        dp[u][d[u]] = w[u];
        for (auto v : graph[u]) {
            if (v == p) continue;
            dfs(v, u);
            int mx = *max_element(dp[v].begin()+1, dp[v].end());
            FOR(i, 1, 12, 1) dp[u][i] += max(dp[v][i], mx-c);
        }
    };
    dfs(1, 1);

    int res = *max_element(dp[1].begin()+1, dp[1].end());
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}