#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

vector<int> a;
void bt(int cur, int last) {
    if (last != 10) a.push_back(cur);
    for (int i = 0; i<last; i++) {
        int k = cur*10 + i;
        bt(k, i);
    }
}

void solve() {
    int n; cin >> n;
    bt(0, 10);
    sort(a.begin(), a.end());
    cout << (n >= a.size() ? -1 : a[n]) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}