#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

const int MAXN = 11;
int n, m, ptr;
vector<vector<int>> a(MAXN, vector<int>(MAXN));
vector<tuple<int, int, int>> edges;

int getParent(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = getParent(parent, parent[x]);
    }
    return parent[x];
}

void unionSet(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    return a == b;
}

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void init() {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (a[i][j] == 1) {
                vector<pair<int, int>> stk;
                a[i][j] = ++ptr;
                stk.push_back({i, j});
                while (!stk.empty()) {
                    auto [x, y] = stk.back(); stk.pop_back();
                    for (int d = 0; d<4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (a[nx][ny] == 1) {
                            a[nx][ny] = ptr;
                            stk.push_back({nx, ny});
                        }
                    }
                }
            }   
        }
    }
}

void addEdge(int k) {
    vector<int> dist(ptr+1, INF);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (a[i][j] != k) continue;
            for (int d = 0; d<4; d++) {
                int x = i + dx[d], y = j + dy[d];
                int c = 0, p = -1;
                while (0 <= x && x < n && 0 <= y && y < m) {
                    if (a[x][y] == 0) c++;
                    else {
                        p = a[x][y];
                        break;
                    }
                    x += dx[d], y += dy[d];
                }
                if (p != -1 && c > 1) dist[p] = min(dist[p], c);
            }
        }
    }

    //cout << "Cur : " << k << " : ";
    //for (int i = 2; i<=ptr; i++) cout << dist[i] << " \n"[i==ptr];

    int cnt = 0;
    for (int i = 1; i<=ptr; i++) {
        if (i == k) continue;
        if (dist[i] != INF && dist[i] > 1) {
            edges.push_back({dist[i], k, i});
            cnt++;
            //cout << "Add Bridges: "  << dist[i] << " " << i << " " << k << endl;
        }
    }
    
    //cout << "Add cnt : " << cnt << endl;

    if (cnt == 0) {
        cout << -1 << endl;
        exit(0);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cin >> a[i][j];
    }

    ptr = 1;
    init();

    // for (int i = 0; i<n; i++) {
    //      for (int j = 0; j<m; j++) cout << a[i][j] << " \n"[j==m-1];
    // }

    vector<int> chk(ptr+1, 0);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            int cur = a[i][j];
            if (cur > 0 && chk[cur] == 0) {
                chk[cur] = 1;
                addEdge(cur);
            }
        }
    }

    vector<int> parent(ptr+1, 0);
    for (int i = 1; i<=ptr; i++) parent[i] = i;

    int res = 0, tot = 0;
    sort(edges.begin(), edges.end());
    for (auto [w, u, v] : edges) {
        if (!find(parent, u, v)) {
            unionSet(parent, u, v);
            res += w;
            tot++;
        }
    }
    cout << (tot == ptr-2 ? res : -1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}