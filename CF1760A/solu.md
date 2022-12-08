如题，现在需要求出三个数的中位数。

中位数的定义：题目中说明的是**不是最大也不是最小的那个数**，但如果直接理解为排好序后位列中间的那个数则题意更简单。

因此用 `<algorithm>` 库中的 `sort` 函数排序后输出中项即可。

上代码！

```cpp
#include <bits/stdc++.h>
using namespace std;
int t;
int main(/*CLCK*/) {
    cin >> t;
    while (t--) {
        int a[3];
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a, a + 3);
        cout << a[1] << endl;
    }
    return 0;
}
```

qwq

完结撒花~