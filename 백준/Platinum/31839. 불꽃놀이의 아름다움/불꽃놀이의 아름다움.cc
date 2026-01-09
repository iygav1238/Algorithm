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
    vi a(n+1), graph[n+1];
    FOR(i, 1, n-1, 1) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    FOR(i, 1, n, 1) cin >> a[i];
    int sum = accumulate(a.begin()+1, a.end(), 0LL);

    vi sub(n+1), w(n+1), dp(n+1), dep(n+1);
    function<void(int, int)> dfs = [&](int u, int p) {
        dp[u] = w[u] = dep[u]*a[u];
        sub[u] = a[u];
        for (auto v : graph[u]) {
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
            sub[u] += sub[v];
            dp[u] += dp[v];
        }
    };

    vi res(n+1);
    function<void(int, int)> reroot = [&](int u, int p) {
        for (auto v : graph[u]) {
            if (v == p) continue;
            res[v] = res[u]+(sum-sub[v])-sub[v];
            reroot(v, u);
        }
    };

    dfs(1, 1);
    res[1] = dp[1];
    reroot(1, 1);

    int ans = *max_element(res.begin(), res.end());
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}