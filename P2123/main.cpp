#include <bits/stdc++.h>
using namespace std;
#define int long long
struct secr {
    int a, b, d;
} st[20005];
int t;
bool cmp(secr x, secr y) {
    if (x.d != y.d)
        return x.d < y.d;
    if (x.d <= 0)
        return x.a < y.a;
    else
        return x.b > y.b;
}
signed main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> st[i].a >> st[i].b;
            st[i].d = st[i].a - st[i].b;
            if (st[i].d > 0) st[i].d = 1;
            else st[i].d = -1;
        }
        sort(st + 1, st + n + 1, cmp);
        int c = 0, s = 0;
        for (int i = 1; i <= n; i++) {
            s += st[i].a;
            c = max(c, s);
            c += st[i].b;
        }
        cout << c << endl;
    }
    return 0;
}
