#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cin >> a[i][j];
    }

    int res = INF;
    for (int cur = 0; cur<(1 << n); cur++) {
        int cnt = 0;
        for (int i = 0; i<n; i++) {
            if (cur & (1 << i)) {
                for (int j = 0; j<n; j++) a[i][j] ^= 1;
                cnt++;
            }
        }
        int c1 = 0, c2 = 0;
        for (int j = 0; j<n; j++) {
            int sum = 0;
            for (int i = 0; i<n; i++) sum += a[i][j];
            
            c1 += min(n-sum, 1+sum);
            c2 += min(sum, 1 + n-sum);
        }
        cnt += min(c1, c2);
        res = min(res, cnt);
        for (int i = 0; i<n; i++) {
            if (cur & (1 << i)) {
                for (int j = 0; j<n; j++) a[i][j] ^= 1;
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