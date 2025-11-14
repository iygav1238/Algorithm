#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define FOR(i, a, b, c) for (int i = a; (c > 0 ? i<=b : i>=b); i+=c)

#define heap priority_queue
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>

#define YES "YES"
#define NO "NO"

const int MOD = 998244353;
const int INF = 1e18+2;

vi pw(13, 1);

void make() {
    int a, b; cin >> a >> b;
    int ans = a+b;
    FOR(i, 12, 0, -1) {
        int mul = 0, x = pw[i];
        while (mul*x <= ans) mul++;
        mul--;
        char res = mul+'a';
        cout << res;
        ans -= mul*x;
    }
}

void answer() {
    string s; cin >> s;
    int res = 0;
    FOR(i, 12, 0, -1) {
        char c = s[12-i];
        int mul = c-'a';
        res += mul*pw[i];
    }
    cout << res << endl;
}

void solve() {
    int T; cin >> T;
    FOR(i, 1, 12, 1) pw[i] = 26*pw[i-1];
    if (T == 1) make();
    else answer();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}