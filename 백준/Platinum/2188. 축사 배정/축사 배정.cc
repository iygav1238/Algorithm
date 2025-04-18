/*
    Author : iygav1238
    이분 매칭 예제
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;
const int MAXN = 201;

int n, m;
vector<int> graph[MAXN], mat(MAXN, 0);
bool visited[MAXN];

int dfs(int u) {
    if (visited[u]) return 0;
    visited[u] = true;
    for (auto v : graph[u]) {
        if (mat[v] == 0 || dfs(mat[v])) {
            mat[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i<=n; i++) {
        int s; cin >> s;
        for (int j = 0; j<s; j++) {
            int x; cin >> x;
            graph[i].push_back(x);
        }
    }

    int res = 0;
    for (int i = 1; i<=n; i++) {
        memset(visited, false, sizeof(visited));
        res += dfs(i);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}