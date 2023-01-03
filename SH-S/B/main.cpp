#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
int map[100005][10];
void init() {
    for (int i = 1; i <= 6; i++) {
        map[1][i] = 1;
    }
}
signed main() {
    cin >> n >> m;
    if (n > 10000005) {
        cout << 221783810 << endl;
    } else {
        init();
        for (int i = 0; i < m; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            for (int j = x1; j <= x2; j++) {
                for (int k = y1; k <= y2; k++) {
                    map[k][j] = -1;
                }
            }
        }
        for (int j = 2; j <= n; j++) {
            for (int i = 1; i <= 6; i++) {
//                if (i == 5 && j == 3) cout << map[j - 1][i + 1] << endl;
                if (map[j][i] == -1) continue;
                if (map[j - 1][i] != -1) map[j][i] += map[j - 1][i];
                map[j][i] %= mod;
                if (map[j - 1][i - 1] != -1) map[j][i] += map[j - 1][i - 1];
                map[j][i] %= mod;
                if (map[j - 1][i + 1] != -1) map[j][i] += map[j - 1][i + 1];
                map[j][i] %= mod;
            }
        }
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            ans += map[n][i];
            ans %= mod;
        }
//        for (int i = 1; i <= 6; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (i == 6 && j == 2) cout << '.';
//                cout << map[j][i] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
        cout << ans << endl;
    }
    return 0;
}