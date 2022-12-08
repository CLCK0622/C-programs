#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int ans[50005];
signed main() {
    cin >> n >> m;
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        int tmp = (n - i) * (n - i - 1) / 2;
        if (m <= tmp) {
            ans[l++] = i;
        } else {
            ans[r--] = i;
            m -= (r - l + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}