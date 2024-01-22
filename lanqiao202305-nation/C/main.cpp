#include <iostream>
using namespace std;
string s;
int cnt = 0;
int num[205];
int ans = 0;
int main() {
    char c;
    while (cin >> c) {
        if (c != ' ') s += c;
        if (c == EOF || c == '\n') break;
    }
    int tmp1 = 0, tmp2 = 0;
    int op = 1; //1+ 2-
    int stat = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == ' ') continue;
        if (s[i] >= '0' && s[i] <= '9') {
            if (stat == 0) tmp1 *= 10, tmp1 += s[i] - '0';
            else tmp2 *= 10, tmp2 += s[i] - '0';
        } else if (s[i] == '*' || s[i] == '/') {
            if (stat) {
                if (stat == 1) {
                    tmp1 = tmp1 * tmp2;
                    tmp2 = 0;
                } else {
                    tmp1 = tmp1 / tmp2;
                    tmp2 = 0;
                }
            }
            stat = (s[i] == '*' ? 1 : 2);
        } else {
            if (stat) {
                if (stat == 1) {
                    tmp1 = tmp1 * tmp2;
                    tmp2 = 0;
                } else {
                    tmp1 = tmp1 / tmp2;
                    tmp2 = 0;
                }
                stat = 0;
            }
//            cout << op << " " << tmp1 << endl;
            if (op == 1) {
                ans += tmp1;
            } else if (op == 2) {
                ans -= tmp1;
            }
            tmp1 = tmp2 = 0;
            switch(s[i]) {
                case '+':
                    op = 1;
                    break;
                case '-':
                    op = 2;
                    break;
                default:
                    break;
            }
        }
    }
    if (stat) {
        if (stat == 1) {
            tmp1 = tmp1 * tmp2;
            tmp2 = 0;
        } else {
            tmp1 = tmp1 / tmp2;
            tmp2 = 0;
        }
        stat = 0;
    }
    if (op == 1) {
        ans += tmp1;
    } else if (op == 2) {
        ans -= tmp1;
    }
    cout << ans << endl;
    return 0;
}