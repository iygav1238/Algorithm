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
#define viii vector<vector<vector<int>>>
#define vpii vector<pair<int, int>>

#define YES "YES"
#define NO "NO"

const int MOD = 998244353;
const int INF = 1e18+2;

void solve() {
    int n, q; cin >> n >> q;
    vi a(n+1);
    FOR(i, 1, n, 1) cin >> a[i];
    multiset<int> tour;
    FOR(i, 1, n, 1) if (a[i]) tour.insert(i);

    int cur = 1;
    while (q--) {
        int w, idx; cin >> w;
        if (w == 1) {
            cin >> idx;
            a[idx] ^= 1;
            if (a[idx]) tour.insert(idx);
            else tour.erase(tour.find(idx));
        } else if (w == 2) {
            cin >> idx;
            cur = (cur+idx)%n;
            if (cur == 0) cur = n;
        } else {
            if (tour.empty()) cout << -1 << endl;
            else {
                auto it = tour.lower_bound(cur);
                if (it == tour.end()) it = tour.begin();

                int i = *it;
                if (i >= cur) cout << i-cur << endl;
                else cout << n-cur + i << endl;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}