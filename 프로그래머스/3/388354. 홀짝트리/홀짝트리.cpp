#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+1;
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer = {0, 0};
    vector<int> graph[MAXN], vis(MAXN, 1);
    for (int i = 0; i<edges.size(); i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (auto x : nodes) vis[x] = 0;
    
    for (auto i : nodes) {
        if (vis[i]) continue;
        int c1 = 0, c2 = 0;
        vector<int> st = {i};
        vis[i] = 1;
        int tot = 0;
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            int sz = graph[u].size();
            tot++;
            if (u%2 == sz%2) c1++;
            else c2++;
            for (auto v : graph[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                st.push_back(v);
            }
        }
        if (tot == 2) {
            if (c1 == 1) {
                answer[0]++;
                answer[1]++;
            }
        } else {
            if (c1 == 1) answer[0]++;
            else if (c2 == 1) answer[1]++;
        }
    }
    
    return answer;
}