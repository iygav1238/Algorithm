#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define heap priority_queue
#define tiii tuple<int, int, int>

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void solve() {
    int n, m, a, b, c, x, y; 
    cin >> n >> m >> x >> y >> a >> b >> c;
    vector<vector<int>> mp(n+2, vector<int>(m+2, INF)), d(n+2, vector<int>(m+2, INF));

    int X = 1, Y = 1;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] > mp[X][Y]) X = i, Y = j;
        }
    }

    d[x][y] = 0;
    heap<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push({0, x, y});
    while (!pq.empty()) {
        auto [cur, i, j] = pq.top(); pq.pop();
        if (cur > d[i][j]) continue;
        for (int D = 0; D<4; D++) {
            int nx = i + dx[D], ny = j + dy[D];
            int z = mp[nx][ny] - mp[i][j];
            if (abs(z) > c) continue;
            int cost = (z == 0 ? 1 : (z > 0 ? abs(z)*a : abs(z)*b));
            if (d[nx][ny] > cur + cost) {
                d[nx][ny] = cur + cost;
                pq.push({cur+cost, nx, ny});
            } 
        }
    }
    cout << (d[X][Y] == INF ? -1 : d[X][Y]) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}