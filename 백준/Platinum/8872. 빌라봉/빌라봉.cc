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
    int n, m, l; cin >> n >> m >> l;
    vector<vpii> graph(n+1);
    FOR(i, 1, m, 1) {
        int s, e, x; cin >> s >> e >> x;
        graph[s].push_back({e, x});
        graph[e].push_back({s, x});
    }

    vi dp(n+1, 0), dist(n+1, -1);
    function<void(int, int)> dfs = [&](int u, int p) {
        dp[u] = 0;
        for (auto [v, w] : graph[u]) {
            if (v == p) continue;
            dfs(v, u);
            dp[u] = max(dp[u], dp[v] + w);
        }
    };

    function<void(int, int, int)> reroot = [&](int u, int p, int x) {
        dist[u] = max(dp[u], x);

        vpii child;
        child.push_back({x, -1});
        for (auto [v, w] : graph[u]) {
            if (v == p) continue;
            child.push_back({dp[v] + w, v});
        }
        sort(child.rbegin(), child.rend());

        for (auto [v, w] : graph[u]) {
            if (v == p) continue;
            int nxt;
            if (child[0].second != v) nxt = child[0].first + w;
            else nxt = child[1].first + w;
            reroot(v, u, nxt);
        }
    };

    auto GetRadius = [&](int node) {
        vi comp;
        queue<int> q; q.push(node);
        vector<bool> vis(n+1, false);
        vis[node] = true;
        
        int i = 0;
        comp.push_back(node);
        while(i < comp.size()){
            int u = comp[i++];
            for (auto [v, w] : graph[u]) {
                if (!vis[v] && dist[v] == -1) {
                    vis[v] = true;
                    comp.push_back(v);
                }
            }
        }

        dfs(node, -1);
        reroot(node, -1, 0);

        int radius = INF, diameter = 0;
        for (int u : comp) {
            radius = min(radius, dist[u]);
            diameter = max(diameter, dist[u]);
        }
        return make_pair(radius, diameter);
    };

    vi radii;
    int ori = 0;
    FOR(i, 1, n, 1) {
        if (dist[i] == -1) { 
            auto [r, d] = GetRadius(i);
            radii.push_back(r);
            ori = max(ori, d);
        }
    }
    sort(radii.rbegin(), radii.rend());

    if (radii.size() == 1) cout << ori << endl;
    else {
        int c1 = radii[0] + radii[1] + l;
        int c2 = 0;
        if(radii.size() >= 3) c2 = radii[1] + radii[2] + 2*l;
        cout << max({ori, c1, c2}) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}