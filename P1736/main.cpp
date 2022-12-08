#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt1, cnt2;
int mp[2505][2505];
int f[2505][2505][2];
void count(int &m1, int &m2, int &m3, int &mm3, int x, int y) {
    cnt1 = 0; cnt2 = 0;
    int tmp1 = 2505; int tmp2 = 2505;
    for (int i = 1; i <= f[x - 1][y - 1][0]; i++) {
        if (mp[x - i][y]) {
            m3++;
            tmp1 = min(tmp1, i);
        }
        if (mp[x][y - i]) {
            m1++;
            tmp2 = min(tmp2, i);
        }
    }
    cnt1 = min(tmp1, tmp2) - 1;
    tmp1 = tmp2 = 2505;
    for (int i = 1; i <= f[x - 1][y + 1][1]; i++) {
        if (mp[x - i][y]) {
            mm3++;
            tmp1 = min(tmp1, i);
        }
        if (mp[x][y + i]) {
            m2++;
            tmp2 = min(tmp2, i);
        }
        cnt2 = min(tmp1, tmp2) - 1;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!mp[i][j]) continue;
            int m1 = 0, m2 = 0, m3 = 0, mm3 = 0;
            count(m1, m2, m3, mm3, i, j);
            if (!m1 && !m3) {
                f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][0] + 1);
            } else {
                f[i][j][0] = cnt1 + 1;
            }
            if (!m2 && !mm3) {
                f[i][j][1] = max(f[i][j][1], f[i - 1][j + 1][1] + 1);
            } else {
                f[i][j][1] = cnt2 + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, max(f[i][j][0], f[i][j][1]));
        }
    }
    cout << ans << endl;
    return 0;
}