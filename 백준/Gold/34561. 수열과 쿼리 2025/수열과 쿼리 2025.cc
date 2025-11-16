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

int getParent(vi& parent, int x) {
    if (parent[x] != x) {
        parent[x] = getParent(parent, parent[x]);
    }
    return parent[x];
}

void unionSet(vi& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find(vi& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    return a == b;
}

void solve() {
    int n; cin >> n;
    vi a(n+1);
    FOR(i, 1, n, 1) cin >> a[i];
    int m; cin >> m;

    vii idx(3e5+1);
    vi rep(3e5+1, 0), parent(n+1), res(n+1);
    FOR(i, 1, n, 1) {
        idx[a[i]].push_back(i);
        if (rep[a[i]] == 0) rep[a[i]] = i;
        parent[i] = i;
        res[i] = a[i];
    }

    FOR(i, 1, 3e5, 1) {
        if (!idx[i].empty()) {
            int s = idx[i].size();
            FOR(j, 0, s-2, 1) unionSet(parent, idx[i][j], idx[i][j+1]);
        }
    }

    while (m--) {
        int w; cin >> w;
        if (w == 1) {
            int x, y; cin >> x >> y;
            if (rep[x] > 0 && x != y) {
                int i = rep[x];
                if (rep[y] > 0) {
                    int j = rep[y];
                    unionSet(parent, i, j);
                }

                rep[y] = getParent(parent, i);
                rep[x] = 0;
                res[getParent(parent, i)] = y;
            }
        } else {
            int z; cin >> z;
            cout << res[getParent(parent, z)] << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}