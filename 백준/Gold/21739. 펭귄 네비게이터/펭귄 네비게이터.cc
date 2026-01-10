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

#define YES "YES"
#define NO "NO"

const int MOD = 1e9+7;
const int INF = 1e18+2;

int fpow(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;

    vi fact(2*n+1);
    fact[0] = 1;
    FOR(i, 1, 2*n, 1) fact[i] = (fact[i - 1] * i) % MOD;

    int x = (fact[n+1]*fact[n])%MOD; 
    int res = (fact[2*n]*fpow(x, MOD-2))%MOD;
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}