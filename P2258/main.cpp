#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans = 0x3f3f3f3f;
int r, c;
int mp[20][20];
int f[20][20];
int main() {
    cin >> n >> m;
    cin >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for (int h = 1; h <= pow(2, n); h++) {
        if (__builtin_popcount(h) != r) continue;
        int hh = h;
        int cnt = 1, pos = 0;
        int num[20] = {0};
        int ls[20] = {0};
        while (hh) {
            pos++;
            if (hh & 1) {
                num[cnt++] = pos;
            }
            hh >>= 1;
        }
        for (int i = 1; i <= m; i++) {
            //ls[i] = 0;
            for (int j = 1; j < r; j++) {
                ls[i] += abs(mp[num[j]][i] - mp[num[j + 1]][i]);
            }
        }
        int hc[20][20] = {0};
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < i; j++) {
                for (int k = 1; k <= r; k++) {
                    hc[i][j] += abs(mp[num[k]][i] - mp[num[k]][j]);
                }
            }
        }
        int f[20][20];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++) {
            int mxj = min(i, c);
            for (int j = 1; j <= mxj; j++) {
                if (j == 1) f[i][j] = ls[i];
                else if (j == i) f[i][j] = f[i - 1][j - 1] + ls[i] + hc[i][j - 1];
                else {
                    f[i][j] = 0x3f3f3f3f;
                    for (int k = j - 1; k <= i - 1; k++) {
                        f[i][j] = min(f[i][j], f[k][j - 1] + ls[i] + hc[i][k]);
                    }
                }
                if (j == c)
                    ans = min(ans, f[i][c]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}