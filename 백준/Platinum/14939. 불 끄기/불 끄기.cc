#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

const int n = 10;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void solve() {
    vector<vector<int>> a(n, vector<int>(n)), b;
    for (int i = 0; i<n; i++) {
        string s; cin >> s;
        for (int j = 0; j<n; j++) a[i][j] = (s[j] == 'O');
    }

    int res = INF;
    for (int cur = 0; cur<(1 << n); cur++) {
        b = a;
        int cnt = 0;
        for (int j = 0; j<n; j++) {
            if (cur & (1 << j)) {
                b[0][j] ^= 1;
                cnt++;
                for (int d = 0; d<4; d++) {
                    int y = 0+dy[d], x = j+dx[d];
                    if (0 <= y && y < n && 0 <= x && x < n){
                        b[y][x] ^= 1;
                    }
                }
            }
        }

        for (int i = 1; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (b[i-1][j] == 1) {
                    cnt++;
                    b[i][j] ^= 1;
                    for (int d = 0; d<4; d++) {
                        int y = i+dy[d], x = j+dx[d];
                        if (0 <= y && y < n && 0 <= x && x < n){
                            b[y][x] ^= 1;
                        }
                    }
                }
            }    
        }
        int ok = accumulate(b[n-1].begin(), b[n-1].end(), 0LL);
        if (ok == 0) res = min(res, cnt);
    }
    cout << (res == INF ? -1 : res) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}