�����⣬�������ÿһ���ˣ�������������ֵ���������١�

��һ������ $1, 2, 3, 5, 5, 5$���׵ô��� $-4, -3, -2, 0, 0, 0$���ڼ�������У����ֳ�������������ֻ���õ����ֵ�ʹδ�ֵ��������ȣ������ڷ�������ȥ��󣬶������ֵ���ȥ�δ�ֵ���ɡ�

�ϴ��룺

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
            mx = max(mx, a[i]); // ���ֵ
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != mx) {
                mxx = max(mxx, a[i]); // �δ�ֵ
            }
            if (a[i] == mx) {
                cnt++;
                if (cnt >= 2) { // �ж�����ֵ
                    mxx = mx;
                }
            }
        }
        for (int i = 0; i < n; i++) { // ���
            if (a[i] != mx) cout << a[i] - mx << " ";
            else cout << mx - mxx << " ";
        }
        cout << endl;
    }
    return 0;
}
```

�����������