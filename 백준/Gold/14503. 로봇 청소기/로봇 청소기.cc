#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    int n, m; cin >> n >> m;
    int r, c, d; cin >> r >> c >> d;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cin >> a[i][j];
    }

    while (true) {
        //cout << r << " " << c << " " << d << endl;
        a[r][c] = 2;
        int chk = 0;
        for (int k = d+3; k>=d; k--) {
            int i = k%4;
            int x = r + dx[i], y = c + dy[i];
            if (a[x][y] == 0) {
                chk = 1;
                r = x, c = y, d = i;
                break;
            }
        }

        if (chk == 0) {
            r -= dx[d], c -= dy[d];
            if (a[r][c] == 1) break;
        }
        a[r][c] = 3;

        // for (int i = 0; i<n; i++) {
        //     for (int j = 0; j<m; j++) cout << a[i][j] << " \n"[j==m-1];
        // }
        // cout << endl;
    }
    int cnt = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cnt += (a[i][j] > 1);
    }
    cout << cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}