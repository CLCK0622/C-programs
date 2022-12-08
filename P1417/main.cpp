#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
struct node {
    int a, b, c;
} p[55];
int f[100005];
bool cmp(node a, node b) {
    return 1ll * a.c * b.b < 1ll * b.c * a.b;
}
void read() {
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].b;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].c;
    }
}
signed main() {
    cin >> t >> n;
    read();
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= p[i].c; j--) {
            f[j] = max(f[j], f[j - p[i].c] + p[i].a - j * p[i].b);
        }
        for (int j = 1; j <= t; j++) {
            f[j] = max(f[j - 1], f[j]);
        }
    }
    int ans = -1;
    for (int i = 1; i <= t; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}