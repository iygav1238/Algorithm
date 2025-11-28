#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define FOR(i, a, b, c) for (int i = a; (c > 0 ? i<=b : i>=b); i+=c)

#define heap priority_queue
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>

#define YES "YES"
#define NO "NO"

const int MOD = 998244353;
const int INF = 1e18+2;

struct Trie {
    struct Node {
        Node *child[2] = {nullptr, nullptr};
        int cnt = 0;
    };
    Node *root;

    Trie() {
        root = new Node();
    }
    
    void Insert(int a) {
        Node *node = root;
        FOR(i, 60, 0, -1) {
            int x = ((1LL << i) & a) ? 1 : 0;
            if (!node->child[x]) node->child[x] = new Node();
            node = node->child[x];
            node->cnt++;
        }
    }

    void Remove(int a) {
        Node *node = root;
        FOR(i, 60, 0, -1) {
            int x = ((1LL << i) & a) ? 1 : 0;
            node = node->child[x];
            node->cnt--;
        }
    }

    int Search(int a) {
        Node *node = root;
        int res = 0;
        FOR(i, 60, 0, -1) {
            int x = ((1LL << i) & a) ? 1 : 0;
            if (!node->child[x ^ 1] || node->child[x ^ 1]->cnt == 0) node = node->child[x];
            else {
                node = node->child[x ^ 1];
                res |= (1LL << i);
            }
        }
        return res;
    }
} trie;

void solve() {
    int n; cin >> n;
    vi a(n+1);
    FOR(i, 1, n, 1) {
        cin >> a[i];
        trie.Insert(a[i]);
    }
    int res = 0;
    FOR(i, 1, n, 1) {
        trie.Remove(a[i]);
        res = max(res, trie.Search(a[i]));
        trie.Insert(a[i]);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();    
    return 0;
}