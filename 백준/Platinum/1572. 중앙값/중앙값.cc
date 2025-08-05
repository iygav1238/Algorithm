#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int MAX = 65536;
struct Segtree {
    int LOG, SIZE;
    vector<int> tree;
    Segtree(int n) {
        LOG = (int)ceil(log2(n+1));
        SIZE = 1 << LOG;
        tree.assign(2*SIZE, 0);
    }

    void update(int i, int x=1) {
        i += SIZE;
        tree[i] += x;
        while (i > 1) {
            i /= 2;
            tree[i] += x;
        }
    }

    int query(int x) {
        int i = 1;
        while (i < SIZE) {
            int l = tree[2*i], r = tree[2*i+1];
            if (l < x) {
                x -= tree[2*i];
                i = 2*i + 1;
            } else i *= 2;
        }
        return i - SIZE;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];

    Segtree tree(MAX);
    int res = 0;
    for (int i = 1; i<=n; i++) {
        tree.update(a[i]);
        if (i >= k) {
            res += tree.query((k+1)/2);
            tree.update(a[i-k+1], -1);
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