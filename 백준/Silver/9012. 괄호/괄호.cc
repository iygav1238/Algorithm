#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> a(n+1, 0);
    for (int i = 1; i<=n; i++) a[i] = (s[i-1] == '(' ? 1 : -1);

    for (int i = 1; i<=n; i++) {
        a[i] += a[i-1];
        if (a[i] < 0) { cout << "NO" << endl; return; }
    }
    cout << (a[n] == 0 ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}