#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void view(const deque<int> &q) {
    cout << "Cur : ";
    for (auto x : q) cout << x << " ";
    cout << endl;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a) cin >> x;

    deque<int> q;
    for (int i = 1; i<=n; i++) q.push_back(i);

    int res = 0;
    for (auto x : a) {
        if (q.front() == x) q.pop_front();
        else {
            int idx = 0;
            for (int i = 1; i<q.size(); i++) {
                if (q[i] == x) {
                    idx = i;
                    break;
                }
            }
            int l = idx, r = q.size()-idx;
            if (l <= r) {
                while (q.front() != x) {
                    int y = q.front(); q.pop_front();
                    res++;
                    q.push_back(y);
                }
            } else {
                while (q.front() != x) {
                    int y = q.back(); q.pop_back();
                    res++;
                    q.push_front(y);
                }
            }
            q.pop_front();
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}