#include <iostream>
#include <cstring>
using namespace std;
int n, ans1, ans2 = 0x3f3f3f3f;
int a[205];
int f1[105][105], f2[105][105];
int s[105];
int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        if (i <= n) cin >> a[i];
        if (i > n) a[i] = a[i - n];
        s[i] = s[i - 1] + a[i];
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= 2 * n - l + 1; i++) {
            int j = i + l - 1;
            f2[i][j] = 0x3f3f3f3f;
            for (int k = i; k < j; k++) {
                f1[i][j] = max(f1[i][j], f1[i][k] + f1[k + 1][j]);
                f2[i][j] = min(f2[i][j], f2[i][k] + f2[k + 1][j]);
            }
            f1[i][j] += s[j] - s[i - 1];
            f2[i][j] += s[j] - s[i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        ans1 = max(ans1, f1[i][i + n - 1]);
        ans2 = min(ans2, f2[i][i + n - 1]);
    }
    cout << ans2 << endl;
    cout << ans1 << endl;
    return 0;
}