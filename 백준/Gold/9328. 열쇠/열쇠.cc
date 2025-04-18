#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int res;
bool chk(char x, int i, int j, vector<bool>& hav, map<char, vector<pair<int, int>>>& door) {
    if (x == '.') return true;
    else if (x == '$') {
        res++;
        return true;
    }
    else if (islower(x)) {
        hav[x-'a'] = true;
        return true;
    }
    else if (isupper(x)) {
        if (hav[tolower(x) - 'a']) return true;
        door[x].push_back({i, j});
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n+2, vector<char>(m+2, '*'));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }

    vector<bool> hav(26, false);
    string s; cin >> s;
    if (s != "0") {
        for (auto x : s) hav[x-'a'] = true;
    }

    res = 0;
    map<char, vector<pair<int, int>>> door;
    vector<vector<bool>> visited(n+2, vector<bool>(m+2, false));

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        if (chk(a[i][1], i, 1, hav, door)) {q.push({i, 1}); a[i][1] = '.'; visited[i][1] = true;}
        if (chk(a[i][m], i, m, hav, door)) {q.push({i, m}); a[i][m] = '.'; visited[i][m] = true;}
    }
    for (int j = 1; j <= m; j++) {
        if (chk(a[1][j], 1, j, hav, door)) {q.push({1, j}); a[1][j] = '.'; visited[1][j] = true;}
        if (chk(a[n][j], n, j, hav, door)) {q.push({n, j}); a[n][j] = '.'; visited[n][j] = true;}
    }

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int y = i + dy[d], x = j + dx[d];
            if (visited[y][x] || (a[y][x] == '*')) continue;
            if (isupper(a[y][x]) && !hav[towlower(a[y][x])-'a']) {
                door[a[y][x]].push_back({y, x});
            } else {
                if (islower(a[y][x])) {
                    hav[a[y][x] - 'a'] = true;
                    for (auto [cy, cx] : door[toupper(a[y][x])]) {
                        if (!visited[cy][cx]) {
                            visited[cy][cx] = true;
                            q.push({cy, cx});
                        }
                    }
                }
                if (a[y][x] == '$') res++;
                a[y][x] = '.';
                visited[y][x] = true;
                q.push({y, x});
            }
            
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}
