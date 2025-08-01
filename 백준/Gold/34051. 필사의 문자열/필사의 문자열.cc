#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> a(n), res;
    for (int i = 0; i<n; i++) a[i] = s[i]-'a';
    int mx = *max_element(a.begin(), a.end());
    res = a;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<i; j++) {
            if (a[j] < a[i]) {
                vector<int> temp;
                for (int k = 0; k<j; k++) temp.push_back(a[k]);
                for (int k = i; k>=j; k--) temp.push_back(a[k]);
                for (int k = i+1; k<n; k++) temp.push_back(a[k]);
                if (res < temp) swap(res, temp);
                break;
            }
        }
    }
    for (int i = 0; i<n; i++) cout << (char)(res[i]+'a');
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}