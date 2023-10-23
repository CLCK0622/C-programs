#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, p;
struct point {
    int oc, c;
    int u;
} a[105];
vector<int> v[105];
vector<int> fv[105];
int w[105][105];
vector<int> L;
queue<int> S;
int in[105], out[105];
int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].oc;
        cin >> a[i].u;
    }
    for (int i = 1; i <= p; i++) {
        int uu, vv, ww;
        cin >> uu >> vv >> ww;
        v[uu].push_back(vv);
        fv[vv].push_back(uu);
        w[uu][vv] = ww;
        out[uu] ++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j : v[i]) {
            in[j] ++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] != 0) {
            a[i].c = a[i].oc - a[i].u;
        } else {
            a[i].c = a[i].oc;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            S.push(i);
        }
    }
    while (!S.empty()) {
        int u = S.front();
        L.push_back(u);
        S.pop();
        for (int i : v[u]) {
            in[i] --;
            if (in[i] == 0) {
                S.push(i);
            }
        }
    }
    for (int i : L) {
        for (int j : fv[i]) {
            int u = j;
            int v = i;
            if (a[u].c > 0) {
                a[v].c += a[u].c * w[u][v];
            }
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (a[i].c > 0 && out[i] == 0) {
            cout << i << " " << a[i].c << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "NULL" << endl;
    }
    return 0;
}