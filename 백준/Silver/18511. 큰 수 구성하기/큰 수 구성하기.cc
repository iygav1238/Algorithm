#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int n, k, res;
vector<int> a;
void bt(int cnt, int cur) {
    if (cur <= n) res = max(res, cur);
    if (cnt == 10) return;

    for (auto x : a) {
        cur = 10*cur + x;
        bt(cnt+1, cur);
        cur /= 10;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i<k; i++) {
        int x; cin >> x;
        a.push_back(x);
    }

    res = 0;
    bt(0, 0);
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}