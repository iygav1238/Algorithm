#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1}; 

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> a(n+2, vector<int>(m+2, 2));
    for (int i = 1; i<=n; i++) {
        string s; cin >> s;
        for (int j = 1; j<=m; j++) a[i][j] = s[j-1]-'0';
    }

    // for (int i = 0; i<n+2; i++) {
    //     for (int j = 0; j<m+2; j++) cout << a[i][j] << " \n"[j==m+1];
    // }

    vector<vector<vector<int>>> dp(n+2, vector<vector<int>>(m+2, vector<int>(k+1, INF)));
    queue<tuple<int, int, int>> q;
    dp[1][1][0] = 1;
    q.push({0, 1, 1});
    while (!q.empty()) {
        auto [c, i, j] = q.front(); q.pop();
        //cout << "Cur : " << i << " " << j << " cnt : " << c << endl;
        for (int d = 0; d<4; d++) {
            int x = i + dx[d], y = j + dy[d];
            int f = a[x][y];
            if (a[x][y] < 2) {
                if (a[x][y] == 1 && c == k) continue;
                if (dp[x][y][c+f] > dp[i][j][c] + 1) {
                    dp[x][y][c+f] = dp[i][j][c] + 1;
                    q.push({c+f, x, y});
                    //cout << "push ! " << c+f << " " << x << " " << y << endl;
                }
            }
        }
    }

    int res = *min_element(dp[n][m].begin(), dp[n][m].end());
    cout << (res == INF ? -1 : res) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}