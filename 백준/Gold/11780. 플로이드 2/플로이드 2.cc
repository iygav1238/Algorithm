#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF)), path(n+1, vector<int>(n+1, -1));
    for (int i = 1; i<=n; i++) dist[i][i] = 0;
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (dist[u][v] > w) {
            dist[u][v] = w;
            path[u][v] = u;
        }
    }

    for (int k = 1; k<=n; k++) {
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " \n"[j==n];
    }
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            if (dist[i][j] == INF || i == j) cout << 0 << endl;
            else {
                vector<int> res;
                int cur = j;
                while (cur != i) {
                    res.push_back(cur);
                    cur = path[i][cur];
                }
                res.push_back(cur);
                reverse(res.begin(), res.end());
                cout << res.size() << " ";
                for (auto x : res) cout << x << " \n"[x == j];
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}