#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int l, ans = 0x3f3f3f3f;
int s, t, m;
int oa[105], a[105];
bool st[30500];
int f[30500];
signed main() {
    cin >> l;
    cin >> s >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> oa[i];
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    sort(oa + 1, oa + m + 1);
    if (s == t) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += (oa[i] % s == 0);
        }
        cout << cnt << endl;
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        a[i] = a[i - 1] + min(s * t, oa[i] - oa[i - 1]);
        st[a[i]] = true;
    }
    int ll = a[m] + s * t;
    for (int i = 1; i <= ll; i++) {
        for (int j = s; j <= t; j++) {
            if (i - j >= 0) {
                if (st[i]) f[i] = min(f[i], f[i - j] + 1);
                else f[i] = min(f[i], f[i - j]);
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = a[m]; i <= ll; i++) {
        ans = min(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}