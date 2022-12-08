#include <iostream>
using namespace std;
int n, ans;
int a[100005];
int f[100005];
int mx[100005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (f[i] > mx[i - 1]) break;
            if ((a[i] & a[j]) != 0) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        mx[i] = max(mx[i - 1], f[i]);
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}