#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

const int sz = 1 << 20;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), dp(n+1, 0), l(n+1), r(n+1), pre(n+1, 0);
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    vector<int> tree1(2*sz, 0), tree2(2*sz, INF);
    for (int i = 1; i<=n; i++) {
        int L = sz, R = a[i]-1 + sz;
        int j = 0;
        while (L <= R) {
            if (L & 1) j = max(j, tree1[L]);
            if (~R & 1) j = max(j, tree1[R]);
            L = (L+1)/2;
            R = (R-1)/2;
        }
        l[i] = j+1;
        j = a[i] + sz;
        tree1[j] = i;
        while (j > 1) {
            j /= 2;
            tree1[j] = i;
        }
    }

    for (int i = n; i>=1; i--) {
        int L = sz, R = a[i]-1+sz;
        int j = n+1;
        while (L <= R) {
            if (L & 1) j = min(j, tree2[L]);
            if (~R & 1) j = min(j, tree2[R]);
            L = (L+1)/2;
            R = (R-1)/2;
        }
        r[i] = j-1;
        j = a[i] + sz;
        tree2[j] = i;
        while (j > 1) {
            j /= 2;
            tree2[j] = i;
        }
    }

    int res = 0;
    for (int i = 1; i<=n; i++) {
        //cout << l[i] << " " << r[i] << endl;
        res = max(res, a[i]*(pre[r[i]]-pre[l[i]-1]));
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}