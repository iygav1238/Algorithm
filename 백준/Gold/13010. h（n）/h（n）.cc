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

    if (n == 1) cout << 1 << endl;
    else {
        auto cnt = [](int x) {
            int res = 0;
            for (int i = 1; i*i<=x; i++) {
                if (x%i == 0) {
                    res++;
                    if (i*i != x) res++;
                }
            }
            return res;
        };
        auto ok = [](int x, int k, int y) {
            int cnt = 0;
            while (y%x == 0) {
                cnt++;
                y /= x;
            }
            return (cnt == k && y == 1);
        };

        FOR(k, 60, 2, -1) {
            int x = (int)round(pow(n, (double)1/k));
            if (x <= 1) continue;
            if (ok(x, k, n) && cnt(x) == k) {
                cout << x << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
    
    // 적어도 n의 양의 약수는 2개임..
    // h(x)는 적어도 x^2라는 뜻임..
    // n이 소수라면.. x^2 = n일 수가 없음.. n 이 1이면 x = 1이지만 아니라면 -1

    // n이 소수가 아니라면.. 적어도 x^3 = n임..
    // 즉 n이 소수면 -1, 아니면 적어도 i <= 1e6를 모두 탐사해보면 됨..
    // 근데 그러면 n이 1e18이하일때 소수판정을 어케함??

    // 밀러라빈 소수 판정이면 골드가 아닌데
    // 근데 생각해보니까 소수판정 할 필요가 없는데
    // 그냥 1e6까지 다 해보면 짜피 뭐 소수면 없을거고..

    // 약수 개수를 일일히 세면 귀찮으니까 cnt배열로 하자

    // 근데 생각해보니까 2^60 >= 1e18인거 생각하면 h(x)에서 x의 약수는 많아봐야 60이어야할텐데
    // 그러면 i <= 60까지보면서 x^i == n인 x를 확인해보자
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}