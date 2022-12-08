#include <bits/stdc++.h>
using namespace std;
int n, m, f[10005];
int p1, p2, p3;
int find(int k) {
    if (f[k] == k) return k;
    return f[k] = find(f[k]);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> p1 >> p2 >> p3;
        if (p1 == 1) {
            f[find(p2)] = find(p3);
        } else {
            if (find(p2) == find(p3)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}