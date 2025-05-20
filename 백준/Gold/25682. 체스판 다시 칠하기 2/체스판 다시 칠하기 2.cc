#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int n, m, k;
int cal(vector<vector<int>> a, int v) {
    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            int cur = ((i%2==j%2) ? v : (v ^ 1));
            pre[i][j] = (a[i][j] != cur);
            if (i > 0) pre[i][j] += pre[i-1][j];
            if (j > 0) pre[i][j] += pre[i][j-1];
            if (min(i, j) > 0) pre[i][j] -= pre[i-1][j-1];
        }
    }

    int res = INF;
    for (int i = k; i<=n; i++) {
        for (int j = k; j<=m; j++) res = min(res, pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k]);
    }
    return res;
}

void solve() {
    cin >> n >> m >> k;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for (int i = 1; i<=n; i++) {
        string s; cin >> s;
        for (int j = 1; j<=m; j++) a[i][j] = (s[j-1] == 'B') ? 0 : 1;
    }

    cout << min(cal(a, 0), cal(a, 1));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}