#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

map<int, int> pw;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1), b(n+1, 0), cnt(n+1, 0);
    for (int i = 1; i<=n; i++) cin >> a[i];

    vector<int> p1(n+1, 0), p2(n+1, 0);
    for (int i = 1; i<=n; i++) {
        int c1 = 0, c2 = 0;
        int x = a[i], y = a[i] + 1;
        while (x > 1) {
            c1++; 
            x = x/2;
            if (x == 1) break;
            else x++;
        }
         while (y > 1) {
            c2++; 
            y = y/2;
            if (y == 1) break;
            else y++;
        }
        cnt[i] = c1, b[i] = (c2 > c1);
        p1[i] = p1[i-1] + cnt[i], p2[i] = p2[i-1] + b[i];
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int res = p1[r] - p1[l-1];
        int plus = p2[r] - p2[l-1];
        cout << res + plus/2 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int v = 4;
    while (v <= 1e9) pw[v] =  1, v *= 2;

    int t; cin >> t;
    while (t--) solve();    
    return 0;
}