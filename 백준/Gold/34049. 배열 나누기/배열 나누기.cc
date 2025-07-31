#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int res = 0, cur = 0;
    for (int i = n-1; i>=0; i--) {
        cur += a[i];
        if (cur >= 0) { res++; cur = 0; }
    }

    cout << (cur < 0 ? -1 : res) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}