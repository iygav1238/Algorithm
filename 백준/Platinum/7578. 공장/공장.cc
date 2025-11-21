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

struct Segtree {
    vi tree;
    int LOG, SIZE;
    Segtree(int n) {
        LOG = (int)ceil(log2(n+1));
        SIZE = 1 << LOG;
        tree.assign(2*SIZE, 0);
    }

    void update(int i, int x) {
        i += SIZE;
        tree[i] += x;
        while (i > 1) {
            i /= 2;
            tree[i] += x;
        }
    }

    int query(int l, int r) {
        l += SIZE; r += SIZE;
        int res = 0;
        while (l <= r) {
            if (l & 1) res += tree[l];
            if (~r & 1) res += tree[r];
            l = (l+1)/2, r = (r-1)/2;
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n+1), b(n+1);
    FOR(i, 1, n, 1) cin >> a[i];
    FOR(i, 1, n, 1) cin >> b[i];


    map<int, int> mat;
    FOR(i, 1, n, 1) mat[a[i]] = i;

    Segtree tree(1e6+1);
    int res = 0;
    FOR(i, 1, n, 1) {
        int j = tree.query(mat[b[i]], 1e6);
        res += j;
        tree.update(mat[b[i]], 1);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}