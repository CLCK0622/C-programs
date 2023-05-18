#include <iostream>
using namespace std;
const int mod = 1000000007;
int n, m, k;
int f[805][805][16][2];
int map[805][805];
long long ans;
int main() {
    cin >> n >> m >> k; k++;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            f[i][j][map[i][j]][0] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int kk = 0; kk < k; kk++) {
                int h = map[i][j];
                f[i][j][kk][0] += f[i - 1][j][(kk - h + k) % k][1];
                f[i][j][kk][0] += f[i][j - 1][(kk - h + k) % k][1];
                f[i][j][kk][1] += f[i - 1][j][(kk + h) % k][0];
                f[i][j][kk][1] += f[i][j - 1][(kk + h) % k][0];
                f[i][j][kk][0] %= mod;
                f[i][j][kk][1] %= mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += f[i][j][0][1];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
 * f[i][j][p][q] (i, j) |a-uim|=p q=0->a q=1->uim
 * f[i][j][p][1] = f[i - 1][j][(p - h) % k][0]
 * f[i][j][p][1] = f[i][j - 1][(p - h) % k][0]
 * f[i][j][p][0] = f[i - 1][j][(p + h) % k][1]
 * f[i][j][p][0] = f[i][j - 1][(p + h) % k][1]
 *
 * f[i][j][h][0] = h;
 */