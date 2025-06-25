#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

const int MAXN = 10001;
int dep;
vector<int> graph[MAXN], order(MAXN, 0), res(MAXN, 0);
int dfs(int u, int root) {
    order[u] = ++dep;
    int cur = order[u];
    int child = 0;
    for (int v : graph[u]) {
        if (!order[v]) {
            child++;
            int df = dfs(v, 0);
            if (!root&&df >= order[u]) res[u] = 1;
            cur = min(cur, df);
        }
        else cur = min(cur, order[v]);
    }

    if (root && child > 1) res[u] = 1;
    return cur;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i<=n; i++) {
        if (!order[i]) dfs(i, 1);
    }
    int tot = accumulate(res.begin(), res.end(), 0LL);
    cout << tot << endl;
    for (int i = 1; i<=n; i++) {
        if (res[i]) cout << i << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}