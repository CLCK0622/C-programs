#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[1000005];
bool pri[1000005];
void is_prime() {
    memset(pri, 1, sizeof(pri));
    pri[1] = 0;
    pri[2] = 1;
    for (int i = 2; i * 2 <= m; i++) {
        if (pri[i]) {
            for (int j = i * 2; j <= m; j += i) {
                pri[j] = 0;
            }
        }
    }
}
void init() {
    for (int i = 2; i <= m; i++) {
        if (pri[i]) {
            cnt[i] = cnt[i - 1] + 1;
        } else {
            cnt[i] = cnt[i - 1];
        }
    }
}
void print() {
    for (int i = 1; i <= m; i++) {
        cout << pri[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
}
int main() {
    cin >> n >> m;
    is_prime();
    init();
//    print();
    while (n--) {
        int l, r;
        cin >> l >> r;
        if (l < 1 || r > m) {
            cout << "Crossing the line" << endl;
            continue;
        }
        cout << cnt[r] - cnt[l - 1] << endl;
    }
    return 0;
}