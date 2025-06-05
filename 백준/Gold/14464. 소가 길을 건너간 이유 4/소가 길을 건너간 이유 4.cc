#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define heap priority_queue
#define pii pair<int, int>

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    }
};

void solve() {
    int c, n; cin >> c >> n;
    vector<int> a(c);
    for (auto &x : a) cin >> x; 
    vector<pii> cow(n);
    for (auto &x : cow) cin >> x.first >> x.second; 
    sort(a.begin(), a.end());
    sort(cow.begin(), cow.end());

    int res = 0, ptr = 0;
    priority_queue<pii, vector<pii>, cmp> pq;
    for (auto x : a) {
        while (ptr < n && cow[ptr].first <= x) pq.push(cow[ptr++]);
        if (pq.empty()) continue;
        while (!pq.empty()) {
            auto [l, r] = pq.top(); pq.pop();
            if (l <= x && x <= r) { res++; break; }
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