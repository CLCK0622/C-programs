#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
int a[100005], b[100005], c[100005];
int upper;
struct node {
    int to, nx, val;
} e[200005];
int tot;
int head[200005];
bool vis[200005];
int col[200005];
void add(int a, int b, int c) {
    e[++tot].to = b;
    e[tot].nx = head[a];
    e[tot].val = c;
    head[a] = tot;
}
bool check(int mid) {
    memset(vis, 0, sizeof vis);
    memset(col, 0, sizeof col);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            col[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int i = head[x]; i; i = e[i].nx) {
                    if (e[i].val < mid) continue;
                    int xx = e[i].to;
                    if (!vis[xx]) {
                        vis[xx] = true;
                        col[xx] = 1 - col[x];
                        q.push(xx);
                    } else {
                        if (col[xx] == col[x]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
int binary(int l, int r) {
    int mid = (l + r) >> 1;
    if (l + 1 >= r) return l;
    if (check(mid)) {
        binary(l, mid);
    } else {
        binary(mid, r);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        add(a[i], b[i], c[i]);
        add(b[i], a[i], c[i]);
        upper = max(upper, c[i]);
    }
    cout << binary(0, upper + 1) << endl;
    return 0;
}