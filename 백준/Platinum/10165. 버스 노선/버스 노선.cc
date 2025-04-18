#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void Sort(vector<tuple<int, int, int>> &p) {
    sort(p.begin(), p.end(), [](const auto &a, const auto &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });
}

void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> a(m);
    for (int i = 0; i<m; i++) {
        int s, e; cin >> s >> e;
        a[i] = {s, e, i+1};
    }

    vector<tuple<int, int, int>> L, R;
    int front = 0, back = n;
    for (auto [l, r, i] : a) {
        if (l > r) {
            front = max(front, r);
            back = min(back, l);
            R.push_back({l, n+r, i});
        } L.push_back({l, r, i});
    }

    //cout << "front : " << front << ", back : " << back << endl; 
    vector<int> res;
    Sort(L); Sort(R);
    for (auto [l, r, j] : L) {
        if (r > front && l < back) res.push_back(j);
        front = max(front, r);
        //cout << l << " " << r << " " << j << endl;
    }
    front = 0;
    for (auto [l, r, j] : R) {
        if (r > front) res.push_back(j);
        front = max(front, r);
    }
    
    sort(res.begin(), res.end());
    for (auto x : res) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}