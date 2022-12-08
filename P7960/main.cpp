#include <bits/stdc++.h>
using namespace std;
int t;
int ct, cnt;
const int maxa = 1e7 + 5;
bool is[maxa];
int num[maxa];
int fal[maxa];
bool check(int t) {
    if (t % 7 == 0) return true;
    while (t) {
        if (t % 10 == 7) return true;
        t /= 10;
    }
    return false;
}
void init() {
    memset(is, 1, sizeof(is));
    for (int i = 1; i < maxa; i++) {
        if (is[i] && check(i)) is[i] = 0;
        if (is[i]) {
            num[++ct] = i;
        }
        if (!is[i]) {
            fal[++cnt] = i;
            for (int j = 1; j * fal[cnt] <= maxa; j++) {
                is[j * fal[cnt]] = 0;
            }
        }
    }
}
int main() {
    cin >> t;
    init();
    while (t--) {
        int k;
        cin >> k;
        int kpos = lower_bound(num + 1, num + ct + 1, k) - num;
//        cout << kpos << endl;
        if (num[kpos] != k) {
            cout << -1 << endl;
        } else {
            cout << num[kpos + 1] << endl;
        }
    }
//    for (int i = 1; i < 100; i++) {
//        cout << fal[i] << " ";
//    }
    return 0;
}