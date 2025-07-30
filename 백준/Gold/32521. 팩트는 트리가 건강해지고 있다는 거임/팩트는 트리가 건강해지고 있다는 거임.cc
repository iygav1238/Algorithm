#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MAXN = 1e5+1;
int n, k, res;
vector<int> a(MAXN, 0), graph[MAXN], sub(MAXN, 0);
int dfs(int u, int p) {
    sub[u] = a[u];
    int tot = 0;
    vector<int> lst;
    for (auto v : graph[u]) {
        if (v == p) continue;
        int w = dfs(v, u);
        lst.push_back(w);
        tot += w;
    }
    sort(lst.begin(), lst.end());
    while (tot + a[u] > k) {
        res++;
        tot -= lst.back(); lst.pop_back();
    }
    sub[u] += tot;
    return sub[u];
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    res = 0;
    dfs(1, 1);

    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}