#include <iostream>
using namespace std;
int map[10][10];
bool vis[10][10][10];
int num[85];
int cnt = 0;
bool flag = false;
void upd(int x, int y, int stat) {
    for (int i = 0; i < 9; i++) {
       vis[x][i][map[x][y]] = stat;
       vis[i][y][map[x][y]] = stat;
    }
    int xx = x / 3, yy = y / 3;
    for (int i = xx * 3; i < xx * 3 + 3; i++) {
        for (int j = yy * 3; j < yy * 3 + 3; j++) {
            vis[i][j][map[x][y]] = stat;
        }
    }
}
void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
void dfs(int npos) {
    if (npos == cnt) {
        print();
        flag = true;
        return ;
    }
    int x = npos / 9, y = npos % 9;
    for (int i = 1; i <= 9; i++) {
        if (!vis[x][y][i]) {
            map[x][y] = i;
            vis[x][y][i] = true;
            upd(x, y, 1);
            dfs(num[npos + 1]);
            if (flag) return;
            vis[x][y][i] = false;
            upd(x, y, 0);
            map[x][y] = 0;
        }
    }
}
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c; cin >> c;
            if (c > '0' && c <= '9') {
                map[i][j] = c - '0';
                upd(i, j, 1);
            } else if (c == '.') {
                num[cnt++] = i * 9 + j;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << (map[i][j] ? map[i][j] : 0);
        }
        cout << endl;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << num[i] << " ";
    }
//    dfs(num[0]);
    return 0;
}
/*
17.5..8..
.52.1....
.....759.
.8...94.3
.197.4..8
7......15
4.1...6..
3...2..59
...96..3.
 */