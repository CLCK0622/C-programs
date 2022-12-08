#include <iostream>
using namespace std;
int n, m;
int p[400], sc[200];
int f[45][45][45][45];
int ct[5];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> sc[i];
        ct[sc[i]]++;
    }
    int a = ct[1], b = ct[2], c = ct[3], d = ct[4];
    f[0][0][0][0] = p[1];
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                for (int l = 0; l <= d; l++) {
                    int x = i + j * 2 + k * 3 + l * 4 + 1;
                    if (i) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l] + p[x]);
                    if (j) f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l] + p[x]);
                    if (k) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l] + p[x]);
                    if (l) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1] + p[x]);
                }
            }
        }
    }
    cout << f[a][b][c][d] << endl;
    return 0;
}