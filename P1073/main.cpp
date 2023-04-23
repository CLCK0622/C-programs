#include <iostream>
#include <vector>
#include <cmath>
const int inf = 0x3f3f3f3f;
const int N = 100005;
using namespace std;
vector<int> g[N];
int n, m;
int f[N], mi[N], c[N];
void dfs(int x, int minx, int pre) {
    bool flag = true;
    minx = min(c[x], minx);
    if (mi[x] > minx)
        mi[x] = minx, flag = false;
    int maxx = max(f[pre], c[x] - minx);
    if (f[x] < maxx)
        f[x] = maxx, flag = false;
    if (flag)
        return;
    for (int i = 0; i < g[x].size(); i++)
        dfs(g[x][i], minx, x);
}
int main() {
    cin >> n >> m;
    for (int & i : mi)
        i = inf;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        if (t3 == 2)
            g[t2].push_back(t1);
    }
    dfs(1, inf, 0);
    cout << f[n] << endl;
    return 0;
}
