#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    int res = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (res > 0) return 1;
    else if (res == 0) return 0;
    else return -1;
}

void solve() {
    int xa, ya, xb, yb, xc, yc; cin >> xa >> ya >> xb >> yb >> xc >> yc;
    cout << fixed << setprecision(1) << abs(xa*(yb-yc) + xb*(yc-ya) + xc*(ya-yb)) / 2.0 << endl;

    vector<pair<int, int>> a = {{xa, ya}, {xb, yb}, {xc, yc}};
    sort(a.begin(), a.end());
    swap(a[1], a[2]);

    xa = a[0].first; ya = a[0].second;
    xb = a[1].first; yb = a[1].second;
    xc = a[2].first; yc = a[2].second;

    //cout << xa << " " << ya << " " << xb << " " << yb << " " << xc << " " << yc << endl;
    int n, res = 0; cin >> n;
    while (n--) {
        int x, y; cin >> x >> y;
        int c1 = CCW(xa, ya, xb, yb, x, y);
        int c2 = CCW(xb, yb, xc, yc, x, y);
        int c3 = CCW(xc, yc, xa, ya, x, y);
        if ((c1 >= 0 && c2 >= 0 && c3 >= 0) || (c1 <= 0 && c2 <= 0 && c3 <= 0)) res++;
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}
