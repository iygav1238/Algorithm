#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void solve() {
    int n; cin >> n;
    vector<int> fibo(n+1, 1);
    for (int i = 3; i<=n; i++) fibo[i] = fibo[i-1] + fibo[i-2];

    vector<int> p1, p2;
    int j = 3;
    if (n%3 == 2) {
        j = 5;
        p1.push_back(1);
        p2.push_back(2);
    }
    for (int i = j; i<=n; i+=3) {
        p1.push_back(i-2);
        p1.push_back(i-1);
        p2.push_back(i);
    }
    cout << p1.size() << endl;
    for (int i = 0; i<p1.size(); i++) cout << p1[i] << " \n"[i==p1.size()-1];
    cout << p2.size() << endl;
    for (int i = 0; i<p2.size(); i++) cout << p2[i] << " \n"[i==p2.size()-1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}