#include <iostream>
using namespace std;
int n, ans;
int a[250];
int f[250][250];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][i] = a[i];
    }
    for (int l = 0; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k <= j; k++) {
                if (f[i][k] == f[k + 1][j] && f[i][k] > 0) f[i][j] = max(f[i][j], f[i][k] + 1);
                ans = max(ans, f[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}