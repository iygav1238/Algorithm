#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
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

    void init(vector<int> &a) {
        for (int i = 1; i<=N; i++) tree[SIZE+i] = a[i-1];
        for (int i = SIZE-1; i>=1; i--) tree[i] = tree[2*i] + tree[2*i+1];
    }

    void update(int i, int x) {
        i += SIZE;
        tree[i] = x;
        while (i > 1) {
            i /= 2;
            tree[i] = tree[2*i] + tree[2*i+1];
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
    vector<int> a(n+1), b(n, 1), idx(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }

    Segtree tree(n);
    tree.init(b);
    int l = 1, r = n;
    while (l < r) {
        int i = idx[l], j = idx[r];
        cout << tree.query(1, i-1) << endl;
        tree.update(i, 0);
        cout << tree.query(j+1, n) << endl;
        tree.update(j, 0);
        l++, r--;
    }
    if (n & 1) cout << 0 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}