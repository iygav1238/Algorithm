/*
    Author : iygav1238
    다익스트라에서 현재 노드에 도달하는 비용이 엄격히 작지 않아도 물의 양이 더 많으면
    지나갈 수 있도록 추가 처리하는 알고리즘
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

struct Compare {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        return get<1>(a) < get<1>(b);
    }
};

void solve() {
    int n, m; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    cin >> m;

    vector<pair<int, int>> graph[n+1], dist(n+1, {INF, 0});
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int s, t; cin >> s >> t;
    dist[s] = {0, a[s]};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> pq;
    pq.push({0, a[s], s});
    while (!pq.empty()) {
        auto [cost, water, u] = pq.top(); pq.pop();
        if (cost > dist[u].first || (cost == dist[u].first && water < dist[u].second)) continue;

        for (auto [v, w] : graph[u]) {
            int ncost = cost + w;
            int nwater = water + a[v];
            auto [x, y] = dist[v];
            if (ncost < x || (ncost == x && nwater > y)) {
                dist[v] = {ncost, nwater};
                pq.push({ncost, nwater, v});
            }
        }
    }
    if (dist[t].first == INF) cout << -1 << endl;
    else cout << dist[t].first << " " << dist[t].second << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}