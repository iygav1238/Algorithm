#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

struct BIT {
    int n; vector<int> t;
    BIT(int n): n(n), t(n+1,0) {}
    void add(int i,int v){ for(; i<=n; i+=i&-i) t[i]+=v; }
    int sum(int i){ int s=0; for(; i>0; i-=i&-i) s+=t[i]; return s; }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n), b;
    for (auto &x : a) cin >> x;
    
    b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int &x : a) x = lower_bound(b.begin(), b.end(), x) - b.begin()+1;

    BIT bit(b.size());
    int res = 0;
    for(int x : a){
        res += (bit.sum(b.size()) - bit.sum(x));
        bit.add(x,1);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}