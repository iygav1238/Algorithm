#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int n;
void solve() {
    vector<int> a(n+1), dp(n+2, 0), pre(n+1, 0);
    for (int i = n; i >= 1; i--) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i];
 
    for (int i = n; i>=1; i--) {
        int tmp = INF;
        for (int j = i; j<=n; j++) {
            tmp = min(tmp, pre[j] - pre[i-1] - dp[j+1]);
        }
        dp[i] = tmp;
    }

    if (dp[1] < 0) cout << "A" << endl;
    else if (dp[1] > 0) cout << "B" << endl;
    else cout << "D" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i<3; i++) solve();    
    return 0;
}
