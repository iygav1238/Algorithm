#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int INF = 1e9;

struct SegTree {
    int sz;
    vector<int> tree;
    SegTree(int n) {
        int LOG = (int)ceil(log2(n));
        sz = 1 << LOG;
        tree.assign(2*sz, INF);
    }

    void update(int i, int x) {
        i += sz;
        tree[i] = x;
        while (i > 1) {
            i /= 2;
            tree[i] = min(tree[2*i], tree[2*i+1]);
        }
    }

    int query(int l, int r) {
        l = max(0LL, l); r = max(0LL, r);
        l += sz; r += sz;
        int res = INF;
        while (l <= r) {
            if (l & 1) res = min(res, tree[l++]);
            if (!(r & 1)) res = min(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

void solve() {
    int n, x, k; cin >> n >> x >> k;
    vector<int> a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];

    SegTree tree(n+1);
    tree.update(0, 0);
    int cnt = 0;
    for (int i = 1; i<=n; i++) {
        if (a[i] == 1) cnt = 0;
        else cnt++;

        if (i == n) {
            int low = tree.query(i-x, i-1);
            if (low == INF) cout << -1 << endl;
            else cout << low+1 << endl;
        } else if (cnt >= k) {
            int low = tree.query(i-x, i-k);
            if (low != INF) tree.update(i, low+1);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}