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
#define vpii vector<pair<int, int>>

const int MOD = 998244353;
const int INF = 1e18+2;

void solve(int t) {
    int n; cin >> n;
    cout << "Case #" << t << ": ";
    if (n == 0) cout << "INSOMNIA" << endl;
    else {
        vi chk(10, 0);
        FOR(i, 1, 523518, 1) {
            int cur = n*i;
            while (cur > 0) {
                chk[cur%10] = 1;
                cur /= 10;
            }
            int tot = accumulate(chk.begin(), chk.end(), 0LL);
            if (tot == 10) { cout << n*i << endl; return; }
        }
        cout << "INSOMNIA" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    FOR(i, 1, t, 1) solve(i);    
    return 0;
}