#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m, k, x; cin >> n >> m >> k >> x;
    vector<int> graph[n+1];
    for (int i = 0 ;i<m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> dist(n+1, INF), vis(n+1, 0);
    queue<int> q; q.push(x);
    vis[x] = 1, dist[x] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v : graph[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v); 
            }
        }
    }

    //for (int i = 1; i<=n; i++) cout << dist[i] << " \n"[i==n];

    vector<int> res;
    for (int i = 1; i<=n; i++) {
        if (dist[i] == k) res.push_back(i);
    }

    if (res.empty()) cout << -1 << endl;
    else {
        for (auto u : res) cout << u << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}