#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, k; cin >> n >> k;
    if (n == k) cout << "Impossible" << endl;
    else if (n == k + 1) {
        for (int i = 1; i<=n; i++) cout << i << " \n"[i==n];
    }
    else {
        cout << k + 2 << " ";
        for (int i = 2; i<=k+1; i++) cout << i << " ";
        for (int i = k + 2; i<=n; i++) cout << (i < n ? i + 1 : 1) << " \n"[i==n];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}