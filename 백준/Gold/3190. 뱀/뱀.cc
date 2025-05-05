#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n+2, vector<int>(n+2, INF));
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) a[i][j] = 0;
    }
    int k; cin >> k;
    while (k--) {
        int i, j; cin >> i >> j;
        a[i][j] = 1;
    }
    a[1][1] = 3;
    pair<int, int> head = {1, 1}, tail = {1, 1};

    int l, d = 1, s = 1; cin >> l;
    for (int i = 0; i<l; i++) {
        int t; char c; cin >> t >> c;
        //cout << t << " " << c << endl;
        auto [x1, y1] = head;
        auto [x2, y2] = tail;
        for (int j = s; j<=t; j++) {

            //cout << "Time : " << j-1 << endl;
            //for (int x = 1; x<=n; x++) {
            //    for (int y = 1; y<=n; y++) cout << a[x][y] << " \n"[y==n];
            //}
            //cout << endl;

            x1 += dx[d], y1 += dy[d];
            if (a[x1][y1] == 1) {
                a[x1][y1] = j+3;
                continue;
            }
            
            if (a[x1][y1] != 0) {
                //cout << "HIT ! 2 : " << j << endl;
                //for (int x = 1; x<=n; x++) {
                //    for (int y = 1; y<=n; y++) {
                //        cout << a[x][y] << " \n"[y==n];
                //    }
                //}
                cout << j << endl;
                return;
            }
            a[x1][y1] = j+3;

            for (int dd = 0; dd<4; dd++) {
                int nx = x2 + dx[dd], ny = y2 + dy[dd];
                if (a[nx][ny] == a[x2][y2] + 1) {
                    a[x2][y2] = 0;
                    x2 = nx, y2 = ny;
                    break;
                }
            }
        }
        head = {x1, y1};
        tail = {x2, y2};


        if (c == 'L') d = (d+3)%4;
        else if (c == 'D') d = (d+1)%4;
        s = t+1;
    }
    auto [x1, y1] = head;
    auto [x2, y2] = tail;
    //cout << "cur dir : " << d << endl;
    //cout << "head : " << x1 << " " << y1 << endl;
    //cout << "tail : " << x2 << " " << y2 << endl;

    
    for (int j = s; j<INF; j++) {
        //cout << "Time : " << j-1 << endl;
        //for (int x = 1; x<=n; x++) {
        //    for (int y = 1; y<=n; y++) cout << a[x][y] << " \n"[y==n];
        //}
        //cout << endl;

        x1 += dx[d], y1 += dy[d];
        if (a[x1][y1] == 1) {
            a[x1][y1] = j+3;
            continue;
        }

        if (a[x1][y1] != 0) {
            //cout << "HIT ! 1 : " << j << endl;
            //for (int x = 1; x<=n; x++) {
            //    for (int y = 1; y<=n; y++) {
            //       cout << a[x][y] << " \n"[y==n];
            //    }
            //}
            cout << j << endl;
            return;
        }
        a[x1][y1] = j+3;

        for (int dd = 0; dd<4; dd++) {
            int nx = x2 + dx[dd], ny = y2 + dy[dd];
            if (a[nx][ny] == a[x2][y2] + 1) {
                a[x2][y2] = 0;
                x2 = nx, y2 = ny;
                break;
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