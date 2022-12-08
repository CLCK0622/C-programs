#include <iostream>
using namespace std;
int n, m, t;
struct dream {
    int m, t;
} p[105];
int f[205][205];
int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].m >> p[i].t;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= p[i].m; j--) {
            for (int k = t; k >= p[i].t; k--) {
                f[j][k] = max(f[j][k], f[j - p[i].m][k - p[i].t] + 1);
            }
        }
    }
    cout << f[m][t] << endl;
    return 0;
}