#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MN = 105;
int t, n, m, tans[MN], ifvisi[MN], unaval[MN];
char s[MN][MN];
int main() {
    cin >> t;
    while (t--) {
        memset(ifvisi, 0, sizeof(ifvisi));
        memset(unaval, 0, sizeof(unaval));
        int iflie = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            scanf("%s", s[i] + 1);
            cin >> tans[i];
        }
        for (int k = 1; k <= n; k++) {
            int ff = 0;
            for (int i = 1; i <= n; i++) {
                if (unaval[i]) continue;
                int p1 = -1, p2 = -1, f1 = 1, f2 = 1;
                for (int j = 1; j <= m; j++) {
                    if (!ifvisi[j]) {
                        if (s[j][i] == '1') {
                            if (tans[j] == p1 || p1 == -1) p1 = tans[j];
                            else f1 = 0;
                        }
                        if (s[j][i] == '0') {
                            if (tans[j] == p2 || p2 == -1) p2 = tans[j];
                            else f2 = 0;
                        }
                    }
                }
                if (k == n) {
                    if (f1 && f2) {
                        unaval[i] = 1;
                        ff = 1;
                        break;
                    }
                } else {
                    if (f1) {
                        for (int j = 1; j <= m; j++) if (s[j][i] == '1') ifvisi[j] = 1;
                        unaval[i] = 1;
                        ff = 1;
                        break;
                    } else if (f2) {
                        for (int j = 1; j <= m; j++) if (s[j][i] == '0') ifvisi[j] = 1;
                        unaval[i] = 1;
                        ff = 1;
                        break;
                    }
                }
            }
            if (!ff) {
                iflie = 1;
                break;
            }
        }
        if (iflie) cout << "LIE" << endl;
        else cout << "OK" << endl;
    }
    return 0;
}
