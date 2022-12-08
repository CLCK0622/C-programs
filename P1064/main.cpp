#include <iostream>
#include <vector>
#define int long long
using namespace std;
int n, m;
struct object {
    int v, p, q;
} p[65];
int f[32005];
vector<int> mn;
vector<int> v[65];
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p[i].v >> p[i].p >> p[i].q;
        if (p[i].q == 0) mn.push_back(i);
        else v[p[i].q].push_back(i);
    }
    for (int ii = 0; ii < mn.size(); ii++) {
        for (int j = n; j >= p[mn[ii]].v; j--) {
            int i = mn[ii];
            if (v[i].size() == 0) f[j] = max(f[j], f[j - p[i].v] + p[i].v * p[i].p);
            for (int k = 0; k < v[i].size(); k++) {
                if (j < p[v[i][k]].v + p[i].v) continue;
                f[j] = max(f[j], f[j - p[v[i][k]].v - p[i].v] + p[v[i][k]].v * p[v[i][k]].p + p[i].v * p[i].p);
            }
            if (v[i].size() == 2 && j >= p[v[i][0]].v + p[v[i][1]].v + p[i].v) f[j] = max(f[j], f[j - p[v[i][0]].v - p[v[i][1]].v - p[i].v] + p[v[i][0]].v * p[v[i][0]].p + p[v[i][1]].v * p[v[i][1]].p + p[i].p * p[i].v);
        }
    }
    cout << f[n] << endl;
    return 0;
}