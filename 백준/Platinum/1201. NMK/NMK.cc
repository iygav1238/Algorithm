#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (n < m+k-1) cout << -1 << endl;
    else {
        vector<int> res, p, cur;
        int cnt = 0, rest;
        if ((n+m-1)/m <= k) {
            rest = n;
            while (res.size() < n) {
                for (int j = rest; j>max(0LL, rest-m); j--) {
                    cur.push_back(j);
                }
                rest -= m;
                for (int x = cur.size()-1; x >= 0; x--) res.push_back(cur[x]);
                p.push_back(cur[0]);
                cur.clear();
            }
            cnt = k - (n+m-1)/m;
            while (cnt) {
                int x = res.back(); res.pop_back();
                if (x != p.back()) cnt--;
                else p.pop_back();
                cur.push_back(x);
            }
            sort(cur.begin(), cur.end());
            reverse(cur.begin(), cur.end());
            for (auto x : cur) res.push_back(x);

        } else if ((n+k-1)/k <= m) {
            rest = 1;
            while (res.size() < n) {
                for (int j = rest; j<min(n+1, rest+k); j++) {
                    cur.push_back(j);
                }
                rest += k;
                for (int x = cur.size()-1; x >= 0; x--) res.push_back(cur[x]);
                p.push_back(cur[0]);
                cur.clear();
            }
            cnt = m - (n+k-1)/k;
            while (cnt) {
                int x = res.back(); res.pop_back();
                if (x != p.back()) cnt--;
                else p.pop_back();
                cur.push_back(x);
            }
            sort(cur.begin(), cur.end());
            for (auto x : cur) res.push_back(x);

        } else res.push_back(-1);
        for (auto x : res) cout << x << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}