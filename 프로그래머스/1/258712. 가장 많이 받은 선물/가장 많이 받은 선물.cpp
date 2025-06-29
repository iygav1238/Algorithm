#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MOD = 998244353;
const int INF = 1000000000000000002LL;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    string a, b;
    map<string, int> cnt, res;
    map<pair<string, string>, int> table;
    for (auto x : friends) cnt[x] = 0;
    for (auto x : gifts) {
        stringstream s(x);
        s >> a >> b;
        cnt[a]++; cnt[b]--;
        table[{a, b}]++;
    }
    
    for (auto x : friends) {
        for (auto y : friends) {
            if (x == y) continue;
            int c1 = table[{x, y}];
            int c2 = table[{y, x}];
            if ((c1 > c2) || (c1 == c2 && cnt[x] > cnt[y])) res[x]++;
        }
    }

    for (auto [_, x] : res) answer = max(answer, x);
    return answer;
}