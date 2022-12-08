#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, ans;
string s;
string tmp[500005];
int cnt = 0;
set<string> ttmp;
void init() {
    for (int i = 0; i < 500005; i++) {
        tmp[i] = "";
    }
    ttmp.clear();
}
int ctper(int x) {
    int ans = 1;
    for (int i = 1; i <= x; i++) {
        ans *= i;
    }
    return ans;
}
int work(int t, int d) {
    set<string> cc;
    for (int i = 0; i < t; i += d) {
        tmp[cnt++] = s.substr(i, d);
        cc.insert(tmp[cnt - 1]);
    }
    if (ttmp.find(s.substr(t, s.size() % d)) != ttmp.end()) {
        return 0;
    } else ttmp.insert(s.substr(t, s.size() % d));
    for (int i = t + s.size() % d + 1; i < s.size(); i += d) {
        tmp[cnt++] = s.substr(i, d);
        cc.insert(tmp[cnt - 1]);
    }
    int tt = cc.size();
//    cout << tt << endl;
    return (ctper(s.size() / d - tt) % mod + (s.size() / d + s.size() / d - tt + 1) * (tt - 1) / 2);
}
signed main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        init();
        for (int j = 0; j < s.size(); j += i) {
            ans += work(j, i);
        }
    }
    cout << ans << endl;
    return 0;
}