#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int x, y, z; cin >> x >> y >> z;
    if (x == 3 && y == z && x == y) cout << 0 << endl;
    else {
        int v = min({x, y, z});
        cout << (v-1)/2 << endl;
    }
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}