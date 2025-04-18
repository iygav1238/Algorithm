/*
    Author : iygav1238
    배낭 문제 변형 O(n*(log(10^11) + 0.5*m^2))
    let dp[i][j] = i번째 타이어로 j바퀴 돌았을 때의 최소 시간
    dp 전이 : dp[i][j] = min(dp[i-1][k] + @) (0 <= k <= j), @는 상수
    @ 계산 : 이동 거리는 (j-k)*L, 초기항 a, 공차 -d, 마지막 b인 수열의 prefix가 
            이동거리를 처음 넘을 때의 인덱스 (이분 탐색으로 찾음)
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

int find(int l, int r, int k, tuple<int, int, int> &p) {
    auto [a, b, d] = p;
    while (l < r) {
        int m = (l+r)/2;
        int cur = m*(2*a - (m-1)*d)/2;
        if (cur >= k) r = m;
        else l = m+1;
    }
    return r;
}

void solve() {
    int n, m, l; cin >> n >> m >> l;
    vector<tuple<int, int, int>> t(n+1);
    for (int i = 1; i<=n; i++) {
        int a, b, d; cin >> a >> b >> d;
        t[i] = {a, b, d};
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
    vector<int> req(m+1, 0);
    dp[0][0] = 0;
    for (int i = 1; i<=n; i++) {
        auto [a, b, d] = t[i];
        int c = (a-b)/d, low = c*(2*a - (c-1)*d)/2;
        for (int j = 1; j<=m; j++) {
            int dist = j*l;
            if (dist >= low) {
                dist -= low;
                req[j] = c + (dist+b-1)/b;
            } else {
                req[j] = find(0, c, dist, t[i]);
            }
        }
        for (int j = 0; j<=m; j++) {
            dp[i][j] = dp[i-1][j];
            for (int k = 0; k<j; k++) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + req[j-k]);
            }
        }
    }
    cout << dp[n][m] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}