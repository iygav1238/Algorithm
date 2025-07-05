#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define heap priority_queue
#define pii pair<int, int>

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int n, m, s, d, res = -1;
vector<vector<pii>> dijkstra(const vector<vector<pii>>& graph) {
    vector<int> dist(n, INF);
    vector<vector<pii>> node(n);
    heap<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s}); dist[s] = 0;
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if (dist[u] < c) continue;
        for (auto [v, w] : graph[u]) {
            int newc = c + w;
            if (dist[v] > newc) {
                dist[v] = newc;
                node[v] = {{u, w}};
                pq.push({newc, v});
            } else if (dist[v] == newc) node[v].push_back({u, w});
        }
    }
    res = dist[d];
    return node;
} 

void solve() {
    cin >> s >> d;
    vector<vector<pii>> graph(n);
    map<tuple<int, int, int>, int> valid;
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        valid[{u, v, w}] = 1;
    }

    vector<vector<pii>> node = dijkstra(graph);
    vector<int> st = {d}, vis(n, 0);
    vis[d] = 1;
    while (!st.empty()) {
        auto u = st.back(); st.pop_back();
        for (auto [v, w] : node[u]) {
            tuple<int, int, int> cur = {v, u, w};
            if (valid[cur]) {
                valid[cur] = 0;
                if (vis[v] == 0) {
                    vis[v] = 1;
                    st.push_back({v});
                }
            }
        }
    }

    graph.assign(n, {});
    for (auto &[k, x] : valid) {
        if (x == 1) {
            auto [u, v, w] = k;
            graph[u].push_back({v, w});
        }
    }

    res = INF;
    dijkstra(graph);
    cout << (res == INF ? -1 : res) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (1) {
        cin >> n >> m;
        if (n+m == 0) break;
        solve();  
    }
    return 0;
}