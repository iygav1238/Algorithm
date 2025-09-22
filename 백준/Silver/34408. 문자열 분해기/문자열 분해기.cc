#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    string S, T; cin >> S >> T;
    vector<int> CS(26, 0), CT(26, 0);
    for (auto c : S) CS[c-'A']++;
    for (auto c : T) CT[c-'A']++;

    for (int i = 0; i<26; i++) {
        if (CS[i] < CT[i]) {
            cout << "NEED FIX" << endl;
            return;
        }
    }
    cout << "OK" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}