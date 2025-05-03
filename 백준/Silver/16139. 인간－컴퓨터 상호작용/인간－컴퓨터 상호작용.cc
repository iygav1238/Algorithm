#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;

    vector<vector<int>> pre(n+1, vector<int>(26, 0));
    for (int i = 1; i<=n; i++) {
        pre[i] = pre[i-1];
        pre[i][s[i]-'a']++;
    }

    int q; cin >> q;
    while (q--) {
        char c; cin >> c;
        int l, r; cin >> l >> r;
        cout << pre[r+1][c-'a'] - pre[l][c-'a'] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}