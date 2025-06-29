#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer = {0, 0, 0, 0}, vis(MAXN, 0);
    vector<vector<int>> graph(MAXN), deg(MAXN, {0, 0});
    int n = 0;
    for (auto x : edges) {
        int u = x[0], v = x[1];
        if (u == v) {
            answer[1]++;
            vis[u] = 1;
        } else {
            graph[u].push_back(v);
            deg[u][0]++; deg[v][1]++;
        }
        
        n = max({n, u, v});
    }

    vector<int> chk;
    for (int i = 1; i<=n; i++) {
        if (vis[i] == 1) continue;
        if (deg[i][0] > 1 && deg[i][1] == 0) { answer[0] = i; vis[i] = 1; }
        else if (deg[i][0] > 1) chk.push_back(i);
    }

    for (auto x : chk) {
        if (vis[x] == 1) continue;
        vector<int> st = {x};
        vis[x] = 1;
        answer[3]++;
        while (!st.empty()) {
            auto u = st.back(); st.pop_back();
            for (auto v : graph[u]) {
                if (vis[v] == 0) {
                    vis[v] = 1;
                    st.push_back(v);
                }
            }
        }
    }

    for (int i = 1; i<=n; i++) {
        if (vis[i] == 1) continue;
        if (deg[i][0] == 0 && deg[i][1] == 0) continue;
        bool cycle = false, vv = false;

        vector<int> st = {i};
        vis[i] = 1;
        while (!st.empty()) {
            auto u = st.back(); st.pop_back();
            if (deg[u][0] == 0) vv = true;
            for (auto v : graph[u]) {
                if (vis[v] == 0) {
                    vis[v] = 1;
                    st.push_back(v);
                } else {
                    if (v == i) cycle = true;
                }
            }
        }

        if (cycle) answer[1]++;
        if (vv) answer[2]++;
    }

    return answer;
}