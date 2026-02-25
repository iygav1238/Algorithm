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

#define viii vector<vector<vector<int>>>

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n+1);
    FOR(i, 1, n, 1) {
        string s; cin >> s;
        a[i] = " " + s + " ";
    }
    string s; cin >> s;
    int q = s.size();

    pii mn, yg, goal;
    FOR(i, 1, n, 1) {
        FOR(j, 1, m, 1) {
            if (a[i][j] == 'Y') mn = {i, j};
            if (a[i][j] == 'F') yg = {i, j};
            if (a[i][j] == 'X') goal = {i, j};
        }
    }

    function<pii(char)> dir = [](char c) -> pii {
        if (c == 'S') return {1, 0};
        if (c == 'N') return {-1, 0};
        if (c == 'E') return {0, 1};
        return {0, -1}; 
    };

    function<pii(pii, pii)> pos = [&](pii cur, pii d) -> pii {
        int nx = cur.first + d.first, ny = cur.second + d.second;
        if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '#') return cur;
        return {nx, ny};
    };

    viii dp(q+1, vii(n+1, vi(m+1, INF)));
    auto [x1, y1] = mn;
    auto [x2, y2] = yg;
    auto [x3, y3] = goal;
    FOR(k, 0, q, 1) dp[k][x3][y3] = 0;

    FOR(k, q-1, 0, -1) {
        FOR(i, 1, n, 1) {
            FOR(j, 1, m, 1) {
                if (a[i][j] == '#' || a[i][j] == 'X') continue;
                auto [x, y] = pos({i, j}, dir(s[k]));
                dp[k][i][j] = min({dp[k+1][i][j], dp[k+1][x][y]});
                if (dp[k][i][j] != INF) dp[k][i][j]++;
            }
        }
    }

    int res = -1;
    FOR(k, 0, q-1, 1) {
        if (dp[k][x1][y1] < dp[k][x2][y2]) {
            cout << k << endl;
            return;
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