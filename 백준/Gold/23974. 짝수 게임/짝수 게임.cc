/*
    Author : iygav1238
    백트래킹을 통해 규칙 찾기
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

const int MOD = 998244353;

int cur = 0;

// bool bt(int turn, int rest) {
//     if (rest == 0) {
//         return (cur % 2 == 0);
//     }

//     if (turn == 0) {
//         for (int i = 1; i <= 4; i++) {
//             if (rest >= i) {
//                 cur += i;
//                 bool win = bt(1, rest - i);
//                 cur -= i;
//                 if (win) return true;
//             }
//         }
//         return false;
//     } else {
//         for (int i = 1; i <= 4; i++) {
//             if (rest >= i) {
//                 bool win = bt(0, rest - i);
//                 if (!win) return false;
//             }
//         }
//         return true;
//     }
// }


// void test() {
//     for (int n = 0; n <= 1; n++) {
//         cout << "N = " << n << " : ";
//         for (int k = 1; k <= 20; k++) {
//             cur = n;
//             bool res = bt(0, k);
//             if (!res) cout << k << " ";
//         }
//         cout << endl;
//     }
// }

void solve() {
    int n, k; cin >> n >> k;
    if (n == 0) {
        if ((k-1)%6 == 0) cout << "HS" << endl;
        else cout << "YG" << endl;
    } else {
        int res = k%6;
        if (res == 5 || res == 0) cout << "HS" << endl;
        else cout << "YG" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //test();
    solve();    
    return 0;
}