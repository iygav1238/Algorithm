#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

struct Node {
    Node *child[2] = {nullptr, nullptr};

    void insert(const string& s) {
        Node* cur = this;
        for (auto c : s) {
            int x = c - '0';
            if (!cur->child[x]) cur->child[x] = new Node;
            cur = cur->child[x];
        }
    }

    int search(const string& s) {
        Node* cur = this;
        int res = 0;
        for (auto c : s) {
            int x = c - '0';
            int y = x ^ 1;
            res <<= 1;
            if (cur->child[y]) {
                res |= 1;
                cur = cur->child[y];
            } else cur = cur->child[x];
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    Node *trie = new Node;

    int res = 0;
    for (int i = 0; i<n; i++) {
        string cur = "";
        for (int j = 31; j>=0; j--) {
            if (a[i] & (1 << j)) cur += "1";
            else cur += "0";
        }

        if (i > 0) {
            int y = trie->search(cur);
            res = max(res, y);
        }
        trie->insert(cur);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}