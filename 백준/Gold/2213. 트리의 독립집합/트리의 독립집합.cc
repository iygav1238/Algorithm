#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

const int MAXN = 10101;
vector<int> a(MAXN+1), graph[MAXN+1], res;
vector<vector<int>> dp(MAXN, {0, 0});
void dfs1(int u, int p) {
    dp[u][0] = a[u];
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u][0] += dp[v][1];
        dp[u][1] += max(dp[v][0], dp[v][1]);
    }
}

void dfs2(int u, int p, int puse=0) {
    int use = 0;
    if (!puse && dp[u][0] > dp[u][1]) {
        use = 1;
        res.push_back(u); 
    }
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs2(v, u, use);
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs1(1, 1); dfs2(1, 1);
    sort(res.begin(), res.end());
    cout << max(dp[1][0], dp[1][1]) << endl;
    for (auto x : res) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}