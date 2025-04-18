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

int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    if (x1 > x2 || (x1 == x2 && y1 > y2)) swap(x1, x2), swap(y1, y2);
    if (x3 > x4 || (x3 == x4 && y3 > y4)) swap(x3, x4), swap(y3, y4);

    int res1 = CCW(x1, y1, x2, y2, x3, y3);
    int res2 = CCW(x1, y1, x2, y2, x4, y4);
    int res3 = CCW(x3, y3, x4, y4, x1, y1);
    int res4 = CCW(x3, y3, x4, y4, x2, y2);

    if (x2 == x3 && y2 == y3) return 1;
    if (x1 == x4 && y1 == y4) return 1;

    if (res1 == 0 && res2 == 0 && res3 == 0 && res4 == 0) {
        if (x1 == x2) {
            if (y2 < y3 || y4 < y1) return 0;
            return 3;
        }
        if (x2 < x3 || x4 < x1) return 0;
        return 3;
    } else if (res1 * res2 <= 0 && res3 * res4 <= 0) {
        if (res1 == 0 || res2 == 0 || res3 == 0 || res4 == 0) return 1;
        return 2;
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<tuple<int, int, int, int>> a(n);
    for (int i = 0; i<n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2 || (x1 == x2 && y1 > y2)) swap(x1, x2), swap(y1, y2);
        a[i] = {x1, y1, x2, y2};
    }

    for (auto [x1, y1, x2, y2] : a) {
        for (auto [x3, y3, x4, y4] : a) {
            cout << intersect(x1, y1, x2, y2, x3, y3, x4, y4);
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}
