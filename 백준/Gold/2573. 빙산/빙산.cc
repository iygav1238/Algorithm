#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cin >> a[i][j];
    }

    int res = 1;
    while (1) {
        bool update = false;

        vector<vector<int>> b = a;
        for (int i = 1; i<n-1; i++) {
            for (int j = 1; j<m-1; j++) {
                if (a[i][j] == 0) continue;
                int tot = 0;
                for (int d = 0; d<4; d++) {
                    int ny = i + dy[d], nx = j + dx[d];
                    tot += (a[ny][nx] == 0);
                }
                if (tot) {
                    update = true;
                    b[i][j] = max(0LL, b[i][j] - tot);
                }
            }
        }

        int maps = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 1; i<n-1; i++) {
            for (int j = 1; j<m-1; j++) {
                if (b[i][j] == 0 || vis[i][j]) continue;

                maps++;
                vector<pair<int, int>> st;
                st.push_back({i, j});
                vis[i][j] = 1;
                while (!st.empty()) {
                    auto [y, x] = st.back(); st.pop_back();
                    for (int d = 0; d<4; d++) {
                        int ny = y + dy[d], nx = x + dx[d];
                        if (!vis[ny][nx] && b[ny][nx]) {
                            vis[ny][nx] = 1;
                            st.push_back({ny, nx});
                        }
                    }
                }
            }
        }

        if (maps > 1) { cout << res << endl; return; }
        if (!update) { cout << 0 << endl; return; }
        swap(a, b);
        res++;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}