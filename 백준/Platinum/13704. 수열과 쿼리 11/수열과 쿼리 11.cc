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

const int MAXN = 1e6+1;
int SQRT;
struct cmp {
    bool operator()(const tiii &a, const tiii &b) const {
        if (get<0>(a)/SQRT != get<0>(b)/SQRT) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vi a(n+1), pre(n+1, 0);
    FOR(i, 1, n, 1) {
        cin >> a[i];
        pre[i] = pre[i-1] ^ a[i];
    }

    SQRT = sqrt(n);

    int m; cin >> m;
    vector<tiii> query(m+1);
    FOR(i, 1, m, 1) {
        int s, e; cin >> s >> e;
        query[i] = {s, e, i};
    }
    sort(query.begin()+1, query.end(), cmp());

    vi res(m+1), XOR(1 << 21);
    int l = 1, r = 0, cnt = 0;

    auto Plus = [&](int i) {
        cnt += XOR[pre[i] ^ k];
        XOR[pre[i]]++;
    };

    auto Minus = [&](int i) {
        XOR[pre[i]]--;
        cnt -= XOR[pre[i] ^ k];
    };
    
    FOR(i, 1, m, 1) {
        auto [s, e, x] = query[i];
        while (r < e) Plus(++r);
        while (r > e) Minus(r--);
        while (l < s-1) Minus(l++);
        while (l > s-1)  Plus(--l);
        res[x] = cnt;
    }

    FOR(i, 1, m, 1) cout << res[i] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}