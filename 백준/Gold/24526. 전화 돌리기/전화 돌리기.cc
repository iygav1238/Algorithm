#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> graph[n+1], degree(n+1, 0), dp(n+1, 0);
    for (int i = 0; i<m; i++) {
        int u, v; cin >> u >> v;
        graph[v].push_back(u);
        degree[u]++;
    }

    queue<int> q;
    for (int i = 1; i<=n; i++) {
        if (degree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        dp[u] = 1;
        for (auto v : graph[u]) {
            degree[v]--;
            if (degree[v] == 0) q.push(v);
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}