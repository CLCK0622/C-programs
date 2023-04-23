#include <iostream>
#define int long long
using namespace std;
string s;
int n, nxt[1000005];
int cnt;
signed main() {
    cin >> n;
    cin >> s;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j && (s[i] != s[j])) {
            j = nxt[j];
        }
        if (s[i] == s[j]) j++;
        nxt[i + 1] = j;
    }
    for (int i = 1; i <= n; i++) {
        j = i;
        while (nxt[j]) j = nxt[j];
        if (nxt[i] != 0) nxt[i] = j;
        cnt += i - j;
    }
    cout << cnt << endl;
    return 0;
}