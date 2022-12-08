~~翻译者水一发~~

先说思路：

既然要求的是从 $1$ 到 $n$ 的合法的排列，那么必定有 $1$ 到 $n$ 的所有数字构成，因此在输入时对数字进行标记，先从 $1$ 补全到 $max{b_1, ..., b_m}$，若此时已经超过 $sum$ 则为 `false`; 而如果此时还没有用完，则从 $max + 1$ 开始依次补足，看是否能使得补全数字的和正好等于 $sum$，若超过则 `false`；反之则为 `true`。

上代码了！

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int t;
bool flag;
int m, s, mx;
bool vis[5005];
bool check() {
    for (int i = 1; i <= mx; i++) { // 判断有没有补全
        if (!vis[i]) return false;
    }
    return true;
}
void work() {
    int cnt = 0, sum = 0;
    for (int i = 1; ; i++) {
        if (!vis[i]) {
            cnt++; sum += i;
            vis[i] = 1;
        }
        if (sum == s && check()) { // 是否合法 && 是否可行？
            flag = true;
            return ;
        }
        if (sum > s) return ; // 超过则直接 false
    }
}
int main() {
    cin >> t;
    while (t--) {
        cin >> m >> s;
        memset(vis, 0, sizeof(vis));
        flag = 0; mx = 0;
        for (int i = 1; i <= m; i++) {
            int tmp; cin >> tmp;
            mx = max(mx, tmp); // 记最大数
            vis[tmp] = true; // 标记
        }
        work();
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
```

完结撒花~