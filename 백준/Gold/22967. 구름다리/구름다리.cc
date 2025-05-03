#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    vector<int> graph[n+1];
    for (int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<pair<int, int>> res;
    if (n <= 4) {
        for (int i = 1; i<=n; i++) {
            for (int j = i+1; j<=n; j++) {
                if (find(graph[i].begin(), graph[i].end(), j) == graph[i].end()) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                    res.push_back({i, j});
                }
            }
        }
        cout << res.size() << endl;
        cout << 1 << endl;
        for (auto [u, v] : res) cout << u << " " << v << endl;
    } else {
        for (int i = 2; i<=n; i++) {
            if (find(graph[1].begin(), graph[1].end(), i) == graph[1].end()) {
                res.push_back({1, i});
            }
        }
        cout << res.size() << endl;
        cout << 2 << endl;
        for (auto [u, v] : res) cout << u << " " << v << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}