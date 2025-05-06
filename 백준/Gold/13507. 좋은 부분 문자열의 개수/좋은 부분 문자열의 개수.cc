#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

const int MOD1 = 1e9+7, MOD2 = 1e9+9;
const int BASE1 = 911, BASE2 = 3571;

vector<int> pow1, pow2, hash1, hash2;

void build_hash(const string& s) {
    int n = s.size();
    pow1.assign(n+1, 1); pow2.assign(n+1, 1);
    hash1.assign(n+1, 0); hash2.assign(n+1, 0);

    for (int i = 1; i<=n; ++i) {
        pow1[i] = (pow1[i-1]*BASE1)%MOD1;
        pow2[i] = (pow2[i-1]*BASE2)%MOD2;
        hash1[i] = (hash1[i-1]*BASE1 + s[i-1])%MOD1;
        hash2[i] = (hash2[i-1]*BASE2 + s[i-1])%MOD2;
    }
}

pair<int, int> get_hash(int l, int r) {
    int h1 = (hash1[r+1] - (hash1[l]*pow1[r-l+1])%MOD1 + MOD1)%MOD1;
    int h2 = (hash2[r+1] - (hash2[l]*pow2[r-l+1])%MOD2 + MOD2)%MOD2;
    return {h1, h2};
}

void solve() {
    string s, t; cin >> s >> t;
    s = "Z" + s;
    int k, n = s.size(); cin >> k;
    
    vector<int> pre(n, 0);
    for (int i = 1; i<n; i++) {
        pre[i] = pre[i-1] + (t[s[i]-'a'] == '0');
    }

    build_hash(s);

    set<pair<int, int>> res;
    for (int i = 1; i<n; i++) {
        for (int j = 0; j<i; j++) {
            if (pre[i] - pre[j] <= k) {
                auto [l, r] = get_hash(j+1, i);
                res.insert({l, r});
            }
        }
    }
    cout << res.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}
