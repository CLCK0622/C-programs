#include <iostream>
#include <cmath>
using namespace std;
int g, n;
struct grazing {
    int x, y, t;
} gr[100005];
struct alibis {
    int x, y, t;
} al[100005];
int ans = 0;
int main() {
    cin >> g >> n;
    for (int i = 0; i < g; i++) {
        cin >> gr[i].x >> gr[i].y >> gr[i].t;
    }
    for (int i = 0; i < n; i++) {
        cin >> al[i].x >> al[i].y >> al[i].t;
    }
    for (int i = 0; i < n; i++) {
        bool inno = true;
        for (int j = 0; j < g; j++) {
//            cout << abs(al[i].x - gr[j].x) + abs(al[i].y - gr[j].y) << endl;
//            cout << abs(al[i].t - gr[j].t) << endl;
            if (abs(al[i].x - gr[j].x) + abs(al[i].y - gr[j].y) <= -(al[i].t - gr[j].t)) {
                inno = false;
//                cout << i << " " << j << endl;
                break;
            }
        }
        if (inno) ans++;
    }
    cout << ans << endl;
    return 0;
}