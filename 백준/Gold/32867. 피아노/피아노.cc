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
#define viii vector<vector<vector<int>>>
#define vpii vector<pair<int, int>>

#define YES "YES"
#define NO "NO"

const int MOD = 998244353;
const int INF = 1e18+2;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n+1);
    FOR(i, 1, n, 1) cin >> a[i];

    int res = 0, l = a[1], r = a[1];
    FOR(i, 2, n, 1) {
        l = min(l, a[i]), r = max(r, a[i]);
        if (r-l+1 > k) res++, l = r = a[i];
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}