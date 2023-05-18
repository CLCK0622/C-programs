#include <iostream>
#include <queue>
#include <cstring>
#define int long long
using namespace std;
int n, m, b;
struct node {
    int nxt, to, w;
} edge[200005];
int head[10005], vis[10005], ans[10005], cnt = 0;
int f[10005];
void add(int u, int v, int w) {
    edge[++cnt].nxt = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt;
}
priority_queue<pair<int, int> > q;
bool check(int x) {
    while (!q.empty()) q.pop();
    memset(ans, 0x3f, sizeof ans);
    memset(vis, 0, sizeof vis);
    ans[1] = 0;
    q.push(make_pair(ans[1], 1));
    vis[1] = 1;
    while (!q.empty()) {
        int u = q.top().second;
        int d = q.top().first;
        q.pop();
        if (ans[u] != d) continue;
        for (int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (f[v] > x && v != n) {
                continue;
            }
            if (!vis[v]) {
                vis[v] = true;
                if (ans[v] > ans[u] + edge[i].w) {
                    ans[v] = ans[u] + edge[i].w;
                    cout << v << " " << vis[v] << endl;
                    q.push(make_pair(ans[v], v));
                }
            }
        }
    }
    return ans[n] <= b;
}
int binary(int l, int r) {
    int mid = (l + r) >> 1;
    if (l + 1 >= r) {
        return l;
    }
    if (check(mid)) {
        return binary(l, mid);
    } else {
        return binary(mid + 1, r);
    }
}
signed main() {
    cin >> n >> m >> b;
    int maxx = -1, minn = 0x7fffffff;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        maxx = max(maxx, f[i]);
    } minn = max(f[1], f[n]);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    int l = binary(minn, maxx);
    if (l > maxx) cout << "AFK" << endl;
    else cout << l << endl;
    return 0;
}