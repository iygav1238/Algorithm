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
    int n, s; cin >> n >> s;
    vi w(n+1), t(n+1);
    FOR(i, 1, n, 1) cin >> w[i];
    FOR(i, 1, n, 1) cin >> t[i];

    vi graph[n+1];
    FOR(i, 1, n, 1) {
        int p; cin >> p;
        graph[p].push_back(i);
    }

    int sum = accumulate(w.begin()+1, w.end(), 0LL);
    if (sum < s) cout << -1 << endl;
    else {
        vi order(n+1), sub(n+1);
        int id = 0;
        function<void(int)> dfs = [&](int u) {
            order[u] = id++;
            sub[u] = 1;
            for (auto v : graph[u]) {
                dfs(v);
                sub[u] += sub[v];
            }
        };
        dfs(0);
        
        vi re(n+1);
        FOR(i, 0, n, 1) re[order[i]] = i;

        vii dp(n+2, vi(s+1, INF));
        dp[n+1][0] = 0;
        FOR(i, n, 0, -1) {
            FOR(j, 0, s, 1) {
                dp[i][j] = min(t[re[i]]+dp[i+1][max(0LL, j-w[re[i]])], dp[i+sub[re[i]]][j]);
            }
        }
        cout << dp[0][s] << endl;
    }    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}