#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cin >> a[i][j];
    }

    for (int res = 0; res<2020; res++) {
        bool mov = false;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (!vis[i][j]) {
                    int tot = 0;
                    vector<pair<int, int>> order, st;
                    st.push_back({i, j});
                    vis[i][j] = 1;
                    while (!st.empty()) {
                        auto [y, x] = st.back(); st.pop_back();
                        order.push_back({y, x});
                        tot += a[y][x];
                        for (int d = 0; d<4; d++) {
                            int ny = y + dy[d], nx = x + dx[d];
                            if (0 > nx || n <= nx || 0 > ny || n <= ny) continue;
                            if (vis[ny][nx]) continue;
                            int diff = abs(a[ny][nx] - a[y][x]);
                            if (l <= diff && diff <= r) {
                                st.push_back({ny, nx});
                                vis[ny][nx] = 1;
                            }
                        }
                    }
                    int sz = order.size();
                    if (sz > 1) {
                        mov = true;
                        tot /= sz;
                        for (auto [y, x] : order) a[y][x] = tot;
                    }
                }
            }
        }

        if (!mov) { cout << res << endl; return; }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}