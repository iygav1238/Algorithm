#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    vector<int> a(n), graph[n];
    for (auto &x : a) cin >> x;

    int init = 0;
    for (int i = 0; i<n; i++) {
        if (a[i]) init |= (1 << i);
    }

    for (int i = 0; i<n; i++) {
        int c; cin >> c;
        for (int j = 0; j<c; j++) {
            int x; cin >> x;
            graph[i].push_back(--x);
        }
    }

    int res = -1, goal = (1 << n)-1;
    vector<int> visited(1 << n, 0);
    queue<pair<int, int>> q = {};
    visited[init] = 0; q.push({init, 0});
    while (!q.empty()) {
        auto [cur, lvl] = q.front(); q.pop();
        if (cur == goal) {
            res = lvl;
            break;
        }
        for (int i = 0; i<n; i++) {
            if (cur & (1 << i)) continue;
            int newc = cur ^ (1 << i);
            for (auto x : graph[i]) newc ^= (1 << x);
            if (visited[newc] == 0) {
                visited[newc] = 1;
                q.push({newc, lvl+1});
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