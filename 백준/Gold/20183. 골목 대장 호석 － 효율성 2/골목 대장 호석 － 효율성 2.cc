#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define FOR(i, a, b, c) for (int i = a; (c > 0 ? i<=b : i>=b); i+=c)

#define heap priority_queue
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define viii vector<vector<vector<int>>>
#define vpii vector<pair<int, int>>

#define YES "YES"
#define NO "NO"

const int MOD = 998244353;
const int INF = 1e18+2;

void solve() {
    int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
    vpii graph[n+1];
    FOR(i, 1, m, 1) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    auto ok = [&](int k) {
        vi cost(n+1, INF);
        cost[a] = 0;
        heap<pii, vpii, greater<pii>> pq;
        pq.push({0, a});
        while (!pq.empty()) {
            auto [c, u] = pq.top(); pq.pop();
            if (cost[u] < c) continue;
            for (auto [v, w] : graph[u]) {
                if (w > k) continue;
                int nc = c + w;
                if (cost[v] > nc) {
                    cost[v] = nc;
                    pq.push({nc, v});
                }
            }
        }
        return cost[b] <= c;
    };

    int l = 1, r = 1e9+1;
    while (l < r) {
        int mid = (l+r)/2;
        if (ok(mid)) r = mid;
        else l = mid+1;
    }
    if (r > 1e9) cout << -1 << endl;
    else cout << r << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}