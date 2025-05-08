#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int chk(int k) {
    int tot = 0;
    while (k) {
        tot += k%10;
        k /= 10;
    }
    return (tot & 1);
}

void solve() {
    int n; cin >> n;
    while (n < INF-1) {
        if (chk(n)) {
            cout << n << endl;
            return;
        }
        n *= 2;
    }
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}