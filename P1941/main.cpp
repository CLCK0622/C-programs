#include <iostream>
#include <cstring>
using namespace std;
int n, m, k;
struct pipe {
    int p, d, h;
} p[10005];
int x[10005], y[10005];
int f[10005][1005];
bool vis[10005];
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= k; i++) {
        int pp;
        cin >> pp;
        cin >> p[pp].d >> p[pp].h;
    }

}