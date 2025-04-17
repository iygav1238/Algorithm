/*
    Author : iygav1238
    전처리를 통해서 a[i][j] = (i, j)가 물이 되는 처음 날짜로 정한 다음, 
    어떤 백조에서 다른 백조로 이동할 때 이동하는 칸의 값들 중 최댓값이 최소가 되는 걸 다익스트라로 찾음
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> P;
    vector<vector<int>> a(n, vector<int>(m, INF)), dist(n, vector<int>(m, INF)), visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    char x;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> x;
            if (x == 'X') continue;
            if (x == 'L') P.push_back({i, j});
            q.push({i, j});
            a[i][j] = 0;
            visited[i][j] = 1;
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d<4; d++) {
            int y = i + dy[d], x = j + dx[d];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (visited[y][x] == 0) {
                visited[y][x] = 1;
                a[y][x] = a[i][j] + 1;
                q.push({y, x});
            }
        }
    }

    auto [y1, x1] = P[0];
    auto [y2, x2] = P[1];
  
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, y1, x1});
    while (!pq.empty()) {
        auto [c, i, j] = pq.top(); pq.pop();
        if (dist[i][j] < c) continue; 
        for (int d = 0; d<4; d++) {
            int y = i + dy[d], x = j + dx[d];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            int newc = max(c, a[y][x]);
            if (dist[y][x] > newc) {
                dist[y][x] = newc;
                pq.push({newc, y, x});
            }
        }
    }

    cout << dist[y2][x2] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}
