#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int ans = -1;
int main() {
    cin >> n;
    cin >> s;
    int ls = s.size();
    s = s + s + s;
    string ss = s;
//    cout << s << endl;
    for (int i = ls; i <= 2 * ls + 1; i++) {
        s = ss;
        int c1 = 1, c2 = 1;
        int l = i, r = i + 1;
        int ll = l - 1, rr = r + 1;
        while (s[ll] == s[l] || s[l] == 'w' || s[ll] == 'w') {
            if (ll < 0) break;
            if (s[ll] == 'w') s[ll] = s[l];
            c1++; l--; ll--;
        }
        while (s[rr] == s[r] || s[r] == 'w' || s[rr] == 'w') {
            if (rr >= 3 * ls) break;
            if (s[rr] == 'w') s[rr] = s[r];
            c2++; r++; rr++;
        }
        ans = max(ans, c1 + c2);
//        cout << s << endl;
//        if (ans == c1 + c2) cout << i << " " << c1 + c2 << " " << ll << " " << rr << endl;
    }
    ans = min(ans, ls);
    cout << ans << endl;
    return 0;
}