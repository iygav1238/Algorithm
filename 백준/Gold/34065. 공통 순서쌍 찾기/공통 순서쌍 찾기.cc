#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1), idx(n+1), b(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<=n; i++) {
        cin >> b[i];
        idx[b[i]] = i;
    }

    deque<int> q;
    vector<pair<int, int>> res;
    for (int i = 1; i<=n; i++) {
        vector<int> temp;
        while (!q.empty() && (res.size() < k)) {
            auto x = q.front(); 
            if (x < idx[a[i]]) {
                res.push_back({b[x], a[i]});
                temp.push_back(x);
                q.pop_front();
            } else break;
        }
        if (res.size() >= k) break;
        q.push_front(idx[a[i]]);
        while (!temp.empty()) {
            auto x = temp.back(); temp.pop_back();
            q.push_front(x);
        }
    }

    if (res.size() < k) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for (auto [x, y] : res) cout << x << " " << y << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}