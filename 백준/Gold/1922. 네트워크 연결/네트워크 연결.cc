#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define tiii tuple<int, int, int>

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int getParent(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = getParent(parent, parent[x]);
    }
    return parent[x];
}

void unionSet(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    return a == b;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<tiii> edges(m);
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());

    int res = 0;
    vector<int> parent(n+1, 0);
    for (int i = 1; i<=n; i++) parent[i] = i;
    for (auto [w, u, v] : edges) {
        if (!find(parent, u, v)) {
            unionSet(parent, u, v);
            res += w;
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}