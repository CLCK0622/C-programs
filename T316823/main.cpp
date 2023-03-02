#include <iostream>
#include <cstring>

using namespace std;
int N, t;
int map[1005][1005];
struct point {
    int x, y;
    int num;
} ban[1000005];
int head[1000005];
int tot;
int to[1000005];
bool vis[1000005];
int ans;
struct node {
    int to, nxt;
} e[1000005];

void add(int a, int b) {
    e[++tot].to = b;
    e[tot].nxt = head[a];
    head[a] = tot;
}

void build_map() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != 1 && map[i - 1][j]) add(map[i][j], map[i - 1][j]);
            if (j != 1 && map[i][j - 1]) add(map[i][j], map[i][j - 1]);
            if (i != N && map[i + 1][j]) add(map[i][j], map[i + 1][j]);
            if (j != N && map[i][j + 1]) add(map[i][j], map[i][j + 1]);
        }
    }
}

bool find(int x) {
    int xx;
    for (int i = head[x]; i; i = e[i].nxt) {
        xx = e[i].to;
        if (!vis[xx]) {
            vis[xx] = true;
            if (!to[xx] || find(to[xx])) {
                to[xx] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> t;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = (i - 1) * N + j;
        }
    }
    for (int i = 1; i <= t; i++) {
        cin >> ban[i].x >> ban[i].y;
        map[ban[i].x][ban[i].y] = 0;
    }
    build_map();
    for (int i = 1; i <= N * N; i++) {
        memset(vis, 0, sizeof vis);
        if (find(i)) ans++;
    }
    cout << ans / 2 << endl;
    return 0;
}