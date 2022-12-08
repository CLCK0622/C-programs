#include <bits/stdc++.h>
#define int long long
using namespace std;
struct edge {
    int v, w;
};
vector<edge> e[10005];
int dis[10005], vis[10005];
int n, m, s;
void dij() {
    for (int i = 0; i <= n; i++) {
        dis[i] = 2147483647;
    }
    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = 0; int md = 2147483647;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] < md) u = j, md = dis[j];
        }
        vis[u] = true;
        for (auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
        }
    }
}
signed main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(edge{v, w});
    }
    dij();
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}