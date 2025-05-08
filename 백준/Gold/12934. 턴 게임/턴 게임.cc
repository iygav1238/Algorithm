#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int x, y; cin >> x >> y;
    int tot = x + y;
    
    int l = 1, r = 1e8;
    while (l < r) {
        int m = (l + r)/2;
        if (m*(m+1)/2 >= tot) r = m;
        else l = m+1;
    }

    if (r*(r+1)/2 != tot) {
        cout << -1 << endl;
        return;
    }

    int n = r, res = 0;
    while (x > n) {
        x -= n;
        n--;
        res++;
    }
    if (x != 0) res++;
    cout << res << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}