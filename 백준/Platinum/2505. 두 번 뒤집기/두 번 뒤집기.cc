#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

void rev(vector<int> &a, int l, int r) {
    while (l < r) swap(a[l++], a[r--]);
}

int chk(vector<int> &a, int l1, int r1, int l2, int r2) {
    int c = 1;
    for (int i = 1; i<a.size(); i++) {
        if (a[i] != i) c = 0;
    }
    if (c == 1) {
        cout << l1 << " " << r1 << endl;
        cout << l2 << " " << r2 << endl;
        return 1;
    }
    return 0;
}

int p(vector<int> a, vector<int> loc, int n) {
    vector<pair<int, int>> res;
    for (int i = 1; i<=n; i++) {
        if (a[i] != i) {
            res.push_back({i, loc[i]});
            int l = i, r = loc[i];
            while (l < r) {
                swap(loc[a[l]], loc[a[r]]);
                swap(a[l], a[r]);
                l++, r--;
            }
        }
    }
    if (res.size() <= 2) {
        for (auto [l, r] : res) cout << l << " " << r << endl;
        if (res.size() == 1) cout << 1 << " " << 1 << endl;
        return 1;
    }
    return 0;
}

void view(vector<int> &a) {
    cout << "CUR : ";
    for (int i = 1; i<a.size(); i++) cout << a[i] << " \n"[i==a.size()-1];
}

void solve() {
    int n, l = INF, r = 0; cin >> n;
    vector<int> a(n+1), loc(n+1);;
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        loc[a[i]] = i;
        if (a[i] != i) l = min(l, i), r = max(r, i);
    }
    if (r == 0) {
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }

    if (p(a, loc, n)) return;

    int L = l, R = r;
    for (int i = l+1; i<=r; i++) {
        if (a[i] != a[i-1]-1) {
            L = i-1;
            break;
        }
    }
    for (int i = r-1; i>=l; i--) {
        if (a[i] != a[i+1]+1) {
            R = i+1;
            break;
        }
    }

    //cout << "L : " << L << " R : " << R << endl;
    // case 1 : [l, r]을 뒤집는 경우
    rev(a, l, r);
    if (chk(a, l, r, 1, 1)) return;
    //view(a);
    int ll = INF, rr = 0, c = 1;
    for (int i = 1; i<=n; i++) {
        if (a[i] != i) ll = min(ll, i), rr = max(rr, i);
    }
    rev(a, ll, rr);
    //view(a);
    if (chk(a, l, r, ll, rr)) return;
    rev(a, ll, rr);
    rev(a, l, r);
    //cout << endl;
    // view(a);
    
    // case 2: [L+1, r]을 뒤집는 경우
    int p = a[l];
    rev(a, L+1, r);
    if (chk(a, l, r, 1, 1)) return;
    // view(a);
    rev(a, l, p);
    // view(a);
    if (chk(a, L+1, r, l, p)) return;
    rev(a, l, p);
    rev(a, L+1, r);
    //cout << endl;

    // view(a);
    // case 3: [l, R-1]을 뒤집는 경우
    p = a[r];
    rev(a, l, R-1);
    if (chk(a, l, r, 1, 1)) return;
    // view(a);
    rev(a, p, r);
    // view(a);
    if (chk(a, l, R-1, p, r)) return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}