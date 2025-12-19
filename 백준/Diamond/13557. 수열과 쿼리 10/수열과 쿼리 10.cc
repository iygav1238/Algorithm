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

struct Node {
    int l, r, mx, tot;
    Node(int l, int r, int mx, int tot) : l(l), r(r), mx(mx), tot(tot) {}
};
 
Node id(-INF, -INF, -INF, 0);
 
struct GMT {
    vector<Node> tree;
    int LOG, SIZE;
    GMT (int n, const vi &a) {
        LOG = (int)ceil(log2(n+1));
        SIZE = 1 << LOG;
        tree.assign(2*SIZE, id);
        Init(n, a);
    }
 
    Node Merge(const Node &a, const Node &b) {
        if (a.mx == -INF) return b;
        if (b.mx == -INF) return a;
        int l = max(a.l, a.tot + b.l);
        int r = max(b.r, b.tot + a.r);
        int mx = max({a.mx, b.mx, a.r+b.l});
        int tot = a.tot + b.tot;
        return Node(l, r, mx, tot);
    }
 
    void Init(int n, const vi &a) {
        FOR(i, 1, n, 1) tree[SIZE+i] = Node(a[i], a[i], a[i], a[i]);
        FOR(i, SIZE-1, 1, -1) tree[i] = Merge(tree[2*i], tree[2*i+1]);
    }

    void Update(int i, int x) {
        i += SIZE;
        tree[i] = Node(x, x, x, x);
        while (i > 1) {
            i /= 2;
            tree[i] = Merge(tree[2*i], tree[2*i+1]);
        }
    }
 
    Node Query(int l, int r) {
        l += SIZE, r += SIZE;
        Node s = id, e = id;
        while (l <= r) {
            if (l & 1) s = Merge(s, tree[l]);
            if (~r & 1) e = Merge(tree[r], e);
            l = (l+1)/2, r = (r-1)/2;
        }
        return Merge(s, e);
    }
};

void solve() {
    int n; cin >> n;
    vi a(n+1);
    FOR(i, 1, n, 1) cin >> a[i];

    GMT G(n, a);
    int m; cin >> m;
    while (m--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (y1 < x2) {
            int l = G.Query(x1, y1).r;
            int r = G.Query(x2, y2).l;
            int mid = G.Query(y1+1, x2-1).tot;
            cout << l+r+mid << endl;
        } else {
            int res = G.Query(x2, y1).mx;
            res = max(res, G.Query(x1, x2-1).r + G.Query(x2, y2).l);
            res = max(res, G.Query(x1, y1).r + G.Query(y1+1, y2).l);
            res = max(res, G.Query(x1, x2-1).r + G.Query(x2, y1).tot + G.Query(y1+1, y2).l);
            cout << res << endl;
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}