#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
struct node {
    int to, nxt;
} edge[4000005];
int head[1000005], vis[1000005], dep[1000005], ans[1000005];
int cnt = 0;
const int mod = 100003;
void add(int x, int y) {
    edge[++cnt].nxt = head[x];
    edge[cnt].to = y;
    head[x] = cnt;
}
queue<int> q;
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    memset(dep, 0, sizeof dep);
    ans[1] = 1;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (!vis[v]) {
                dep[v] = dep[x] + 1;
                ans[v] = ans[x];
                ans[v] %= mod;
                vis[v] = true;
                q.push(v);
            } else {
                if (dep[v] > dep[x] + 1) {
                    ans[v] = ans[x];
                    ans[v] %= mod;
                    dep[v] = dep[x] + 1;
                } else if (dep[v] != 0 && dep[v] < dep[x] + 1) {
                    continue;
                } else if (dep[v] == dep[x] + 1) {
                    ans[v] += ans[x];
                    ans[v] %= mod;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}