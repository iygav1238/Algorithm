#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define FOR(i, a, b, c) for (int i = a; (c > 0 ? i<=b : i>=b); i+=c)

#define heap priority_queue
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>

const int MOD = 998244353;
const int INF = 1e18+2;

void solve() {
    string s; getline(cin, s);
    int n = s.size();
    FOR(i, 0, n-1, 1) if (isupper(s[i])) s[i] = tolower(s[i]);
    
    int l = 0, r = n-1;
    while (l < r) {
        if (s[l] != s[r]) { cout << "No" << endl; return; }
        l++, r--;
    }
    cout << "Yes" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while (t--) solve();    
    return 0;
}