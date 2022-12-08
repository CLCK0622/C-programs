#include <bits/stdc++.h>
using namespace std;
int n;
int m[5005];
int f[5005];
vector<int> v[5005];
int ct[5005];
set<vector<int> > s;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        f[i] = 1;
        ct[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (m[i] < m[j]) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    ct[i] = ct[j];
                } else if (f[i] == f[j] + 1) {
                    ct[i] += ct[j];
//                    cout << i << " " << j << endl;
                }
            }
            if (f[i] == f[j] && m[i] == m[j]) {
                ct[i] = 0;
            }
        }
    }
    int ans = -1, act = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] > ans) {
            ans = f[i];
            act = ct[i];
        } else if (f[i] == ans) {
            act += ct[i];
        }
    }
//    for (int i = 1; i <= n; i++) {
//        cout << ct[i] << " ";
//    }
//    cout << endl;
    cout << ans << " " << act << endl;
    return 0;
}