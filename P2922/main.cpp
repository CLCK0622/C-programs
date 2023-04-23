#include <iostream>
#include <cstring>
using namespace std;
int nex[500005][2];
int rd[500005];
int exi[500005];
int m, n, cnt = 1;
int main() {
    cin >> m >> n;
    memset(nex, -1, sizeof nex);
    for (int i = 1; i <= m; i++) {
        int p = 1;
        int l; cin >> l;
        for (int j = 1; j <= l; j++) {
            int x; cin >> x;
            if (nex[p][x] == -1)
                nex[p][x] = ++cnt;
            p = nex[p][x];
            rd[p]++;
        }
        exi[p]++;
    }
    for (int i = 1; i <= n; i++) {
        int p = 1;
        int ans = 0;
        int l; cin >> l;
        bool flag = false;
        for (int j = 1; j <= l; j++) {
            int x; cin >> x;
            if (nex[p][x] == -1) {
                flag = true;
//                break;
            }
            p = nex[p][x];
            ans += exi[p];
        }
        if (!flag) ans += rd[p] - exi[p];
        cout << ans << endl;
    }
    return 0;
}