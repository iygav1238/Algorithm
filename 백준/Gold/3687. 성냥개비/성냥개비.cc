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

const int MAXN = 100;
vector<string> dp(MAXN+1, "INF");
void Init() {
    vi cnt = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    dp[0] = "";
    FOR(i, 2, MAXN, 1) {
        FOR(j, 0, 9, 1) {
            int k = cnt[j];
            if ((k > i) || (dp[i-k] == "INF")) continue;
            int size = dp[i-k].size();
            FOR(r, 0, size, 1) {
                if (j == r && j == 0) continue;
                string news = dp[i-k];
                news.insert(r, to_string(j));
                if (dp[i] == "INF" || news.size() < dp[i].size() || (news.size() == dp[i].size() && news < dp[i])) dp[i] = news;
            }                
        }  
    }
}

void solve() {
    int n; cin >> n;
    cout << dp[n] << " ";
    if (n & 1) {
        cout << 7;
        FOR(i, 2, n/2, 1) cout << 1;
    } else FOR(i, 1, n/2, 1) cout << 1;
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Init();
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}