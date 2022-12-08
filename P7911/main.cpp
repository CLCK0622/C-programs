#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<string> ss;
bool check(string s) {
    int num[30] = {0}; int cnt = 0;
    int sct = 0, dct = 0;
    int tmp = -1;
    for (int i = 0; i < s.size(); i++) {
        if (cnt > 7) return false;
        if (s[i] >= '0' && s[i] <= '9') {
            if (tmp == -1) tmp = 0;
            tmp = tmp * 10 + s[i] - '0';
            if (i == s.size() - 1) {
                num[cnt++] = tmp;
                tmp = -1;
            }
        } else {
            if (i <= s.size() - 3 && s[i + 1] == '0' && s[i + 2] >= '0' && s[i + 2] <= '9') return false;
            if (i == s.size() - 1 || tmp == -1) return false;
            if (tmp != -1) {
                num[cnt++] = tmp;
                if (cnt <= 4 && num[cnt - 1] > 255) return false;
                if (cnt == 5 && num[cnt - 1] > 65535) return false;
                tmp = -1;
            }
            //cout << tmp << endl;
            if (s[i] == '.') dct ++;
            if (s[i] == ':') {
                sct ++;
                if (dct != 3) return false;
            }
        }
    }
    if (cnt >= 6 || num[4] > 65535 || sct != 1 || dct > 3) return false;
    return true;
}
signed main() {
//    freopen("network4.in", "r", stdin);
//    freopen("n4.out", "w", stdout);
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string tp;
        cin >> tp;
        string s;
        cin >> s;
        //cout << s << endl;
        if (!check(s)) {
            ss.push_back("-1");
            cout << "ERR" << endl;
        } else {
            if (tp == "Server") {
                if (find(ss.begin(), ss.end(), s) != ss.end()) {
                    ss.push_back("-1");
                    cout << "FAIL" << endl;
                } else {
                    ss.push_back(s);
                    cout << "OK" << endl;
                }
            } else {
                ss.push_back("-1");
                if (find(ss.begin(), ss.end(), s) == ss.end()) {
                    cout << "FAIL" << endl;
                } else {
                    cout << (long long)(find(ss.begin(), ss.end(), s) - ss.begin() + 1) << endl;
                }
            }
        }
    }
    return 0;
}
