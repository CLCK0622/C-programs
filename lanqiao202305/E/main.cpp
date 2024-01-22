#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, ans;
int a[1000005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int mina = a[(n + 1) / 2], maxa = a[n];
    for (int i = 1; i <= n; i++) {
        if (a[i] > mina) maxa = min(maxa, a[i]);
    }
    int tmpcnt1 = 0, tmpcnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < mina) tmpcnt1 ++;
        if (a[i] > maxa) tmpcnt2 ++;
    }
    int tmp = max(tmpcnt1, tmpcnt2);
    if (tmpcnt1 > tmpcnt2 + 1) maxa = mina;
    if (tmpcnt2 > tmpcnt1 + 1) mina = maxa;
    ans += (tmp + 1) * tmp;
    cout << ans << " " << mina << " " << maxa << endl;
//    for (int i = 1; i <= n; i++) {
//        cout << a[i] << " ";
//    }
    return 0;
}