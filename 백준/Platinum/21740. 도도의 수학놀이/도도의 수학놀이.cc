#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

vector<int> trans = {0, 1, 2, 3, 4, 5, 9, 7, 8, 6};
void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i<n; i++) {
        string x; cin >> x;
        reverse(x.begin(), x.end());
        for (int j = 0; j<x.size(); j++) {
            x[j] = trans[x[j]-'0'] + '0';
        }
        a[i] = x;
    }

    int y = 0;
    vector<string> temp;
    for (auto x : a) y = max(y, (int)x.size());
    for (auto x : a) {
        if (x.size() == y) temp.push_back(x);
    }
    sort(temp.begin(), temp.end(), [](const string &a, const string &b) {
        return a+b > b+a;
    });
    a.push_back(temp[0]);

    sort(a.begin(), a.end(), [](const string &a, const string &b) {
        return a+b > b+a;
    });

    string res = "";
    for (auto x : a) res += x;
    //cout << res << endl;
    reverse(res.begin(), res.end());
    for (auto x : res) cout << trans[x-'0'];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}