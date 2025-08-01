#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i<=n; i++) cin >> a[i];

    vector<int> L(n+1, 0), R(n+2, 0);
    for (int i = 1; i<=n; i++) L[i] = min({i, L[i-1]+1, a[i]});
    for (int i = n; i>=1; i--) R[i] = min({n-i+1, R[i+1]+1, a[i]});
    
    int res = 0;
    for (int i = 1; i<=n; i++) res += min(L[i], R[i]);
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}