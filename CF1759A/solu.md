### STL大法好！！

众所周知，在字符串的子函数中，有这样一个 `find(string s)` 函数，使得**如果能够找到一个字符串则回传串的指针**，反之则**传回 `string::npos` 指针**。

因此，借助这个 STL 函数，可以用 `if (s.find(t) != string::npos) {}` 来判断是否有这一子串。

~~喜闻乐见的~~ 上代码！

```cpp
#include <iostream>
using namespace std;
int t;
string tmp = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
// 最长也就 50 个 char，所以这里直接“打表”
int main() {
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        if (tmp.find(s) != string::npos) { // 如果合法
            cout << "YES" << endl;
        } else cout << "NO" << endl; // 反之
    }
    return 0;
}
```

简洁明了，完结撒花~