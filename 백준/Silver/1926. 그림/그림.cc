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
    vector<vector<int>> a(n+2, vector<int>(m+2, 0));
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) cin >> a[i][j];
    }

    int mx = 0, tot = 0;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if (a[i][j]) {
                tot++;
                int cur = 1;
                a[i][j] = 0;
                vector<pair<int, int>> st = {{i, j}};
                while (!st.empty()) {
                    auto [y, x] = st.back(); st.pop_back();
                    for (int d = 0; d<4; d++) {
                        int ny = y + dy[d], nx = x + dx[d];
                        if (a[ny][nx] == 1) {
                            cur++;
                            a[ny][nx] = 0;
                            st.push_back({ny, nx});
                        }
                    }
                }
                mx = max(mx, cur);
            }
        }
    }
    cout << tot << endl << mx << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}