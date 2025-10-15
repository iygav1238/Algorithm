#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + c > b + d) cout << "Yongdap" << endl;
    else if (a + c < b + d) cout << "Hanyang Univ." << endl;
    else cout << "Either" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}