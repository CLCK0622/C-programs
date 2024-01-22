#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int a[1000005];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mxt = -1, nnum = 0, t = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            if (t > mxt) {
                mxt = t;
                nnum = a[i - 1];
                t = 1;
            }
        } else {
            t ++;
        }
    }
    if (mxt > floor(1.0 * n / 2)) {
        cout << nnum << endl;
    } else {
        cout << "No" << endl;
    }
//    for (int i = 0; i < n; i++) {
//        int x;
//        cin >> x;
//        if (s.find(x) != s.end()) {
//            num[cnt++] = x, times[cnt]++;
//        } else {
//            s.insert(x);
//        }
//    }
//    for (int i = 0; i < cnt; i++) {
//        cout << num[i] << " : " << times[i] << endl;
//    }
//    int mx = -1, npos = 0;
//    for (int i = 0; i < cnt; i++) {
//        if (times[i] > mx) {
//            mx = times[i]; npos = i;
//        }
//    }
//    if (mx > floor(1.0 * n / 2)) {
//        cout << num[npos] << endl;
//    } else {
//        cout << "No" << endl;
//    }
    return 0;
}