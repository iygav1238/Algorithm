#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> graph[n+1];
    for (int i = 0; i<m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int res = 1;
    vector<int> color(n+1, -1), p;
    for (int i = 1; i<=n; i++) {
        if (color[i] != -1) continue;
        color[i] = 0;
        p = {i};
        while (!p.empty()) {
            int u = p.back(); p.pop_back();
            for (auto v : graph[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    p.push_back(v);
                } else if (color[v] == color[u]) res = 0;
            }
        }
    }
    
    cout << (res ? "possible" : "impossible") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}