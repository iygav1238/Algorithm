#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n), p(n, 0);
    for (auto &x : a) cin >> x;

    for (int i = 0; i<n; i++) {
        for (int j = i+1; j<n; j++) {
            int chk = 1;
            for (int k = i+1; k<j; k++) {
                // (a[k]-a[i])/(k-i) < (a[j]-a[i])/(j-i)
                if ((a[k]-a[i])*(j-i) >= (a[j]-a[i])*(k-i)) chk = 0;
            }
            if (chk) {
                p[i]++, p[j]++;
            }
        }
    }
    cout << *max_element(p.begin(), p.end()) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}