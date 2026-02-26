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
#define vpii vector<pair<int, int>>

#define YES "YES"
#define NO "NO"
    
const int MOD = 998244353;
const int INF = 1e18+2;

void solve() {
    int n; cin >> n;
    vi a(n+1), idx(n+1);
    FOR(i, 1, n, 1) cin >> a[i], idx[a[i]] = i;

    vi cycle[n+1], vis(n+1);
    int id = 0, ok = 0;
    FOR(i, 1, n, 1) {
        if (vis[a[i]]) continue;
        vi stk = {a[i]};
        vis[a[i]] = 1;
        cycle[++id].push_back(a[i]);
        while (!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            if (!vis[a[u]]) {
                vis[a[u]] = 1;
                cycle[id].push_back(a[u]);
                stk.push_back(a[u]);
            }
        }
        int m = cycle[id].size();
        ok += m%2;
    }

    cout << YES << endl;

    vpii F, S;
    vi odd;
    FOR(i, 1, id, 1) {
        int m = cycle[i].size();
        if (m & 1) odd.push_back(i);
    }

    int z = odd.size();
    FOR(i, 0, z-2, 2) {
        int j = i+1;
        int u = cycle[odd[i]].back(), v = cycle[odd[j]].back();
        F.push_back({u, v});
        for (auto x : cycle[odd[j]]) cycle[odd[i]].push_back(x);
        cycle[odd[j]].clear();
    }

    FOR(i, 1, id, 1) {
        int m = cycle[i].size();
        if (m & 1) {
            S.push_back({cycle[i][0], cycle[i][1]});
            S.push_back({cycle[i][0], cycle[i][2]});
            if (m > 3) {
                F.push_back({cycle[i][2], cycle[i][m-1]});
                int x = cycle[i].back();
                FOR(j, 3, m-1, 2) {
                    if (x != cycle[i][j+1]) F.push_back({cycle[i][j+1], x});
                    S.push_back({cycle[i][j], cycle[i][j+1]});
                }
            }
        } else if (m > 0) {
            int x = cycle[i].back();
            FOR(j, 0, m-1, 2) {
                if (x != cycle[i][j+1]) F.push_back({cycle[i][j+1], x});
                S.push_back({cycle[i][j], cycle[i][j+1]});
            }
        }
    }

    cout << F.size() << endl;
    for (auto [i, j] : F) {
        if (i > j) swap(i, j);
        cout << i << " " << j << endl;
    }
    cout << S.size() << endl;
    for (auto [i, j] : S) {
        if (i > j) swap(i, j);
        cout << i << " " << j << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}