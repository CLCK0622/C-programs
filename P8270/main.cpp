#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
string s, t, s1, t1;
string q;
int T, n;
bool fl;
bool a[20][20];
int cnt[20];
bool check(int x, int y) {
	s1 = t1 = "";
	for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c - 'a' == x || c - 'a' == y) s1 = s1 + c;
    }
	for(int i = 0; i < t.size(); i++) {
        char c = t[i];
        if (c - 'a' == x || c - 'a' == y) t1 = t1 + c;
    }
	return s1 == t1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> s >> t;
    cin >> T;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
        cnt[t[i] - 'a']--;
    }
    for (int i = 0; i < 17; i++) {
        for (int j = i + 1; j < 18; j++) {
            a[i][j] = check(i, j);
        }
    }
	while (T--) {
		cin >> q;
		sort(q.begin(), q.end());
		n = q.size();
		fl = 1;
        for (int i = 0; i < q.size(); i++) {
            if (cnt[q[i] - 'a'] != 0) {
                cout << "N";
                fl = 0;
                break;
            }
        }
		if (!fl)
            continue;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!a[q[i] - 'a'][q[j] - 'a']) {
                    cout << "N";
                    fl = 0; break;
                }
            }
            if (!fl) break;
        }
		if (fl) cout << 'Y';
	}
    cout << endl;
    return 0;
}
