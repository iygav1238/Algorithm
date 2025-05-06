#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;
const int LOG = 30;

struct node {
    int child[2] = {-1, -1};
    int idx = INF;
};

int query(const vector<node>& trie, int value, int border) {
    int res = INF, cur = 0, ok = 1;
    for (int i = LOG; ok && i>=0; i--) {
        int x = (value >> i) & 1;
        int k = (border >> i) & 1;
        int y = x ^ 1;
        auto& child = trie[cur].child;

        if (k == 1) {
            if (child[y] != -1) cur = child[y];
            else ok = 0;
        } else {
            if (child[y] != -1) {
                res = min(res, trie[child[y]].idx);
            }
            if (child[x] != -1) {
                cur = child[x];
            } else ok = 0;
        }
    }

    if (ok) res = min(res, trie[cur].idx);
    return res;
} 

void add(vector<node> &trie, int value, int index) {
    int cur = 0;
    trie[cur].idx = min(trie[cur].idx, index);
    for (int i = LOG; i>=0; i--) {
        int x = (value >> i) & 1;
        if (trie[cur].child[x] == -1) {
            trie[cur].child[x] = trie.size();
            trie.push_back(node());
        }
        cur = trie[cur].child[x];
        trie[cur].idx = min(trie[cur].idx, index);
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1), pre(n+1, 0);
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] ^ a[i];
    }

    int mx = -1;
    pair<int, int> res;
    vector<node> trie(1);
    for (int i = 0; i<=n; i++) {
        if (i > 0) {
            int j = query(trie, pre[i], k);
            if (j != INF) {
                if (mx < i-j) {
                    mx = i-j;
                    res = {j+1, mx};
                }
            }
        }
        add(trie, pre[i], i);
    }
    cout << res.first << " " << res.second << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}