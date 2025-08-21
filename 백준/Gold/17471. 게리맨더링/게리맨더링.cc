#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), graph[n+1];
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<=n; i++) {
        int k; cin >> k;
        for (int j = 0; j<k; j++) {
            int x; cin >> x;
            graph[i].push_back(x);
        }
    }

    int res = INF;
    for (int stat = 1; stat<(1 << n); stat++) {
        vector<int> loc(n+1, 0);
        for (int i = 0; i<n; i++) {
            if  (stat & (1 << i)) loc[i+1] = 1;
        }
        int tot = accumulate(loc.begin()+1, loc.end(), 0LL);
        if (tot == 0 || tot == n) continue;

        //for (int i = 1; i<=n; i++) cout << loc[i] << " \n"[i==n];
        vector<int> vis(n+1, 0), chk(2, 0);
        for (int i = 1; i<=n; i++) {
            if ((!vis[i]) && (!chk[loc[i]])) {
                vector<int> st = {i};
                vis[i] = chk[loc[i]] = 1;
                while (!st.empty()) {
                    auto u = st.back(); st.pop_back();
                    for (auto v : graph[u]) {
                        if (!vis[v] && loc[v] == loc[u]) {
                            vis[v] = 1;
                            st.push_back(v);
                        }
                    }
                }
            }
        }

        int ok = accumulate(vis.begin(), vis.end(), 0LL);
        if (ok == n) {
            int cur = 0;
            for (int i = 1; i<=n; i++) {
                if (loc[i]) cur += a[i];
                else cur -= a[i];
            }
            res = min(res, abs(cur));
        }
    }
    cout << (res == INF ? -1 : res) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}