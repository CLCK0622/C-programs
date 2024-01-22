#include <iostream>
using namespace std;
int n, m;
char map[105][105];
bool vis[105][105];
int ans;
int dir[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};
bool in(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int px = x + dir[i][0];
        int py = y + dir[i][1];
        if (map[px][py] == 'W' && !vis[px][py]) {
            vis[px][py] = true;
            dfs(px, py);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 'W' && !vis[i][j]) {
                vis[i][j] = true;
                ans ++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}