/*
    Author : iygav1238
    전형적인 다익스트라 경로 역추적
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> graph[m];
    for (int i = 0; i<n; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> dist(m, INF), from(m, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if (dist[u] < c) continue;
        for (auto [v, w] : graph[u]) {
            int cost = c + w;
            if (cost < dist[v]) {
                dist[v] = cost;
                from[v] = u;
                pq.push({cost, v});
            }
        }
    }

    if (dist[m-1] == INF) cout << -1 << endl;
    else {
        vector<int> res;
        int cur = m-1;
        while (cur != 0) {
            res.push_back(cur);
            cur = from[cur];
        }
        res.push_back(0);
        for (int i = res.size()-1; i>=0; i--) cout << res[i] << " \n"[i==0];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i<=t; i++) {
        cout << "Case #" << i <<": ";
        solve(); 
    }    
    return 0;
}