#include <iostream>
using namespace std;
int n, m, t, ans;
int a[55][55];
int f[55][55][2505][2];
int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= t; k++) {
                if (j == 1) {
                    f[i][j][k][0] = max(f[i - 1][m][k - 1][0], f[i - 1][m][k - 1][1]);
                    f[i][j][k][1] = max(f[i - 1][m][k - 1][0], f[i - 1][m][k - 1][1]) + 1;
                } else {
                    if (a[i][j] == a[i][j - 1]) {
                        f[i][j][k][1] = max(f[i][j - 1][k][1] + 1, f[i][j - 1][k - 1][0] + 1);
                        f[i][j][k][0] = max(f[i][j - 1][k][0], f[i][j - 1][k - 1][1]);
                    } else {
                        f[i][j][k][1] = max(f[i][j - 1][k - 1][1] + 1, f[i][j - 1][k][0] + 1);
                        f[i][j][k][0] = max(f[i][j - 1][k][1], f[i][j - 1][k - 1][0]);
                    }
                }
                ans = max(max(f[i][j][k][1], f[i][j][k][0]), ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}