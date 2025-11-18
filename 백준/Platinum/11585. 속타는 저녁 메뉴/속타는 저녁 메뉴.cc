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

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    FOR(i, 0, n-1, 1) {
        char x; cin >> x;
        a[i] = x-'A';
    }
    FOR(i, 0, n-1, 1) {
        char x; cin >> x;
        b[i] = x-'A';
    }
    FOR(i, 0, n-1, 1) b.push_back(b[i]);

    auto failure = [](const vi &s) {
        int n = s.size();
        vi table(n, 0);
        int j = 0;
        FOR(i, 1, n-1, 1) {
            while (j > 0 && s[i] != s[j]) j = table[j-1];
            if (s[i] == s[j]) table[i] = ++j;
        }
        return table;
    };

    auto kmp = [&](const vi &s, const vi &t) {
        vi table = failure(t);
        int j = 0, cnt = 0;
        FOR(i, 0, 2*n-1, 1) {
            while (j > 0 && s[i] != t[j]) j = table[j-1];
            if (s[i] == t[j]) {
                if (j == n-1) {
                    if (i < 2*n-1) cnt++;
                    j = table[j];
                } else j++;
            }
        }
        return cnt;
    };
    int x = kmp(b, a), y = n;
    int g = gcd(x, y);
    cout << x/g << "/" << y/g << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}