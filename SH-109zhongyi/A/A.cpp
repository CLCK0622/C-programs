#include <bits/stdc++.h>
#define int long long
using namespace std;
int t = 0;
int cnt[1000005];
signed main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
//    cout << t << endl;
    for (int i = 0; i < t; i++) {
        memset(cnt, 0, sizeof(cnt));
        int n = 0;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> cnt[i];
        }
        for (int i = 1; i <= n; i++) {
            cnt[i + 1] += cnt[i] / 2;
            if (i == n && cnt[i] >= 2) n++;
            ans += cnt[i] / 2;
            cnt[i] %= 2;
        }
        cout << (ans % 2 ? "Q" : "W") << endl;
    }
    return 0;
}
