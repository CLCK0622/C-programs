### STL�󷨺ã���

������֪�����ַ������Ӻ����У�������һ�� `find(string s)` ������ʹ��**����ܹ��ҵ�һ���ַ�����ش�����ָ��**����֮��**���� `string::npos` ָ��**��

��ˣ�������� STL ������������ `if (s.find(t) != string::npos) {}` ���ж��Ƿ�����һ�Ӵ���

~~ϲ���ּ���~~ �ϴ��룡

```cpp
#include <iostream>
using namespace std;
int t;
string tmp = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
// �Ҳ�� 50 �� char����������ֱ�ӡ����
int main() {
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        if (tmp.find(s) != string::npos) { // ����Ϸ�
            cout << "YES" << endl;
        } else cout << "NO" << endl; // ��֮
    }
    return 0;
}
```

������ˣ��������~