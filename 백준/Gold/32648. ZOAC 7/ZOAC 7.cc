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
    auto f = [](char x) {
        if (x == 'Z') return 0;
        if (x == 'O') return 1;
        if (x == 'A') return 2;
        return 3;
    };
    int n, m; cin >> n >> m;
    vii a(n+1, vi(m+1));
    FOR(i, 1, n, 1) FOR(j, 1, m, 1) {
        char x; cin >> x;
        a[i][j] = f(x);
    }

    viii dp1(n+1, vii(m+1, vi(4))), dp2(n+1, vii(m+1, vi(4)));
    FOR(i, 1, n, 1) FOR(j, 1, m, 1) {
        FOR(k, 0, 3, 1) dp1[i][j][k] = max(dp1[i-1][j][k], dp1[i][j-1][k]);
        dp1[i][j][a[i][j]]++;
    }
    FOR(i, 1, n, 1) FOR(j, 1, m, 1) {
        FOR(k, 0, 3, 1) {
            dp2[i][j][k] = max({dp2[i-1][j][k], dp2[i][j-1][k], dp1[i-1][m][k], dp1[n][j-1][k]});
        }
        dp2[i][j][a[i][j]]++;
    }
    
    FOR(k, 0, 3, 1) cout << max(dp1[n][m][k], dp2[n][m][k]) << " \n"[k==3];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}