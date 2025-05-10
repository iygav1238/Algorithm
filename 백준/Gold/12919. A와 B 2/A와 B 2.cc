#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

string s, t;

void check(vector<char> &q) {
    if (q.size() == s.size()) {
        for (int i = 0; i<q.size(); i++) {
            if (q[i] != s[i]) return;
        }
        cout << 1 << endl;
        exit(0);
    }

    if (q.back() == 'A') {
        q.pop_back();
        check(q);
        q.push_back('A');
    }
    if (q[0] == 'B') {
        reverse(q.begin(), q.end());
        q.pop_back();
        check(q);
        q.push_back('B');
        reverse(q.begin(), q.end());
    }
}

void solve() {
    cin >> s >> t;
    vector<char> a;
    for (auto x : t) a.push_back(x);

    check(a);
    cout << 0 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}