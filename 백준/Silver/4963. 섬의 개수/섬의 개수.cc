#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int n, m;
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void solve() {
    vector<vector<int>> a(n+2, vector<int>(m+2, 0));
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) cin >> a[i][j];
    }

    int tot = 0;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if (a[i][j] == 1) {
                tot++;
                int cur = 1;
                a[i][j] = 0;
                vector<pair<int, int>> st = {{i, j}};
                while (!st.empty()) {
                    auto [y, x] = st.back(); st.pop_back();
                    for (int d = 0; d<8; d++) {
                        int ny = y + dy[d], nx = x + dx[d];
                        if (a[ny][nx] == 1) {
                            cur++;
                            a[ny][nx] = 0;
                            st.push_back({ny, nx});
                        }
                    }
                }
            }
        }
    }

    cout << tot << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (1) {
        cin >> m >> n;
        if (n == 0 && m == 0) break;
        solve();    
    }
    return 0;
}