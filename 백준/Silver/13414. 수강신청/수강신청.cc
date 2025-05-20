#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int K, L; cin >> K >> L;
    map<string, int> a;
    for (int i = 0; i<L; i++) {
        string x; cin >> x;
        a[x] = i;
    }

    vector<pair<int, string>> res;
    for (auto [k, v] : a) {
        res.push_back({v, k});
    }
    sort(res.begin(), res.end());

    for (int i = 0; i<min(K, (int)res.size()); i++) cout << res[i].second << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}