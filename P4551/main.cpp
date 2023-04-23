#include <iostream>
using namespace std;
int n;
struct edge {
    int nxt, to;
    int val;
} e[200005];
int head[200005];
int tot;
void add(int x, int y, int w) {
    e[++tot] = (edge){head[x], y, w};
    head[x] = tot;
}
int sum[200001];
void dfs(int x, int fa) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        int w = e[i].val;
        if (y != fa) {
            sum[y] = sum[x] ^ w;
            dfs(y, x);
        }
    }
}
struct trie {
    int ch[2];
} t[200001];
void build(int val, int x) {
    for (int i = (1 << 30); i; i >>= 1) {
        bool c = val & i;
        if (!t[x].ch[c]) {
            t[x].ch[c] = ++tot;
        }
        x = t[x].ch[c];
    }
}
int query(int val, int x) {
    int ans = 0;
    for (int i = (1 << 30); i; i >>= 1) {
        bool c = val & i;
        if (t[x].ch[!c]) {
            ans += i;
            x = t[x].ch[!c];
        } else {
            x = t[x].ch[c];
        }
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        build(sum[i], 0);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, query(sum[i], 0));
    }
    cout << ans << endl;
    return 0;
}
