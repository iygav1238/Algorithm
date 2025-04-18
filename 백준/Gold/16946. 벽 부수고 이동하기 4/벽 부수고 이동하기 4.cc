#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MAXN = 1010;
int n, m;
vector<vector<int>> a(MAXN, vector<int>(MAXN, 1));
vector<vector<int>> res(MAXN, vector<int>(MAXN, 0));
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, 0));

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void dfs(int i, int j){

    //cout << "cur : " << i << " " << j << endl;
    visited[i][j] = 1;
    vector<pair<int, int>> st;
    st.push_back({i, j});
    int cnt = 1;
    set<pair<int, int>> wall;
    while (!st.empty()){
        auto [y, x] = st.back(); st.pop_back();
        for (int d = 0; d<4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if (a[ny][nx] == 0 && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                cnt++;
                st.push_back({ny, nx});
            } else if (a[ny][nx] == 1) wall.insert({ny, nx});
        }
    }
    //cout << "size: " << cnt << endl;
    for (auto [i, j] : wall) {
        //cout << "Wall: " << i << " " << j << endl;
        res[i][j] += cnt;
    }
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i<=n; i++) {
        string s; cin >> s;
        for (int j = 1; j<=m; j++) a[i][j] = s[j-1]-'0';
        // for (int j = 1; j<=m; j++) cout << a[i][j] << " \n"[j==m];
    }
    
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if (a[i][j] == 0 && !visited[i][j]) dfs(i, j);
        }
    }

    // for (int i = 1; i<=n; i++) {
    //     for (int j = 1; j<=m; j++) cout << visited[i][j] << " \n"[j==m];
    // }

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            if (a[i][j] == 1) res[i][j]++;
            cout << res[i][j]%10;
        }
        cout << endl;
    }

    return 0;
}