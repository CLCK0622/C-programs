#include <bits/stdc++.h>
using namespace std;
int t;
bool fg = false;
bool up = false;
int main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[200005];
        up = false;
        fg = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 && a[i] > a[i - 1]) {
                up = true;
            }
            if (i > 0 && up && a[i] < a[i - 1]) {
                cout << "NO" << endl;
                fg = true;
                break;
            }
        }
        if (!fg) cout << "YES" << endl;
    }
    return 0;
}