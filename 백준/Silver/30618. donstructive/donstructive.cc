#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int l = 0, r = n-1, ptr = 1;
    vector<int> res(n, 0);
    while (l <= r) {
        res[l] = ptr++;
        if (res[r] == 0) res[r] = ptr++;
        l++, r--;
    }
    for (auto x : res) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}   