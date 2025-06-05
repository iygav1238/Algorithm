#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a) cin >> x;

    multiset<int> exist;
    for (int i = 1; i<=n; i++) exist.insert(i);

    int res = 0;
    for (auto x : a) {
        if (exist.empty()) break;
        auto it = exist.upper_bound(x);
        if (it == exist.begin()) break;
        res++;
        --it;
        int k = *it;
        exist.erase(it);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    solve();    
    return 0;
}