#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int l, r;
void getLR(int n, vector<int> &a) {
    l = 0, r = 1;
    vector<pair<int, int>> p(n);
    for (int i = 0; i<n; i++) p[i] = {a[i], i};
    sort(p.begin(), p.end());

    int m1 = p[0].first, m2 = p[1].first;

    int c = 10;
    for (int i = 0; i<n && c > 0; i++) {
        if (a[i] == m1) {
            c--;
            l = i;
            for (int j = 0; j<n; j++) {
                if (j == i) continue;
                if (a[j] == m2) {
                    r = j;
                    if (abs(r-l) > 1) {
                        int mx = max(l, r), mn = min(l, r);
                        if (mx == n-1 && mn == 0) continue;
                        else return;
                    }
                }
            }
        }
    }
    if (l > r) swap(l, r);
}

int res = INF;
void bt(vector<int> a) {
    if (a.size() == 2) {
        int cur =  *max_element(a.begin(), a.end());
        res = min(res, cur);
        return;
    }
    int m = a.size();
    for (int i = 0; i<m; i++) {
        vector<int> p = a;
        
        if (i == 0) p[m-1]--;
        else p[i-1]--;
        if (i == m-1) p[0]--;
        else p[i+1]--;

        p.erase(p.begin() + i);
        bt(p);
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    // random_device rd;
    // mt19937 gen(rd());

    // uniform_int_distribution<> dist_n(3, 10);
    // int n = dist_n(gen);

    // uniform_int_distribution<> dist_val(n, 1'000'000'000);
    // vector<int> a(n);
    // for (int i = 0; i < n; ++i) {
    //     a[i] = dist_val(gen);
    // }

    getLR(n, a);
    if (l > r) swap(l, r);
    int p = a[l], q = a[r];
    int L = r-l-1, R = n-(r-l+1);

    // cout << l << " " << r << endl;
    // cout << L << " " << R << endl;

    for (int i = L; i>=1; i--) {
        if (i == 1) p--, q--;
        else if (p >= q) p--;
        else q--;
    }

    for (int i = R; i>=1; i--) {
        if (i == 1) p--, q--;
        else if (p >= q) p--;
        else q--;
    }

    // bt(a);

    // cout << res << " " << max(p, q) << endl;

    // if (res == max(p, q)) cout << "YES" << endl;
    // else cout << "NO" << endl;
    // cout << n << endl;
    // for (auto x : a) cout << x << " ";
    cout << max(p, q) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}