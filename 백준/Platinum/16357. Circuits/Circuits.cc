#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define T tuple<int, int, int, int>

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

template<typename NodeType,
         typename LazyType,
         typename F_Merge,
         typename F_Update,
         typename F_Composition>
struct LazySegTree { // 1-indexed
public:
    using A = NodeType;
    using B = LazyType;
    LazySegTree() : LazySegTree(0, A(), B()) {}
    explicit LazySegTree(int n, const A& e, const B& id)
        : n(n), e(e), id(id), lg(Log2(n)), sz(1 << lg), tree(sz << 1, e), lazy(sz, id) {}
    void Set(int i, const A& val) { tree[--i | sz] = val; }
    void Init() { for (int i = sz - 1; i; i--) Pull(i); }
    void Update(int i, const B& f) {
        --i |= sz;
        for (int j = lg; j; j--) Push(i >> j);
        Apply(i, f);
        for (int j = 1; j <= lg; j++) Pull(i >> j);
    }
    void Update(int l, int r, const B& f) {
        --l |= sz, --r |= sz;
        for (int i = lg; i; i--) {
            if (l >> i << i != l) Push(l >> i);
            if (r + 1 >> i << i != r + 1) Push(r >> i);
        }
        for (int L = l, R = r; L <= R; L >>= 1, R >>= 1) {
            if (L & 1) Apply(L++, f);
            if (~R & 1) Apply(R--, f);
        }
        for (int i = 1; i <= lg; i++) {
            if (l >> i << i != l) Pull(l >> i);
            if (r + 1 >> i << i != r + 1) Pull(r >> i);
        }
    }
    A Query(int i) {
        --i |= sz;
        for (int j = lg; j; j--) Push(i >> j);
        return tree[i];
    }
    A Query(int l, int r) {
        A L = e, R = e; --l |= sz, --r |= sz;
        for (int i = lg; i; i--) {
            if (l >> i << i != l) Push(l >> i);
            if (r + 1 >> i << i != r + 1) Push(r >> i);
        }
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) L = M(L, tree[l++]);
            if (~r & 1) R = M(tree[r--], R);
        }
        return M(L, R);
    }
private:
    const int n, lg, sz; const A e; const B id;
    vector<A> tree; vector<B> lazy;
    F_Merge M; F_Update U; F_Composition C;
    static int Log2(int n) {
        int ret = 0;
        while (n > 1 << ret) ret++;
        return ret;
    }
    void Apply(int i, const B& f) {
        tree[i] = U(f, tree[i]);
        if (i < sz) lazy[i] = C(f, lazy[i]);
    }
    void Push(int i) {
        Apply(i << 1, lazy[i]);
        Apply(i << 1 | 1, lazy[i]);
        lazy[i] = id;
    }
    void Pull(int i) {
        tree[i] = M(tree[i << 1], tree[i << 1 | 1]);
    }
};


using NodeType = int;
constexpr NodeType e = -INF;

using LazyType = int;
constexpr LazyType id = 0;

struct F_Merge {
    NodeType operator() (const NodeType& a, const NodeType& b) const {
        return max(a, b);
    }
};

struct F_Update {
    NodeType operator() (const LazyType& a, const NodeType& b) const {
        if (a == e) return e;
        return a + b;
    }
};

struct F_Composition {
    LazyType operator() (const LazyType& a, const LazyType& b) const {
        return a + b;
    }
};

int find(vector<int> &b, int x) {
    return lower_bound(b.begin(), b.end(), x) - b.begin()+1;
}

void solve() {
    int n; cin >> n;
    vector<T> a(n); vector<int> b;
    for (int i = 0; i<n; i++) {
        int ux, uy, vx, vy;
        cin >> ux >> uy >> vx >> vy;
        a[i] = {ux, uy, vx, vy};
        b.insert(b.end(), {uy, vy});
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int limit = b.size();

    vector<int> pre(limit+2, 0);
    vector<vector<int>> L(limit+2), R(limit+2);
    vector<pair<int, int>> line(n);
    for (int i = 0; i<n; i++) {
        auto& [ux, uy, vx, vy] = a[i];
        uy = find(b, uy), vy = find(b, vy);
        line[i] = {uy, vy};
        
        pre[vy]++, pre[uy+1]--;
        L[vy].push_back(i);
        R[uy].push_back(i);
    }
    
    LazySegTree<NodeType, LazyType, F_Merge, F_Update, F_Composition> ST(limit, e, id);
    for (int i = 1; i<=limit; i++) {
        pre[i] += pre[i-1];
        ST.Set(i, pre[i]);
    }
    ST.Init();

    int res = ST.Query(1, limit);
    for (int i = 1; i<=limit; i++) {
        for (auto j : L[i]) {
            auto [uy, vy] = line[j];
            ST.Update(vy, uy, -1);
        }

        res = max(res, pre[i] + ST.Query(1, limit));

        for (auto j : R[i]) {
            auto [uy, vy] = line[j];
            ST.Update(vy, uy, 1);
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