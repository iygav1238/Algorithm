#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    if (a.back() == 0) cout << 0 << endl;
    else {
        int mx = 0;
        vector<int> exist(n+3, 0);
        for (auto x : a) {
            if (x < n+3) exist[x] = 1;
            while (exist[mx]) mx++;
        }
        cout << mx+1 << endl; 
    }
    for (int i = 0; i<n; i++) cout << a[i] << " \n"[i==n-1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}