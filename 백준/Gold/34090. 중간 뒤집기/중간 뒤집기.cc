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

void solve() {
    int n; cin >> n;
    vi a(n+1);
    FOR(i, 1, n, 1) cin >> a[i];

    map<int, vi> idx;
    FOR(i, 1, n, 1) idx[a[i]].push_back(i);

    int res = n*(n+1)/2;
    for (auto &[_, p] : idx) {
        int c = p.size();
        res -= c*(c+1)/2;
    }
    cout << res+1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}