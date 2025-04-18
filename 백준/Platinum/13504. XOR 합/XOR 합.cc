#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

struct Node {
    Node *child[2] = {nullptr, nullptr};
    int cnt = 0;
    
    void insert(const vector<int> &s){
        Node *cur = this;
        for (auto x : s) {
            if (!cur->child[x]) cur->child[x] = new Node;
            cur = cur->child[x];
            cur->cnt++;
        }
    }
    
    void remove(const vector<int> &s) {
        Node *cur = this;
        for (auto x : s) {
            cur = cur->child[x];
            cur->cnt--;
        }
    }
    
    int search(const vector<int> &s) {
        Node* cur = this;
        int res = 0;
        for (auto x : s) {
            int y = x ^ 1;
            res <<= 1;
            if (cur->child[y] && cur->child[y]->cnt > 0) {
                res |= 1;
                cur = cur->child[y];
            } else cur = cur->child[x];
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n), pre(n+1, 0);
    for (auto &x : a) cin >> x;
    for (int i = 1; i<=n; i++) pre[i] = pre[i-1] ^ a[i-1];
    
    Node *trie = new Node;
    int res = 0;
    vector<int> cur(32, 0);
    for (int i = 0; i<=n; i++) {
        int x = pre[i];
        for (int i = 31; i>=0; i--) {
            if (x & 1) cur[i] = 1;
            else cur[i] = 0;
            x >>= 1;
        }
        
        if (i > 0) res = max(res, trie->search(cur));
        trie->insert(cur);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();    
    return 0;
}