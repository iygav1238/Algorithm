#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int n;
 
void solve() {
    vector<int> a(n+1);
    vector<int> dp(n+2, -INF), pre(n+1, 0);
    dp[n+1] = 0;
    for (int i = n; i >= 1; i--) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i];
 
    for (int cur = n; cur >= 1; cur--) {
        int tmp = INF;
        for (int i = cur; i <= n; i++) {
            tmp = min(tmp, pre[i] - pre[cur-1] - dp[i+1]);
        }
        dp[cur] = tmp;
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