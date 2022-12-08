#include <iostream>
#include <cstring>
using namespace std;
int n, m;
bool fl;
char map[1505][1505];
int vis[1505][1505][3];
int dir[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
};
void dfs(int x, int y, int lxx, int lyy) {
    if (fl) return ;
    if (vis[x][y][0] && (vis[x][y][1] != lxx || vis[x][y][2] != lyy)) {
        fl = 1; return ;
    }
    vis[x][y][0] = 1; vis[x][y][1] = lxx; vis[x][y][2] = lyy;
    for (int i = 0; i < 4; i++) {
        int lx = lxx + dir[i][0];
        int ly = lyy + dir[i][1];
        int tx = (x + dir[i][0] + n) % n;
        int ty = (y + dir[i][1] + m) % m;
        if (map[tx][ty] != '#') {
            if (!vis[tx][ty][0] || vis[tx][ty][1] != lx || vis[tx][ty][2] != ly) {
                dfs(tx, ty, lx, ly);
            }
        }
    }
}
int main() {
    while ((cin >> n >> m)) {
        int bgx, bgy;
        memset(vis, 0, sizeof(vis));
        fl = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'S') {
                    bgx = i, bgy = j;
                }
            }
        }
        dfs(bgx, bgy, bgx, bgy);
        if (fl) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}