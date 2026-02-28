#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define FOR(i, a, b, c) for (int i = a; (c > 0 ? i<=b : i>=b); i+=c)

#define heap priority_queue
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define viii vector<vector<vector<int>>>
#define vpii vector<pair<int, int>>

#define YES "YES"
#define NO "NO"

const int MOD = 998244353;
const int INF = 1e18+2;

void solve() {
    int n; cin >> n;
    vi a(n+1), pre(n+1);
    FOR(i, 1, n, 1) cin >> a[i], pre[i] = pre[i-1] + a[i];

    int k = 0, res = INF;
    FOR(i, 1, n/2, 1) {
        int cur = INF, ptr = i;
        set<int> dp; dp.insert(pre[i]);
        FOR(j, 2*i, n, 1) {
            int sum = pre[j]-pre[j-i];
            auto it = dp.lower_bound(sum);
            if (it != dp.end()) cur = min(cur, abs(sum - *it));
            if (it != dp.begin()) cur = min(cur, abs(sum - *(--it)));
            ptr++;
            dp.insert(pre[ptr]-pre[ptr-i]);
        }
        if (cur <= res) k = i, res = cur;
    }
    cout << k << endl << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}