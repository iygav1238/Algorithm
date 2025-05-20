#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

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
    vector<tuple<int, int, int>> a;
    for (int i = 0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        a.push_back({w, u, v});
    }
    sort(a.begin(), a.end());

    vector<int> parent(n+1), res;
    for (int i = 0; i<=n; i++) parent[i] = i;

    for (auto [w, u, v] : a) {
        if (!find(parent, u, v)) {
            unionSet(parent, u, v);
            res.push_back(w);
        }
    }
    res.pop_back();

    cout << accumulate(res.begin(), res.end(), 0LL) << endl;
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}