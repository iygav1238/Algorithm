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

const int MOD = 1e9+7;
const int INF = 1e18+2;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n+1), b(n+1);
    FOR(i, 1, n, 1) cin >> a[i] >> b[i];

    vii dp(n+1, vi(3001));
    FOR(i, a[1], b[1], 1) dp[1][i] = 1;
    FOR(i, 2, n, 1) {
        vi pre(3001);
        pre[0] = dp[i-1][0];
        FOR(j, 1, 3000, 1) pre[j] = (pre[j-1] + dp[i-1][j]%MOD)%MOD;

        FOR(j, a[i], b[i], 1) {
            int l = max(a[i-1], j-k), r = min(b[i-1], j+k);
            dp[i][j] = (dp[i][j] + (pre[r]-pre[l-1]+MOD)%MOD)%MOD;
        }
    }

    int res = 0;
    FOR(i, 0, 3000, 1) res = (res + dp[n][i])%MOD;
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}