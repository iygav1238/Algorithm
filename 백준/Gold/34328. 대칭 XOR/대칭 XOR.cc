#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

bool maxbit(int a, int b) {
    return __builtin_clz(a | b) == __builtin_clz(a);
}

void solve() {
    int n; cin >> n;
    vector<int> res(n+1);
    iota(res.begin(), res.end(), 0);

    int l = INF, r = 0;
    for (int i = 1; i<=n; i++) {
        int k = res[i] ^ res[n-i+1];
        l = min(l, k), r = max(r, k);
    }

    if (l == r) for (int i = 1; i<=n; i++) cout << res[i] << " \n"[i==n];
    else cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}