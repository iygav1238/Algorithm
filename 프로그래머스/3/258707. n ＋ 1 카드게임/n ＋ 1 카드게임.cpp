#include <bits/stdc++.h>
using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    int answer = 1;
    set<int> hav, keep;
    for (int i = 0; i<n/3; i++) hav.insert(cards[i]);

    for (int i = n/3; i<n; i+=2) {
        keep.insert(cards[i]);
        keep.insert(cards[i+1]);

        bool ok = false;
        int y = -1;
        for (auto x : hav) {
            int req = n+1-x;
            if (hav.find(req) != hav.end()) {
                ok = true;
                y = x;
                break;
            }
        }

        if (y != -1) {
            hav.erase(y);
            hav.erase(n+1-y);
        }

        if (!ok && coin > 0) {
            for (auto x : keep) {
                int req = n+1-x;
                if (hav.find(req) != hav.end()) {
                    hav.erase(req);
                    ok = true;
                    coin--;
                    y = x;
                    break;
                }
            }
            if (y != -1) keep.erase(y);
        }

        if (!ok && coin > 1) {
            for (auto x : keep) {
                int req = n+1-x;
                if (keep.find(req) != keep.end()) {
                    ok = true;
                    coin -= 2;
                    y = x;
                    break;
                }
            }
            if (y != -1) {
                keep.erase(y);
                keep.erase(n+1-y);
            }
        }
        
        if (!ok) break;
        answer++;
    }
    return answer;
}