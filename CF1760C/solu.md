如题意，即求对于每一个人，除他以外的最大值与他差别多少。

举一个数列 $1, 2, 3, 5, 5, 5$，易得答案是 $-4, -3, -2, 0, 0, 0$，在计算过程中，发现除了其自身，我们只会用到最大值和次大值（可以相等），对于非最大则减去最大，对于最大值则减去次大值即可。

上代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
int t;
int mx = 0, mxx = 0;
bool flag = false;
int main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[200005];
        mx = 0, mxx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]); // 最大值
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != mx) {
                mxx = max(mxx, a[i]); // 次大值
            }
            if (a[i] == mx) {
                cnt++;
                if (cnt >= 2) { // 有多个最大值
                    mxx = mx;
                }
            }
        }
        for (int i = 0; i < n; i++) { // 输出
            if (a[i] != mx) cout << a[i] - mx << " ";
            else cout << mx - mxx << " ";
        }
        cout << endl;
    }
    return 0;
}
```

完结撒花（）