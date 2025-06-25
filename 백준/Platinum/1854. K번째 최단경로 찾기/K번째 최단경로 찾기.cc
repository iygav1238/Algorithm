#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define heap priority_queue
#define pii pair<int, int>

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<pii> graph[n+1];
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<heap<int>> dist(n+1);
    heap<pii, vector<pii>, greater<pii>> pq;
    dist[1].push(0);
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if (c > dist[u].top()) continue;
        for (auto [v, w] : graph[u]) {
            int newc = c + w;
            if (dist[v].size() < k || (dist[v].size() == k && dist[v].top() > newc)){
                dist[v].push(newc);
                if (dist[v].size() > k) dist[v].pop();
                pq.push({newc, v});
            }
        }
    }

    for (int i = 1; i<=n; i++) {
        if (dist[i].size() < k) cout << -1 << endl;
        else cout << dist[i].top() << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}