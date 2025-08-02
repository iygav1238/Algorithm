#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), idx(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }

    int res = n+1, cnt = 0;
    vector<int> temp = a, cur = idx;
    for (int i = 1; i<=n; i++) {
        if (temp[i] != i) {
            cnt++;
            int x = temp[i];
            swap(temp[i], temp[cur[i]]);
            swap(cur[x], cur[i]);
        }
    }
    res = cnt; cnt = 0;
    temp = a, cur = idx;
    for (int i = n; i>=1; i--) {
        if (temp[i] != n-i+1) {
            cnt++;
            int x = temp[i];
            swap(temp[i], temp[cur[n-i+1]]);
            swap(cur[x], cur[n-i+1]);
        }
    }
    cout << n-2 << " " << min(res, cnt) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}