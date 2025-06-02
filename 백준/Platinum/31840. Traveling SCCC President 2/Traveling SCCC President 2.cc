#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define pii pair<int, int>

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int n, m;
const int MAXN = 3e5+1;
vector<pii> graph[MAXN];
vector<int> shift;
bool chk() {
    vector<bool> visited(n+1, false);
    queue<pii> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [u, c] = q.front(); q.pop();
        for (auto [v, w] : graph[u]) {
            if (visited[v]) continue;
            
            bool ok = true;
            for (auto x : shift) {
                if (w & (1LL << x)) ok = false;
            }
            if (ok) {
                visited[v] = true;
                q.push({v,  w | c});
            }
        }
    }
    return visited[n];
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int res = 0;
    for (int i = 59; i>=0; i--) {
        shift.push_back(i);
        if (!chk()) {
            shift.pop_back();
            res |= (1LL << i);
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}