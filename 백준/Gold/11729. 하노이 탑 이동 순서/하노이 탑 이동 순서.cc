#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve(int n, int from, int to, int aux) {
    if (n == 0) return;
    solve(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    solve(n - 1, aux, to, from);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    cout << (1 << n) -1 << endl;
    solve(n, 1, 3, 2);    
    return 0;
}