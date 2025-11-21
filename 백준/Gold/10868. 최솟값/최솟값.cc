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

struct Segtree{
    vi tree;
    int LOG, SIZE;
    Segtree(int n, const vi &a) {
        LOG = (int)ceil(log2(n+1));
        SIZE = 1 << LOG;
        tree.assign(2*SIZE, INF);
        FOR(i, 1, n, 1) tree[i+SIZE] = a[i];
        FOR(i, SIZE-1, 1, -1) tree[i] = min(tree[2*i], tree[2*i+1]);
    }

    void update(int i, int x) {
        i += SIZE;
        tree[i] = x;
        while (i > 1) {
            i /= 2;
            tree[i] = min(tree[2*i], tree[2*i+1]);
        }
    }

    int query(int l, int r) {
        l += SIZE; r += SIZE;
        int res = INF;
        while (l <= r) {
            if (l & 1) res = min(res, tree[l]);
            if (~r & 1) res = min(res, tree[r]);
            l = (l+1)/2, r = (r-1)/2;
        }
        return res;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vi a(n+1);
    FOR(i, 1, n, 1) cin >> a[i];

    Segtree tree(n, a);
    FOR(i, 1, m, 1) {
        int l, r; cin >> l >> r;
        cout << tree.query(l, r) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}