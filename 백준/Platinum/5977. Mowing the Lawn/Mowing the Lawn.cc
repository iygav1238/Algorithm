#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1), pre(n+1, 0);
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    deque<int> q; q.push_back(0);
    vector<pair<int, int>> dp(n+1, {0, 0});
    for (int i = 1; i<=n; i++) {
        while (!q.empty()) {
            int idx = q.front();
            if (idx < i-k) q.pop_front();
            else break;
        }

        dp[i].first = max(dp[i-1].first, dp[i-1].second);
        int j = q.front();
        dp[i].second = dp[j].first + pre[i] - pre[j];
        int cur = dp[i].first - pre[i];
        
        while (!q.empty()) {
            int idx = q.back();
            int w = dp[idx].first - pre[idx];
            if (w <= cur) q.pop_back();
            else break;
        }
        q.push_back(i);
    }   
    cout << max(dp[n].first, dp[n].second) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}