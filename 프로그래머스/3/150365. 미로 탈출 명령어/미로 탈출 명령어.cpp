#include <bits/stdc++.h>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int dist = abs(r - x) + abs(c - y);
    if (dist > k || (k - dist) % 2 != 0) return "impossible";

    while (k > 0) {
        dist = abs(r - x) + abs(c - y);
        if (dist == k) {
            while (x < r) { x++; answer += 'd'; }
            while (y > c) { y--; answer += 'l'; }
            while (y < c) { y++; answer += 'r'; }
            while (x > r) { x--; answer += 'u'; }
            break;
        }
        if (x + 1 <= n && abs(r - (x + 1)) + abs(c - y) <= k - 1 && ((k - 1 - (abs(r - (x + 1)) + abs(c - y))) % 2 == 0)) {
            x++; answer += 'd';
        } else if (y - 1 >= 1 && abs(r - x) + abs(c - (y - 1)) <= k - 1 && ((k - 1 - (abs(r - x) + abs(c - (y - 1)))) % 2 == 0)) {
            y--; answer += 'l';
        } else if (y + 1 <= m && abs(r - x) + abs(c - (y + 1)) <= k - 1 && ((k - 1 - (abs(r - x) + abs(c - (y + 1)))) % 2 == 0)) {
            y++; answer += 'r';
        } else {
            x--; answer += 'u';
        }
        k--;
    }
    return answer;
}
