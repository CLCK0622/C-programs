#include <bits/stdc++.h>
using namespace std;
int m, n;
int mp[205][205];
int f[205][205];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], max(f[i - 1][j - 1], f[i - 1][j + 1])) + mp[i][j];
        }
    }
    int ans = 0;
    cout << max(max(f[n][m / 2 + 1], f[n][m / 2]), f[n][m / 2 + 2]) << endl;
    return 0;
}