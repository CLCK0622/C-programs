#include <iostream>
using namespace std;
const int inf = 1000;
int n;
struct flower {
    int c, a, t;
} p[10005];
int dt;
int f[1005];
int main() {
    int th1, tm1, th2, tm2;
    scanf("%d:%d %d:%d %d", &th1, &tm1, &th2, &tm2, &n);
    dt = th2 * 60 + tm2 - th1 * 60 - tm1;
//    cout << dt << endl;
//    printf("%d %d %d %d %d\n", th1, tm1, th2, tm2, n);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].t >> p[i].c >> p[i].a;
    }
    for (int i = 1; i <= n; i++) {
        if (!p[i].a) {
            for (int j = p[i].t; j <= dt; j++) {
                f[j] = max(f[j], f[j - p[i].t] + p[i].c);
            }
        } else {
            for (int k = 1; k <= p[i].a; k++) {
                for (int j = dt; j >= k * p[i].t; j--) {
                    f[j] = max(f[j], f[j - p[i].t] + p[i].c);
                }
            }
        }
    }
    cout << f[dt] << endl;
    return 0;
}