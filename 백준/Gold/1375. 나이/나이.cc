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
    int n, m; cin >> n >> m;
    map<string, vector<string>> graph;
    FOR(i, 1, m, 1) {
        string u, v; cin >> u >> v;
        graph[u].push_back(v);
    }

    auto dfs = [&](string a, string b) {
        map<string, int> vis;
        vector<string> stk = {a};
        vis[a] = 1;
        while (!stk.empty()) {
            auto u = stk.back(); stk.pop_back();
            for (auto v : graph[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    stk.push_back(v);
                }
            }
        }
        return vis[b];
    };

    int q; cin >> q;
    vector<string> res(q+1);
    FOR(i, 1, q, 1) {
        string u, v; cin >> u >> v;
        int x = dfs(u, v); 
        int y = dfs(v, u);
        if (x > y) res[i] = u;
        else if (x < y) res[i] = v;
        else res[i] = "gg";
    }
    
    FOR(i, 1, q, 1) {
        cout << res[i];
        if (i < q) cout << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}