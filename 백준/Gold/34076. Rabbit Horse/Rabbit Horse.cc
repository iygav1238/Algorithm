#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    string s = "RabbitHorse";
    map<char, int> appear;
    for (char x : s) appear[x]++;

    map<char, int> cnt;
    vector<pair<int, char>> p;
    int tot = 0;
    for (auto [x, c] : appear) {
        cnt[x] = n*c/11;
        tot += cnt[x];
        p.push_back({c, x});
    }
    sort(p.rbegin(), p.rend());

    for (int i = 0; i<n-tot; i++) {
        cnt[p[i%p.size()].second]++;
    }

    for (int i = 0; i<11; i++) {
        if (i == 3) continue;
        for (int j = 0; j<cnt[s[i]]; j++) cout << s[i];
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}