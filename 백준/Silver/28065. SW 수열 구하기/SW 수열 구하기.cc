#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    vector<int> res(n, 0);
    int l = 1, r = n;
    for (int i = 0; i<n; i++) {
        if (i & 1) res[i] = r--;
        else res[i] = l++;
    }
    for (auto x : res) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}