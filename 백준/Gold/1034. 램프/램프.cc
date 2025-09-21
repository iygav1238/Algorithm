#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i<n; i++) {
        string s; cin >> s;
        for (int j = 0; j<m; j++) a[i][j] = s[j]-'0';
    }
    int k; cin >> k;

    int res = 0;
    for (int i = 0; i<n; i++) {
        vector<int> use(m, 0);
        int tot = 0, cur = 0;
        for (int j = 0; j<m; j++) {
            if (a[i][j] == 0) {
                use[j] = 1; tot++;
                for (int r = 0; r<n; r++) a[r][j] ^= 1;
            }
        }

        if (tot <= k) {
            for (int I = 0; I<n; I++) {
                bool ok = true;
                for (int J = 0; J<m; J++) {
                    if (a[I][J] == 0) ok = false;
                }
                cur += ok;
            }

            int rest = k - tot;
            if (rest%2 == 0) res = max(res, cur);
        } 

        for (int j = 0; j<m; j++) {
            if (use[j]) {
                for (int r = 0; r<n; r++) a[r][j] ^= 1;
            }
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}