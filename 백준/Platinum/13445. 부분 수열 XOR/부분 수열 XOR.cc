#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;
const int LOG = 30;

struct node {
    int child[2] = {-1, -1};
    int cnt = 0;
};

int query(const vector<node>& trie, int value, int border) {
    int res = 0, cur = 0, ok = 1;
    int tot = 0;
    for (int i = LOG; ok && i>=0; i--) {
        int x = (value >> i) & 1;
        int k = (border >> i) & 1;
        auto& child = trie[cur].child;

        if (k == 1) {
            if (child[x] != -1) res += trie[child[x]].cnt;
            if (child[x ^ 1] != -1) {
                cur = child[x ^ 1];
                tot |= (1 << i);
            }
            else ok = 0;
        } else {
            if (child[x] != -1) cur = child[x];
            else ok = 0;
        }
    }

    if (ok && (tot < border)) res += trie[cur].cnt;
    return res;
} 

void add(vector<node> &trie, int value) {
    int cur = 0;
    trie[cur].cnt++;
    for (int i = LOG; i>=0; i--) {
        int x = (value >> i) & 1;
        if (trie[cur].child[x] == -1) {
            trie[cur].child[x] = trie.size();
            trie.push_back(node());
        }
        cur = trie[cur].child[x];
        trie[cur].cnt++;
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1), pre(n+1, 0);
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] ^ a[i];
    }

    int res = 0;
    vector<node> trie(1);
    for (int i = 0; i<=n; i++) {
        if (i > 0) res += query(trie, pre[i], k);
        add(trie, pre[i]);
    }
    cout << res << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}