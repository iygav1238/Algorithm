#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int n, m;
void solve() {
    vector<int> visited(n+1, 0), graph[n+1];
    for (int i = 0; i<m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int res = 0;
    for (int i = 1; i<=n; i++) {
        if (visited[i]) continue;
        vector<pair<int, int>> st = {{i, i}};
        int cur = 1;
        visited[i] = 1;
        while (!st.empty()) {
            auto [u, p] = st.back(); st.pop_back();
            for (auto v : graph[u]) {
                if (v == p) continue;
                if (visited[v]) cur = 0;
                else {
                    visited[v] = 1;
                    st.push_back({v, u});
                } 
            }
        }
        res += cur;
    }

    if (res == 0) cout << "No trees." << endl;
    else if (res == 1) cout << "There is one tree." << endl;
    else cout << "A forest of "<< res << " trees." << endl;
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int i = 1; i<=523518; i++) {
        cin >> n >> m;
        if (n == m && n == 0) break;
        cout << "Case " << i << ": ";
        solve();
    }  
    return 0;
}