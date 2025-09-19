#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 1e9+7;
const int INF = 1000000000000000002LL;

int fpow(int a, int b, int mod) {
    int res = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    int res = 0;
    for (int i = 1; i<=n; i++) {
        int K = fpow(k, n-i+1, MOD), A;
        if (i & 1) A = 2*(i-2)*(i-1) + i + 3*(i-1);
        else A = 2*i*(i-1);
        A %= MOD;
        res = (res + K*A%MOD)%MOD;
    }
    cout << res%MOD << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}