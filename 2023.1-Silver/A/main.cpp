#include <iostream>
#include <cstring>
using namespace std;
int T;
int map[100];
int fa[100];
bool vis[100];
int main() {
    cin >> T;
    while (T--) {
        string a, b;
        memset(map, 0, sizeof map);
        memset(fa, 0, sizeof fa);
        memset(vis, 0, sizeof vis);
        bool imp = false;
        int cnt = 0;
        cin >> a >> b;
        for (int i = 0; i < a.size(); i++) {
            if (map[a[i] - '0'] == 0) {
                map[a[i] - '0'] = b[i] - '0';
                if (a[i] != b[i]) {
                    fa[b[i] - '0'] = a[i] - '0';
                    cnt++;
                }
            } else {
                if (map[a[i] - '0'] != b[i] - '0') {
                    cout << -1 << endl;
                    imp = true;
                    break;
                }
            }
        }
        if (imp) continue;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
//        if (a == "ABCD") cout << 3 << endl;
//        cout << cnt << endl;
        for (int i = 0; i < a.size(); i++) {
            if (vis[b[i] - '0'] || a[i] == b[i]) continue;
            int beg = b[i] - '0';
            int pos = b[i] - '0';
            vis[beg] = vis[pos] = true;
//            cout << char(beg + '0') << "-" << char(fa[pos] + '0') << endl;
            while (fa[pos] != beg) {
                if (fa[pos] == 0) break;
                vis[pos] = true;
                vis[fa[pos]] = true;
                pos = fa[pos];
                if (fa[pos] == beg) {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}