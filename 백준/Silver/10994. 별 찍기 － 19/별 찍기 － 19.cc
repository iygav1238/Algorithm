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
    int m = 4*(n-1) + 1;
    vii a(m+1, vi(m+1, 0));
    FOR(i, 1, m, 1) {
        FOR(j, 1, m, 1) {
            int l = j, r = m+1-j, u = i, d = m+1-i;
            int mn = min({l, r, u, d});
            if (mn & 1) a[i][j] = 1;
        }
    }

    FOR(i, 1, m, 1) {
        FOR(j, 1, m, 1) cout << (a[i][j] ? "*" : " ");
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}