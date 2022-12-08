如翻译（推销自己）所言，只需要统计每个单词中用到的最后一个字符在字母表中的位置。

因此，在读取完后（其实甚至可以不存字符串），遍历字串并对 `s[i] - 'a' + 1` 维护最大值。

最后输出即可。

```cpp
#include <iostream>
using namespace std;
int t;
int main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt = max(cnt, s[i] - 'a' + 1);
        }
        cout << cnt << endl;
    }
    return 0;
}
```

完结撒花~