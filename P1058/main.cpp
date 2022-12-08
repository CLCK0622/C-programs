#include <bits/stdc++.h>
int n, m, k, l, i, j, x, y;
using namespace std;
char sqr[6][8] = {
                "..+---+",
                "./   /|",
                "+---+ |",
                "|   | +",
                "|   |/.",
                "+---+.."
        };
int a[55][55];
char ans[550][550];
void work(int x, int y) {
    int i, j;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 7; j++)
            if (sqr[6 - i - 1][j] != '.')
                ans[x - i][y + j] = sqr[6 - i - 1][j];
}
int main() {
    cin >> n >> m;
    l = 4 * m + 2 * n + 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            cin >> a[i][j];
            k = max(k, a[i][j] * 3 + 2 * (n - i + 1) + 1);
        }
    for (i = 1; i <= k; i++)
        for (j = 1; j <= l; j++)
            ans[i][j] = '.';
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            x = k - 2 * (n - i);
            y = 2 * (n - i) + 4 * (j - 1) + 1;
            while (a[i][j]--) {
                work(x, y);
                x -= 3;
            }
        }
    for (i = 1; i <= k; i++) {
        for (j = 1; j <= l; j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
