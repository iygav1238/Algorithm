#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n+1), b(n+1, 0), pre(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        b[i] = (a[i] >= m ? 1 : -1);
        if (a[i] == m) b[i] = 0;
        pre[i] = pre[i-1] + b[i];
    }

    int res = 0, k = 0;
    map<int, int> l, r;
    for (int i = 1; i<=n; i++) {
        if (a[i] == m) {
            for (int j = k; j<=i; j++) {
                if (j & 1) l[pre[j]]++;
                else r[pre[j]]++;
            }
            k = i+1;
        }
        if (i & 1) res += r[pre[i]];
        else res += l[pre[i]];
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}