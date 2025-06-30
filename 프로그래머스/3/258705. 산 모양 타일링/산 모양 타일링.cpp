#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int solution(int n, vector<int> tops) {
    vector<int> dp(2*n+1, 0);
    dp[0] = 1, dp[1] = 2 + tops[0];
    for (int i = 2; i<2*n+1; i++) {
        if (i & 1) {
            if (tops[i/2] == 1) dp[i] = (dp[i-1]%MOD + dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
            else dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
        } else dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
    }
    return dp[2*n]%MOD;
}