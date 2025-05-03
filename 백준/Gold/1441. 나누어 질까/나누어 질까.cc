#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

bool multt(int a, int b, int r, __int128& out) {
    __int128 x = a;
    __int128 y = b;
    out = x * y;
    return out <= r;
}

int count_divisible(const vector<int>& p, int l, int r) {
    int res = 0;
    int sz = p.size();

    for (int mask = 1; mask < (1 << sz); ++mask) {
        __int128 lcm = 1;
        bool chk = false;

        for (int i = 0; i < sz; ++i) {
            if (mask >> i & 1) {
                int g = gcd((int)lcm, p[i]);
                __int128 nxt;
                if (!multt(lcm, p[i] / g, r, nxt)) {
                    chk = true;
                    break;
                }
                lcm = nxt;
            }
        }

        if (chk) continue;

        int cnt = r / lcm - (l - 1) / lcm;
        if (__builtin_popcountll(mask) % 2 == 1) res += cnt;
        else res -= cnt;
    }

    return res;
}

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n), p;
    for (auto &x : a) cin >> x;

    cout << count_divisible(a, l, r) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}