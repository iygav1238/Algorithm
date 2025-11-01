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

const int MOD = 998244353;
const int INF = 1e18+2;

void solve() {
    int r, c; cin >> r >> c;
    vii a(11, vi(11)), b(11, vi(11));
    FOR(i, 1, 10, 1) {
        string s; cin >> s;
        FOR(j, 1, 10, 1) a[i][j] = (s[j-1] == 'o' ? 1 : 0);
    }

    FOR(i, 1, 10, 1) {
        bool ok = false;
        FOR(j, 1, 10, 1) ok |= a[i][j];
        if (ok) FOR(j, 1, 10, 1) b[i][j] = 1;
    }
    FOR(j, 1, 10, 1) {
        bool ok = false;
        FOR(i, 1, 10, 1) ok |= a[i][j];
        if (ok) FOR(i, 1, 10, 1) b[i][j] = 1;
    }

    int res = INF;
    FOR(i, 1, 10, 1) {
        FOR(j, 1, 10, 1) {
            if (b[i][j] == 0) res = min(res, abs(r-i) + abs(j-c));
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