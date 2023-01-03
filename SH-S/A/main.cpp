#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int mn = 105, mm = 505;
int n, m, T;
int t[mn], s[mn];
int H[mm], S[mm];
int f[10000005];
int r[10000005];
int ss[10000005];
void init() {
    for (int i = 0; i < 10000001; i++) {
        r[i] = m + 1;
    }
}
int count(int t) {
    for (int i = 1; i <= m; i++) {
        if (t < S[i]) {
            return (m - i + 2);
        }
    }
    return 1;
}
int check(int t, int x) {
    for (int i = 1; i <= x; i++) {
        ss[i] = H[i];
//        cout << H[i] << " ";
    }
    sort(ss + 1, ss + x + 1);
    int cnt = 0, tans = 0;
    for (int i = 1; i <= x; i++) {
        if (cnt + ss[i] > t) return tans;
        cnt += ss[i]; tans++;
    }
    return x;
}
int main() {
    cin >> n >> m >> T;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> H[i] >> S[i];
    }
    sort(S + 1, S + m + 1);
    int ans = m + 1;
//    for (int i = 1; i <= m; i++) cout << S[i] << endl;
    for (int jj = 0; jj <= T; jj++) {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            for (int j = jj; j >= t[i]; j--) {
                if (f[j] < f[j - t[i]] + s[i]) {
                    f[j] = f[j - t[i]] + s[i];
                }
            }
        }
        int bg = count(f[jj]); if (!f[jj]) continue;
//        cout << f[jj] << " " << bg << " " << T - jj << " " << check(T - jj, bg) << endl;
//        if (count(f[jj]) == 1) bg = 1;
        ans = min(ans, bg - check(T - jj, bg));
    }
    cout << ans << endl;
    return 0;
}