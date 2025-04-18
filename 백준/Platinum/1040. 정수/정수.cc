#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

void solve() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size(), m = stoll(s); 

    if (m == INF) {
        if (k == 1) cout << "1111111111111111111" << endl;
        else {
            string ans = "023456789";
            string plus = "";
            for (int i = 0; i<k-1; i++) plus += ans[i];
            cout << m + stoll(plus) << endl;
        }
        return;
    }

    vector<int> a(n+1, 0), pre(n+1, 0), use(10, 0);
    vector<vector<int>> preuse(n+1, use);
    for (int i = 1; i<=n; i++) {
        a[i] = s[i-1]-'0';
        use[a[i]]++;
        pre[i] = pre[i-1] + (use[a[i]] == 1);
        preuse[i] = use;
    }

    if (n < k) {
        s = "1023456789";
        for (int i = 0; i<k; i++) cout << s[i];
    } else if (pre[n] == k) cout << s << endl;
    else {
        string p = "";
        for (int i = 2; i<k; i++) p += i+'0';

        int res = (int)pow(10, n) + (p != "" ? stoll(p) : 0);
        for (int i = 1; i<=n; i++) {
            if (pre[i-1] > k) break;
            
            int rest = n-i, l = pow(10, rest);
            preuse[i][a[i]]--;

            for (int j = a[i]+1; j<10; j++) {
                int req = k-pre[i-1] - (preuse[i-1][j] == 0);
                if (req < 0) continue;
                int cur = m - m%(l*10) + j*l, x = -1;

                preuse[i][j]++;
                if (req == 0) {
                    for (int y = 0; y<10; y++) {
                        if (preuse[i][y] > 0) {
                            x = y; break;
                        }
                    }

                    int mul = 1;
                    while (mul < l) {
                        cur += mul*x;
                        mul *= 10;
                    }
                    res = min(res, cur);
                } else {
                    vector<int> temp;
                    for (int y = 0; y<10; y++) {
                        if (temp.size() >= req) break;
                        if (preuse[i][y] == 0) temp.push_back(y);
                    }
                    int mul = 1;
                    while (mul < l && !temp.empty()) {
                        cur += mul*temp.back();
                        mul *= 10;
                        temp.pop_back();
                    }
                    if (temp.empty()) res = min(res, cur);
                }
                preuse[i][j]--;
                
            }
            preuse[i][a[i]]++;
        }
        cout << res << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}