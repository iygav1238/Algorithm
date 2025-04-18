#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void solve() {
    int n, m = 1; cin >> n;
    string s; cin >> s;

    int c = (s[0] == '1'), j = 0;
    for (int i = 1; i<n; i++) {
        if (s[i] == '0' && s[i-1] == '1') {
            m = n-i;
            j = i;
            break;
        } else if (s[i] == '1') c++;
    }
    vector<int> res(n), temp;
    for (int i = 0; i<n; i++) res[i] = s[i]-'0';

    if (accumulate(res.begin(), res.end(), 0LL) == 0) {
        cout << 0 << endl;
        return;
    }

    int zero = 0, p = 1;
    for (int k = j; k<n; k++) {
        if (res[k] == 1) break;
        zero++;
    }
    p = min(c, zero);
    j = max(p, j);
    //cout << "cur : " << m << " " << p << " " << j << endl;
    for (int k = j-p; k<j-p+m; k++) {
        temp.push_back(res[k]);
        //cout << "append : " << k << endl;
    }

    /*
    for (auto x : res) cout << x;
    cout << endl;
    for (auto x : temp) cout << x;
    cout << endl;
    */
   
    reverse(res.begin(), res.end());
    reverse(temp.begin(), temp.end());
    while (!res.empty() && res.back() == 0) res.pop_back();
    for (int k = 0; k<temp.size(); k++) res[k] ^= temp[k];
    
    reverse(res.begin(), res.end());
    for (auto x : res) cout << x;
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}