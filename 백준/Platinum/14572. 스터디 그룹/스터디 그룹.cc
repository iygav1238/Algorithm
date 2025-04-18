#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

struct SegTree {
    vector<vector<int>> tree;
    int size = 1 << 17;

    SegTree() {
        tree.assign(1 << 18, {0, 0});
    }

    void update(int i, int v) {
        int x = i + size;
        tree[x] = {v, v};
        while (x > 1) {
            x /= 2;
            tree[x][0] = (tree[2*x][0] & tree[2*x+1][0]);
            tree[x][1] = (tree[2*x][1] | tree[2*x+1][1]);
        }
    }

    int query(int l, int r) {
        l += size, r += size;
        int OR = 0, AND = (1 << 31) -1;
        while (l <= r) {
            if (l & 1) {
                AND &= tree[l][0];
                OR |= tree[l][1];
            }
            if (~r & 1) {
                AND &= tree[r][0];
                OR |= tree[r][1];
            }
            l = (l+1)/2, r = (r-1)/2;
        }
        return __builtin_popcount(OR-AND);
    }
} tree;

void solve() {
    int N, K, D; cin >> N >> K >> D;
    vector<pair<int, int>> a;
    for (int i = 0; i<N; i++) {
        int m, d; cin >> m >> d;
        int stat = 0;
        for (int j = 0; j<m; j++) {
            int x; cin >> x;
            stat |= (1 << x);
        }
        a.push_back({d, stat});
    }
    sort(a.begin(), a.end());

    int res = 0, ptr = 0;
    for (int i = 0; i<N; i++) {
        auto [d, stat] = a[i];
        while (a[ptr].first < d-D) ptr++;
        tree.update(i, stat);
        res = max(res, tree.query(ptr, i)*(i-ptr+1));
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}