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
    int n; cin >> n;
    vii graph(n+1);
    FOR(i, 1, n, 1) {
        int u, v; cin >> u >> v;
        graph[i].push_back(v);
        graph[i].push_back(u);
    }

    if (n < 3) { cout << -1 << endl; return; }

    function<int(vi)> lis = [](vi A) -> int {
        int N = A.size();
        vi DP = {A[0]};
        FOR(i, 1, N-1, 1) {
            int x = A[i];
            auto it = lower_bound(DP.begin(), DP.end(), x);
            int idx = it - DP.begin();
            if (it == DP.end()) DP.push_back(x);
            else *it = x;
        }
        return DP.size();
    };

    auto rotate = [](vi &A) {
        int x = A[0];
        A.erase(A.begin());
        A.push_back(x);
    };

    vi stk = {1}, order, vis(n+1);
    vis[1] = 1;
    while (!stk.empty()) {
        int u = stk.back(); stk.pop_back();
        sort(graph[u].begin()+1, graph[u].end());
        order.push_back(u);
        for (auto v : graph[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                stk.push_back(v);
            }
        }
    }

    if (order.size() < n) { cout << -1 << endl; return; }

    int res = 0;
    FOR(i, 1, n, 1) {
        vi rev;
        FOR(j, n-1, 0, -1) rev.push_back(order[j]);
        res = max({res, lis(order), lis(rev)});
        rotate(order);
    }
    cout << n-res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}