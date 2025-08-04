#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1e10;

void view(const vector<int> &a) {
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
}

int n, LOG, SIZE;
vector<int> merge(const vector<int> &a, const vector<int> &b) {
    vector<int> res(4);
    res[0] = max(a[0], a[3]+b[0]);
    res[1] = max(b[1], a[1]+b[3]);
    res[2] = max({a[2], b[2], a[1]+b[0]});
    res[3] = a[3] + b[3];
    return res;
}

void init(vector<vector<int>> &tree, vector<int> &a) {
    for (int i = 1; i<=n; i++) {
        tree[SIZE+i] = {a[i], a[i], a[i], a[i]};
    }

    for (int i = SIZE-1; i>=1; i--) {
        tree[i] = merge(tree[2*i], tree[2*i+1]);
    }
}

int query(const vector<vector<int>> &tree, int l, int r) {
    l += SIZE; r += SIZE;
    vector<int> L = {-INF, -INF, -INF, 0}, R = {-INF, -INF, -INF, 0};
    while (l <= r) {
        if (l & 1) L = merge(L, tree[l]);
        if (~r & 1) R = merge(tree[r], R);
        l = (l+1)/2;
        r = (r-1)/2;
    }
    vector<int> res = merge(L, R);
    return res[2];
}

void solve() {
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];

    LOG = (int)ceil(log2(n+1));
    SIZE = 1 << LOG;
    vector<vector<int>> tree(2*SIZE, {-INF, -INF, -INF, 0});
    init(tree, a);

    int m; cin >> m;
    while (m--) {
        int i, j; cin >> i >> j;
        cout << query(tree, i, j) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}