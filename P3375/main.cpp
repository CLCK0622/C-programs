#include <iostream>
using namespace std;
string s1, s2;
int pi[1000005];
void count() {
    int n = s2.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s2[i] != s2[j]) {
            j = pi[j - 1];
        }
        if (s2[i] == s2[j]) j++;
        pi[i] = j;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    count();
    for (int i = 0; i < s1.length() - s2.length() + 1; i++) {
        bool flag = true;
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i + j] != s2[j]) {
                flag = false;
//                i += pi[j];
                break;
            }
        }
        if (flag) {
            cout << i + 1 << endl;
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        cout << pi[i] << " ";
    }
    cout << endl;
    return 0;
}
