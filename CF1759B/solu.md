~~������ˮһ��~~

��˵˼·��

��ȻҪ����Ǵ� $1$ �� $n$ �ĺϷ������У���ô�ض��� $1$ �� $n$ ���������ֹ��ɣ����������ʱ�����ֽ��б�ǣ��ȴ� $1$ ��ȫ�� $max{b_1, ..., b_m}$������ʱ�Ѿ����� $sum$ ��Ϊ `false`; �������ʱ��û�����꣬��� $max + 1$ ��ʼ���β��㣬���Ƿ���ʹ�ò�ȫ���ֵĺ����õ��� $sum$���������� `false`����֮��Ϊ `true`��

�ϴ����ˣ�

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int t;
bool flag;
int m, s, mx;
bool vis[5005];
bool check() {
    for (int i = 1; i <= mx; i++) { // �ж���û�в�ȫ
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
        if (sum == s && check()) { // �Ƿ�Ϸ� && �Ƿ���У�
            flag = true;
            return ;
        }
        if (sum > s) return ; // ������ֱ�� false
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
            mx = max(mx, tmp); // �������
            vis[tmp] = true; // ���
        }
        work();
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
```

�������~