#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<int> s(n), e(n);
    for (int i = 0; i<n; i++) {
        s[i] = a[i]-'0', e[i] = b[i]-'0';
    }

    vector<vector<int>> dp(n+1, vector<int>(10, 0));
    for (int i = n-1; i>=0; i--) {
        for (int j = 0; j<10; j++) {
            int x = (s[i]+j)%10;
            int rot = (e[i]-x+10)%10;
            int l = rot + dp[i+1][(j+rot)%10];
            int r = (x-e[i]+10)%10 + dp[i+1][j];
            dp[i][j] = min(l, r);
        }
    }
    cout << dp[0][0] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}