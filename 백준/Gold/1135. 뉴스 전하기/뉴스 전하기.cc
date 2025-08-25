#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

const int MAXN = 50;
vector<int> graph[MAXN], dp(MAXN);
void dfs(int u) {
    dp[u] = (u > 0);
    vector<int> p;
    for (auto v : graph[u]) {
        dfs(v);
        p.push_back(dp[v]);
    }
    sort(p.rbegin(), p.rend());
    if (!p.empty()) {
        int cur = 0;
        for (int i = 0; i<p.size(); i++) {
            cur = max(cur, p[i]+i);
        }
        dp[u] += cur;
    }
}

void solve() {
    int n, t; cin >> n >> t;
    for (int i = 1; i<n; i++) {
        int x; cin >> x;
        graph[x].push_back(i);
    }

    dfs(0);
    cout << dp[0] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}