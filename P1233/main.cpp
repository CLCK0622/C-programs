#include <bits/stdc++.h>
using namespace std;
int n;
struct stick {
    int l, w;
} p[5005];
int f[5005];
bool cmp(stick a, stick b) {
    if (a.l != b.l) return a.l > b.l;
    return a.w > b.w;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].w;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (p[i].w < p[j].w) {
                f[j] = max(f[j], f[i] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}