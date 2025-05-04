#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> l(n), r;
    for (auto &x : l) cin >> x;
    for (int i = 0; i<n/2; i++) {
        r.push_back(l.back());
        l.pop_back();
    }

    int m = l.size();
    map<int, int> cnt;
    for (int i = 0; i<(1 << m); i++) {
        int cur = 0;
        for (int j = 0; j<m; j++) {
            if (i & (1 << j)) cur += l[j];
        }
        if (cur <= c) cnt[cur]++;
    }

    vector<pair<int, int>> p;
    for (auto [k, v] : cnt) p.push_back({k, v});
    sort(p.begin(), p.end());
    for (int i = 1; i<p.size(); i++) {
        p[i].second += p[i - 1].second;
    }

    int res = 0;
    m = r.size();
    for (int i = 0; i<(1 << m); i++) {
        int cur = 0;
        for (int j = 0; j<m; j++) {
            if (i & (1 << j)) cur += r[j];
        }
        if (cur <= c) {
            int rest = c - cur;
            auto it = upper_bound(p.begin(), p.end(), make_pair(rest, INF));
            if (it != p.begin()) {
                --it;
                res += it->second;
            }
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}