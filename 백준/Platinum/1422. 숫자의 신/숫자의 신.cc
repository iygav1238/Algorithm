#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    int mxlen = 0;
    string res = "", use = "";
    for (auto x : a) mxlen = max(mxlen, (int)x.size());
    for (auto x : a) if (x.size() == mxlen) use = max(use, x);
    for (int _ = 0; _<k-n; _++) a.push_back(use);

    sort(a.begin(), a.end(), [](const string &a, const string &b) {
        return a+b > b+a;
    });

    for (auto x : a) res += x;
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();   
    return 0;
}