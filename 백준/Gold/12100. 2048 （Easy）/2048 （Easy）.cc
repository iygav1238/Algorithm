#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, res;
vector<vector<int>> a(22, vector<int>(22, INF));

void move(vector<vector<int>> &p, vector<vector<int>> &use, int i, int j, int d) {
    int k = p[i][j];
    int x = i + dx[d], y = j + dy[d];
    
    while (p[x][y] == 0) {
        x += dx[d];
        y += dy[d];
    }

    p[i][j] = 0;
    if (p[x][y] == k && use[x][y] == 0) {
        use[x][y] = 1;
        p[x][y] += k;
    } else {
        x -= dx[d];
        y -= dy[d];
        p[x][y] = k;
    }
}


void bt(int cur) {
    if (cur == 5) {
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=n; j++) res = max(res, a[i][j]);
        }
        return;
    }

    for (int d = 0; d<4; d++) {
        vector<vector<int>> p = a;
        vector<vector<int>> use(22, vector<int>(22, 0));
        if (d == 0){
            for (int i = 1; i<=n; i++) {
                for (int j = 1; j<=n; j++) move(p, use, i, j, d);
            }
        } else if (d == 1) {
            for (int i = 1; i<=n; i++) {
                for (int j = n; j>=1; j--) move(p, use, i, j, d);
            }
        } else if (d == 2) {
            for (int j = 1; j<=n; j++) {
                for (int i = 1; i<=n; i++) move(p, use, i, j, d);
            }
        } else {
            for (int j = 1; j<=n; j++) {
                for (int i = n; i>=1; i--) move(p, use, i, j, d);   
            }
        }
        swap(a, p);
        bt(cur+1);
        swap(a, p);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) cin >> a[i][j];
    }

    res = 0;
    bt(0);
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}