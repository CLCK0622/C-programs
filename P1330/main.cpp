#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;

struct node {
    int to, nxt;
} NDS[maxm];
int head[maxm];
int cnt;

int n, m;
int vis[maxn], col[maxn];
bool fl = 1;
int sum[2];
int ans;

void add(int x, int y) {
    head[x] = ++cnt;
    NDS[cnt].to = y;
    NDS[cnt].nxt = head[x];
}

void bfs(int t, int cl) {
    vis[t] = 1; col[t] = cl;
    queue<int> q;
    q.push(t);
    while (!q.empty()) {
        int tp = q.front();
        q.pop();
        for (int i = head[tp]; i; i = NDS[i].nxt) {
            int y = NDS[i].to;
            cout << tp << y << vis[y] << col[tp] << col[y] << endl;
            if (!vis[y]) {
//                cout << y << 2 - col[tp] % 2 << endl;
                col[y] = 3 - col[tp];
                sum[col[y] - 1]++;
                vis[y] = 1;
                q.push(y);
            } else if (vis[y] && col[y] == col[tp]) {
                cout << "Impossible" << endl;
                fl = 0;
                return ;
            } else if (vis[y]) break ;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            sum[0] = 1, sum[1] = 0;
            bfs(i, 1);
            if (!fl) return 0;
            cout << sum[0] << sum[1] << endl;
            ans += min(sum[0], sum[1]);
        }
    }
    cout << ans << endl;
    return 0;
}
