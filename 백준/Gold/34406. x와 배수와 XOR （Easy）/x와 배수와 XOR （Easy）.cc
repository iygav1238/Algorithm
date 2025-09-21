#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int x; cin >> x;

    if (x == 0) cout << 1 << endl << "2" << endl;
    else {
        for (int shift = 1; shift<31; shift++) {
            int p = x << shift;
            int y = p/x;
            int cur = (y*x) ^ ((y+1)*x);
            if (cur == x) {
                cout << 2 << endl << y << " " << y+1 << endl;
                return;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}