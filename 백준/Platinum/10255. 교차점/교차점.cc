#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int rev=0) {
    int c1 = CCW(x1, y1, x2, y2, x3, y3);
    int c2 = CCW(x1, y1, x2, y2, x4, y4);
    int c3 = CCW(x3, y3, x4, y4, x1, y1);
    int c4 = CCW(x3, y3, x4, y4, x2, y2);

    int p1p2 = c1*c2, p3p4 = c3*c4;
    int px = (rev ? x1 : x2);
    int py = (rev ? y1 : y2);

    int linex = (x1 == x2 && x2 == x3 && x3 == x4);
    int liney = (y1 == y2 && y2 == y3 && y3 == y4);

    if (linex || liney) {
        if (y2 < y3 || y4 < y1) return 0;
        if (x2 < x3 || x4 < x1) return 0;
        if (x2 == x3 && y2 == y3) return !(x2 == px && y2 == py);
        if (x1 == x4 && y1 == y4) return !(x1 == px && y1 == py);
        return 4;
    } else if (p1p2 <= 0 && p3p4 <= 0) {
        return (CCW(x3, y3, x4, y4, px, py) ? 1 : 0); 
    }
    return 0;
}

void solve() {
    int xmin, ymin, xmax, ymax; cin >> xmin >> ymin >> xmax >> ymax;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2 || (x1 == x2 && y1 > y2)) {
        swap(x1, x2); swap(y1, y2);
    }

    int res = 0;
    res += intersect(xmin, ymin, xmax, ymin, x1, y1, x2, y2);
    res += intersect(xmax, ymin, xmax, ymax, x1, y1, x2, y2);
    res += intersect(xmin, ymin, xmin, ymax, x1, y1, x2, y2, 1);
    res += intersect(xmin, ymax, xmax, ymax, x1, y1, x2, y2, 1);
    cout << min(res, 4LL) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}