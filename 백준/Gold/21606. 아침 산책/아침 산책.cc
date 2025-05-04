#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int res;
const int MAXN = 2e5+1;
vector<int> graph[MAXN], a(MAXN), dp(MAXN, 0);
void dfs(int u, int p) {\
    int tot = 0;
    vector<int> cur, pre;
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        cur.push_back(dp[v]);
        tot += dp[v];
    }
    if (a[u] == 1) {
        res += tot;
        dp[u] = 1;
    } else {
        if (cur.size() > 1) {
            pre.push_back(cur[0]);
            for (int i = 1; i<cur.size(); i++) {
                pre.push_back(pre.back() + cur[i]);
            }

            for (int i = cur.size()-1; i>0; i--) {
                res += cur[i]*pre[i-1];
            }
        }
        dp[u] = tot;
    }
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i<=n; i++) a[i] = s[i-1] - '0';
    for (int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    res = 0;
    dfs(1, 1);
    cout << 2*res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}