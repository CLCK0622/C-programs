#include <iostream>
using namespace std;
string s;
int ans, ansi;
string anss;
int f[1000005];
int main() {
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            f[i] = 0;
        } else {
            if ((s[i] == ')' && s[i - 1 - f[i - 1]] == '(') || (s[i] == ']' && s[i - 1 - f[i - 1]] == '[')) {
                f[i] = f[i - 1] + 2 + f[i - 2 - f[i - 1]];
                if (f[i] > ans) {
                    ans = f[i];
                    anss = s.substr(i - f[i] + 1, ans);
                    ansi = i;
                }
            } else {
                f[i] = 0;
            }
        }
    }
    cout << anss << endl;
    return 0;
}