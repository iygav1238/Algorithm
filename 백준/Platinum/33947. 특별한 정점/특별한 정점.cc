#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int res;
const int MAXN = 2e5+1;
vector<int> graph[MAXN], special, dp;
void dfs(int u, int parent) {
    dp[u] = special[u];
    int cnt = 0;
    for (auto v : graph[u]) {
        if (v == parent) continue;
        dfs(v, u);
        cnt += dp[v];
    }

    if (cnt > 0) res += (cnt-1);
    if (cnt == 1) dp[u] = 1;
    else if (cnt > 1) dp[u] = 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    special.assign(n+1, 0); dp.assign(n+1, 0);
    for (int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i<=n; i++) cin >> special[i];

    res = 0;
    int root = 1;
    dfs(root, root);
    res += dp[root];

    cout << max(0LL, res - 1) << endl;
    
    return 0;
}