#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct node {
    int to;
    long long next;
    long long w;
} nds[600010];
int head[300010];
int fa[300010];
long long T[300010], F[300010], G[300010];
long long cnt = 0;
void add(int x, int y) {
    nds[cnt].to = y;
    nds[cnt].next = head[x];
    head[x] = cnt++;
}
unsigned int SA, SB, SC;
bool vis[300010];
int n, m, t1, t2;
long long length[300010];
unsigned int rng61() {
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
long long DP[300010];
void dfs(int x, int k) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = nds[i].next) {
        int y = nds[i].to;
        if (vis[y]) continue;
        if (length[y] < k) continue;
        if (y == fa[x]) {
            DP[y] = min(DP[y], DP[x] + F[x]);
        } else {
            DP[y] = min(DP[y], DP[x] + G[y]);
        }
        dfs(y, k);
    }
}
long long query(int u, int k) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        DP[i] = LLONG_MAX;
    }
    DP[u] = 0;
    long long ans = LLONG_MAX;
    dfs(u, k);
    for (int i = 1; i <= n; i++) {
        if (DP[i] != LLONG_MAX) ans = min(DP[i] + T[i], ans);
    }
    return ans;
}
void solve() {
    long long lastans = 0, output = 0;
    while (m--) {
        int u = (rng61() ^ (t1 * lastans)) % n + 1;
        int k = (rng61() ^ (t1 * lastans)) % (length[u] + 1) * t2;
        lastans = query(u, k);
        output ^= lastans + m;
    }
    printf("%lld\n", output);
}

void pre(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = nds[i].next) {
        int y = nds[i].to;
        if (vis[y]) continue;
        length[y] = length[x] + 1;
        pre(y);
    }
}
int main() {
    freopen("lyric.in", "r", stdin);
    freopen("lyric.out", "w", stdout);
    memset(head, -1, sizeof(head));
    scanf("%d%d%d%d%d%d%d", &n, &m, &SA, &SB, &SC, &t1, &t2);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &T[i]);
    }
    for (int i = 2; i <= n; i++) {
        long long p, f, g;
        scanf("%lld%lld%lld", &p, &f, &g);
        add(i, p);
        add(p, i);
        fa[i] = p;
        F[i] = f;
        G[i] = g;
    }
    pre(1);
    solve();
    return 0;
}
