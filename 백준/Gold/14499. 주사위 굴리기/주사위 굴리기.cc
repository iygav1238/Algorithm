#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void mov(vector<int>& cur, int d) {
    if (d == 1) {
        swap(cur[4], cur[5]);
        swap(cur[5], cur[2]);
        swap(cur[2], cur[0]);
    } else if (d == 2) {
        swap(cur[0], cur[2]);
        swap(cur[5], cur[2]);
        swap(cur[5], cur[4]);
    } else if (d == 3) {
        swap(cur[1], cur[2]);
        swap(cur[2], cur[3]);
        swap(cur[3], cur[4]);
    } else {
        swap(cur[3], cur[4]);
        swap(cur[2], cur[3]);
        swap(cur[1], cur[2]);
    }
}

void solve() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cin >> a[i][j];
    }

    vector<int> cur(6, 0);
    while (k--) {
        int d; cin >> d;
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        x = nx, y = ny;

        mov(cur, d);

        if (a[x][y] == 0) {
            a[x][y] = cur[4];
        }
        else {
            cur[4] = a[x][y];
            a[x][y] = 0;
        }

        //for (int i = 0; i<6; i++) cout << cur[i] << " \n"[i==5];
        cout << cur[2] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}