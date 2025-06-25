#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define Vec vector

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1}; 

void solve() {
    int n, m; cin >> n >> m;
    Vec<string> a(n+2);
    queue<tuple<int, int, int>> q;
    pair<int, int> start;
    
    string inits(m+2, '#');
    a[0] = a[n+1] = inits;
    for (int i = 1; i<=n; i++) {
        string s; cin >> s;
        s = string("#") + s + "#";
        a[i] = s;
        for (int j = 1; j<=m; j++) {
            if (s[j] == '0') {
                start = {i, j}; 
                a[i][j] = '.';
                q.push({i, j, 0});
            }
        }
    }

    //for (auto x : a) cout << x << endl;

    auto [si, sj] = start;
    Vec<Vec<Vec<int>>> dist(n+2, Vec<Vec<int>>(m+2, Vec<int>(1 << 7, INF)));
    dist[si][sj][0] = 0;
    while (!q.empty()) {
        auto [i, j, key] = q.front(); q.pop();
        //cout << "cur : " << i << " " << j << " " << key << endl;
        //cout << "dist : " << dist[i][j][key] << endl;
        for (int d = 0; d<4; d++) {
            int y = i + dy[d], x = j + dx[d];
            int newkey = key;
            if (a[y][x] == '#') continue;
            if (a[y][x] == '.') {
                
            } else if (a[y][x] == '1') {
                dist[y][x][newkey] = min(dist[y][x][newkey], dist[i][j][newkey]+1);
            } else if ('a' <= a[y][x] && a[y][x] <= 'f') {
                int k = a[y][x] - 'a';
                newkey |= (1 << k);
            } else {
                int k = a[y][x] - 'A';
                if (!(newkey & (1 << k))) continue;
            }
            //cout << "PUT " << y << " " << x << endl;
            //cout << "HMM : " << dist[y][x][newkey] << " " << dist[i][j][key] + 1 << endl;
            if (dist[y][x][newkey] > dist[i][j][key] + 1) {
                dist[y][x][newkey] = dist[i][j][key] + 1;
                q.push({y, x, newkey});
            }
        }
    }

    int res = INF;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if (a[i][j] != '1') continue;
            for (int k = 0; k < (1 << 7); k++) {
                res = min(res, dist[i][j][k]);
            }
        }
    }
    
    cout << (res == INF ? -1 : res) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}