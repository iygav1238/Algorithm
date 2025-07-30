#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n, m; cin >> n >> m;
    vector<int> graph[n+1], dist(n+1, -1), from[n+1];
    for (int i = 0; i<m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<pair<int, int>> q; q.push({1, 0});
    dist[1] = 0;
    while (!q.empty()) {
        auto [u, c] = q.front(); q.pop();
        for (auto v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u]+1;
                from[v].push_back(u);
                q.push({v, dist[v]});
            } else if (dist[u]+1 == dist[v]) from[v].push_back(u);
        }
    }

    int mx = 0;
    vector<int> level[n+1], order, visited(n+1, 0);
    q.empty(); q.push({n, 0});
    visited[n] = 1;
    while (!q.empty()) {
        auto [u, c] = q.front(); q.pop();
        order.push_back(u);
        level[c].push_back(u);
        mx = max(mx, c);
        for (auto v : from[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push({v, c+1});
            }
        }
    }

    int res = 1;
    for (int i = 1; i<mx; i++) {
        if (level[i].size() == 1) res = level[i][0];
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}