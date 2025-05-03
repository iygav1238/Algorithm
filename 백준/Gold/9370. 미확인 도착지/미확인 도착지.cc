#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    dist[start] = 0;
    heap.push({0, start});

    while (!heap.empty()) {
        auto [current_distance, current_node] = heap.top(); heap.pop();
        for (auto [new_node, new_distance] : graph[current_node]) {
            int distance = current_distance + new_distance;
            if (distance < dist[new_node]) {
                dist[new_node] = distance;
                heap.push({distance, new_node});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, t; cin >> n >> m >> t;
    int s, g, h; cin >> s >> g >> h;

    graph.assign(n+1, {});
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<bool> res(n+1, false);
    for (int i = 0; i<t; i++) {
        int x; cin >> x;
        res[x] = true;
    }

    vector<int> sd = dijkstra(s, n);
    if (sd[g] > sd[h]) swap(g, h);

    vector<int> dist1 = dijkstra(g, n);
    vector<int> dist2 = dijkstra(h, n);

    for (int i = 1; i<=n; i++) {
        if (sd[i] != sd[g] + dist1[h] + dist2[i]) {
            res[i] = false;
        }
    }

    for (int i = 1; i<=n; i++) {
        if (res[i]) cout << i << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}