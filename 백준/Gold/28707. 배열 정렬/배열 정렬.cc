/*
    Author : iygav1238
    다익스트라를 이용한 백트래킹 (N <= 8, M <= 10)
    10! := 362만
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;
 
void solve() {
    int n, m; cin >> n;
    vector<int> a(n), goal;
    for (auto &x : a) cin >> x;
    cin >> m;
    vector<tuple<int, int, int>> p(m);
    for (int i = 0; i<m; i++) {
        int l, r, w; cin >> l >> r >> w;
        l--, r--;
        p[i] = {l, r, w};
    }
    goal = a;
    sort(goal.begin(), goal.end());

    map<vector<int>, int> stat;
    priority_queue<tuple<int, vector<int>>, vector<tuple<int, vector<int>>>, greater<tuple<int, vector<int>>>> pq;
    pq.push({0, a});
    stat[a] = 0;
    while (!pq.empty()) {
        auto [cost, arr] = pq.top(); pq.pop();
        if (stat[arr] < cost) continue;
        for (auto [l, r, w] : p) {
            swap(arr[l], arr[r]);
            int ncost = cost + w;
            if (stat.find(arr) == stat.end() || stat[arr] > ncost) {
                stat[arr] = ncost;
                pq.push({ncost, arr});
            }
            swap(arr[l], arr[r]);
        }
    }

    if (stat.find(goal) == stat.end()) cout << -1 << endl;
    else cout << stat[goal] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}