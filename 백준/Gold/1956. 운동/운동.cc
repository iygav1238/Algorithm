#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int i = 1; i<=n; i++) dist[i][i] = 0;
    for (int k = 1; k<=n; k++) {
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int res = INF;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            if (i == j || dist[i][j] == INF) continue;
            if (dist[j][i] == INF) continue;
            res = min(res, dist[i][j] + dist[j][i]);
        }
    }
    cout << (res == INF ? -1 : res) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}