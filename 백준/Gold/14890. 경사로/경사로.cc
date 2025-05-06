#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, l; cin >> n >> l;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cin >> a[i][j];
    }

    int res = 0;
    for (int i = 0; i<n; i++) {
        int chk = 1;
        vector<int> use(n, 0);
        for (int j = 1; j<n; j++) {
            if (a[i][j] > a[i][j-1]) {
                if (a[i][j] - a[i][j-1] >= 2) chk = 0;
                else {
                    if (j < l) chk = 0;
                    else {
                        for (int k = j-l; k<j; k++) {
                            if (use[k] == 1) chk = 0;
                            else use[k] = 1;
                        }
                    }
                }
            } else if (a[i][j] < a[i][j-1])  {
                if (a[i][j-1] - a[i][j] >= 2) chk = 0;
                else {
                    if (j+l > n) chk = 0;
                    else {
                        for (int k = j; k<j+l; k++) {
                            if (use[k] == 1 || a[i][k] != a[i][j]) chk = 0;
                            else use[k] = 1;
                        }
                    }
                }
            }
        }
        res += chk;
    }

    for (int j = 0; j<n; j++) {
        int chk = 1;
        vector<int> use(n, 0);
        for (int i = 1; i<n; i++) {
            if (a[i][j] > a[i-1][j]) {
                if (a[i][j] - a[i-1][j] >= 2) chk = 0;
                else {
                    if (i < l) chk = 0;
                    else {
                        for (int k = i-l; k<i; k++) {
                            if (use[k] == 1) chk = 0;
                            else use[k] = 1;
                        }
                    }
                }
            } else if (a[i][j] < a[i-1][j])  {
                if (a[i-1][j] - a[i][j] >= 2) chk = 0;
                else {
                    if (i+l > n) chk = 0;
                    else {
                        for (int k = i; k<i+l; k++) {
                            if (use[k] == 1) chk = 0;
                            else use[k] = 1;
                        }
                    }
                }
            }
        }
        res += chk;
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}