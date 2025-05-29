#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

struct Segtree {
    int tree[1 << 20];
    int size = 1 << 19;

    void update(int i) {
        i += size;
        tree[i]++;
        while (i > 1) {
            i /= 2;
            tree[i]++;
        }
    }

    int query(int i) {
        int l = size + i+1, r = 2*size-1;
        int res = 0;
        while (l <= r) {
            if (l & 1) res += tree[l++];
            if (~r & 1) res += tree[r--];
            l /= 2;
            r /= 2;
        }
        return res;
    }

} tree;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b;
    for (auto &x : a) cin >> x;
    b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int &x : a) x = lower_bound(b.begin(), b.end(),x) - b.begin() + 1;

    int res = 0;
    for (auto x : a) {
        res += tree.query(x);
        tree.update(x);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}