#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define vt vector

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void solve() {
    int n, m; cin >> n >> m;
    vt<string> a(n);
    for (auto &x : a) cin >> x;

    pair<int, int> R, B;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (a[i][j] == 'R') R = {i, j};
            else if (a[i][j] == 'B') B = {i, j};
        }
    }

    int level = 1;
    queue<tuple<int, int, int, int>> q;
    auto [i1, j1] = R; auto [i2, j2] = B;
    q.push({i1, j1, i2, j2});
    vt<vt<vt<vt<int>>>> dp(n, vt<vt<vt<int>>>(m, vt<vt<int>>(n, vt<int>(m, 523))));
    dp[i1][j1][i2][j2] = 0;
    while (!q.empty() && level <= 10) {
        int sz = q.size();
        for (int _ = 0; _<sz; _++) {
            auto [i1, j1, i2, j2] = q.front(); q.pop();
            //cout << "Cur : " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
            for (int d = 0; d<4; d++) {
                int x1 = i1 + dx[d], y1 = j1 + dy[d];
                int f1 = 0, f2 = 0, f3 = 0;
                while (a[x1][y1] != '#') {
                    if (a[x1][y1] == 'O') {
                        f1 = 1;
                        break;
                    }
                    if (x1 == i2 && y1 == j2) f3 = 1;
                    x1 += dx[d], y1 += dy[d];
                }
                int x2 = i2 + dx[d], y2 = j2 + dy[d];
                while (a[x2][y2] != '#') {
                    if (a[x2][y2] == 'O') {
                        f2 = 1;
                        break;
                    }
                    x2 += dx[d], y2 += dy[d];
                }
                x1 -= dx[d], x2 -= dx[d];
                y1 -= dy[d], y2 -= dy[d];

                if (x1 == x2 && y1 == y2) {
                    if (f3 == 1) {
                        x1 -= dx[d], y1 -= dy[d];
                    } else {
                        x2 -= dx[d], y2 -= dy[d];
                    }
                }

                if (f2 == 1) continue;
                else if (f1 == 1) {
                    cout << level << endl;
                    return;
                }
                else if (dp[x1][y1][x2][y2] > level) {
                    dp[x1][y1][x2][y2] = dp[i1][j1][i2][j2] + 1;
                    if (level < 10) q.push({x1, y1, x2, y2});
                }
                
            }
        }
        level++;
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}