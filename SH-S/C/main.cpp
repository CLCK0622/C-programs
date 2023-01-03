#include <iostream>
using namespace std;
int n, m;
int ans = 0;
struct qj {
    int l, r;
} p[200005];
bool v[10000005] = {0};
int main() {
    cin >> n >> m;
    int mm = m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r;
    }
    while (m--) {
        int ll, rr;
        cin >> ll >> rr;
        memset(v, 0, sizeof v);
        for (int i = 1; i <= n; i++) {
            if (p[i].l >= ll && p[i].r <= rr) {
                for (int j = p[i].l; j <= p[i].r; j++) {
                    v[j] = true;
                }
            }
        }
        int len = 0;
        for (int i = ll; i <= rr; i++) {
            if (v[i]) len++;
        }
        if (m == mm) ans = len;
        else ans = ans xor (len);
    }
    cout << ans << endl;
    return 0;
}