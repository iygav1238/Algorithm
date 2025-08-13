#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 1e9+7;
const int INF = 1000000000000000002LL;

struct Segtree{
    int LOG, SIZE, N;
    vector<int> tree;
    Segtree(int n) {
        N = n;
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
            l = (l+1)/2;
            r = (r-1)/2;
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int MAXN = 2e5, res = 1;
    Segtree tree(MAXN), cnt(MAXN);
    tree.update(a[0], a[0]); cnt.update(a[0], 1);
    for (int i = 1; i<n; i++) {
        int l = tree.query(0, a[i]-1), r = tree.query(a[i], MAXN);
        int cl = cnt.query(0, a[i]-1), cr = cnt.query(a[i], MAXN);
        int cost = ((a[i]*cl - l + r - a[i]*cr)%MOD + MOD)%MOD;
        res = (res*cost)%MOD;
        tree.update(a[i], a[i]); cnt.update(a[i], 1);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}