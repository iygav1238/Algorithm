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
    int n, m; cin >> n >> m;
    vpii a(m+1);
    FOR(i, 1, m, 1) cin >> a[i].first >> a[i].second;
    sort(a.begin()+1, a.end());

    vi res(n+1, INF);
    res[0] = 0;
    FOR(i, 1, m, 1) {
        auto [k, s] = a[i];
        res[k] = min(res[k], s);
    }
    FOR(i, n-1, 1, -1) res[i] = min(res[i], res[i+1]);
    
    FOR(i, 1, m, 1) {
        auto [k, s] = a[i];
        FOR(j, k, n, 1) {
            if (res[j-k] != INF) res[j] = min(res[j], res[j-k]+s);
        }
    }
    FOR(i, n-1, 1, -1) res[i] = min(res[i], res[i+1]);
    FOR(i, 1, n, 1) cout << res[i] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}