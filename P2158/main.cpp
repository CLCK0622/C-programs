#include <bits/stdc++.h>
using namespace std;
int n;
bool pri[40005];
int euler[40005];
void init() {
    memset(pri, 1, sizeof(pri));
    pri[1] = 0;
    euler[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (pri[i]) {
            euler[i] = i - 1;
            for (int j = i * 2; j <= n; j += i) {
                pri[j] = 0;
                if (!euler[j]) euler[j] = j;
                euler[j] = euler[j] / i * (i - 1);
            }
//            cout << i << " " << euler[i] << endl;
        }
    }
}
void eul() {
    for (int i = 1; i <= n; i++) {
        euler[i] = i;
        for (int j = 1; j <= i; j++) {
            if (pri[j] && (i % j == 0)) {
                euler[i] /= j;
                euler[i] *= j - 1;
            }
        }
    }
}
int main() {
    cin >> n;
    init();
    //eul();
    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans += euler[i];
    }
    if (n == 1) cout << 0 << endl;
    else cout << (ans - 1) * 2 + 1 << endl;
//    for (int i = 1; i < n; i++) {
//        cout << euler[i] << " ";
//    }
//    cout << endl;
    return 0;
}
