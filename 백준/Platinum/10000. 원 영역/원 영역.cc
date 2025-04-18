#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i<n; i++) {
        int x, r; cin >> x >> r;
        a[i] = {x-r, x+r};
    }
    sort(a.begin(), a.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        else return a.first > b.first;
    });

    vector<int> line;
    int res = n + 1, l = -INF, r = -INF;
    for (auto [s, e] : a) {
        res += (l <= s && e <= r);
        if (s > r) {
            line.push_back(l);
            line.push_back(r);
            l = s;
        }
        r = max(r, e);
        l = min(l, s);

        auto it = lower_bound(line.begin(), line.end(), l);
        if (it == line.end()) continue;
        int i = it-line.begin();
        if (i & 1) i--;
        l = min(l, line[i]);
        while (line.size() > i) line.pop_back();
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}