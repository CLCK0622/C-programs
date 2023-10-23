#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, ans = 0x3f3f3f3f;
vector<int> a[200005];
bool ava[200005];
bool fava[200005];
bool vis[200005];
int s, t;
void dfs(int x) {
    vis[x] = true;
    if (x == t) {
        ava[x] = true;
        return ;
    }
    if (a[x].size() == 0) ava[x] = false;
    for (int j : a[x]) {
        if (!vis[j]) dfs(j);
        ava[x] |= ava[j];
    }
}
void fdfs(int x, int lg) {
    if (x == t) {
        ans = min(ans, lg);
        return ;
    }
    for (int j : a[x]) {
        if (fava[j] && !vis[j]) {
            vis[j] = 1;
            fdfs(j, lg + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    cin >> s >> t;
//    memset(ava, 1, sizeof ava);
    ava[t] = fava[t] = true;
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
        if (!a[i].empty()) fava[i] = true;
        for (int j : a[i]) {
            fava[i] &= ava[j];
        }
    }
//    for (int i = 1; i <= n; i++) {
//        cout << a[i].size() << " ";
//    }
//    cout << endl;
//    for (int i = 1; i <= n; i++) {
//        cout << ava[i] << " ";
//    }
//    cout << endl;
//    for (int i = 1; i <= n; i++) {
//        cout << fava[i] << " ";
//    }
//    cout << endl;
    if (!ava[s] || !fava[s]) {
        cout << -1 << endl;
        return 0;
    }
    fdfs(s, 0);
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
    return 0;
}