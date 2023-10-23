#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int T;
int n, h, r;
struct ball {
    int x, y, z, up, dn;
} b[1005];
int f[1005];
bool intersect(int i, int j) {
    int x1 = b[i].x, y1 = b[i].y, z1 = b[i].z;
    int x2 = b[j].x, y2 = b[j].y, z2 = b[j].z;
    if ((x2 - x1) * (x2 - x1)
     + (y2 - y1) * (y2 - y1)
     + (z2 - z1) * (z2 - z1) <= 4 * r * r) {
        return true;
    }
    return false;
}
bool cmp(ball a, ball b) {
    return a.z <= b.z;
}
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int a, int b) {
    f[find(a)] = find(b);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) {
            cin >> b[i].x >> b[i].y >> b[i].z;
            b[i].up = (b[i].z + r >= h);
            b[i].dn = (b[i].z - r <= 0);
        }
        sort(b + 1, b + n + 1, cmp);
        for (int i = 1; i <= n; i++) f[i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (intersect(i, j)) {
                    merge(i, j);
                }
            }
        }
        bool flag = false;
        for (int j = 1; j <= n; j++) {
            int i = j;
            bool flagup = false, flagdn = false;
            for (;;) {
                if (b[i].up == true) {
                    flagup = true;
                }
                if (b[i].dn == true) {
                    flagdn = true;
                }
                if (flagup && flagdn) break;
                if (f[i] != i) {
                    i = f[i];
                } else break;
            }
            if (flagup && flagdn) flag = true;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}