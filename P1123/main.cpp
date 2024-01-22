#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int T;
int n, m;
int a[10][10], vis[100][100];
int ans;
void dfs(int x, int y, int z) {
    if (x > n) {
        ans = max(ans, z);
        return;
    }
    int px = x, py = y + 1;
    if (py > m) {
        px++;
        py = 1;
    }
    if (!vis[x - 1][y] && !vis[x][y - 1] && !vis[x - 1][y - 1] && !vis[x - 1][y + 1]) {
        vis[x][y] = 1;
        dfs(px, py, z + a[x][y]);
        vis[x][y] = 0;
    }
    dfs(px, py, z);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        dfs(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}