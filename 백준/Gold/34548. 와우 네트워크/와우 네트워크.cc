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
    int n, m, t; cin >> n >> m >> t;
    vector<tuple<int, int, int>> a(m);
    for (int i = 0; i<m; i++) {
        int u, v, s; cin >> u >> v >> s;
        a[i] = {s, u, v};
    }
    sort(a.begin(), a.end());

    vector<int> parent(n+1);
    for (int i = 1; i<=n; i++) parent[i] = i;

    int res = 0, cur = n, time = 1;
    for (auto [s, u, v] : a) {
        res += cur*(s-time);
        if (!find(parent, u, v)) {
            cur--;
            unionSet(parent, u, v);
        }
        time = s;
    }
    res += cur*(t-time+1);
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}