#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans;
int a[200005];
int v[200005];
int now[200005];
bool vis[200005];
inline void work() {
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        if (!vis[a[now[i]]]) {
            cnt += v[now[i]];
            vis[a[now[i]]] = 1;
        }
    }
    ans = max(ans, cnt);
}
signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        now[i] = i + 1;
        cin >> a[i] >> v[i];
    }
    while (next_permutation(now, now + n)) {
        work();
    }
    cout << ans << endl;
    return 0;
}