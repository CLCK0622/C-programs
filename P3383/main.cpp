#include <bits/stdc++.h>
using namespace std;
int n, q;
const int maxn = 1e8 + 5;
bool isp[maxn];
int pri[maxn];
void init(int n) {
    memset(isp, 1, sizeof(isp));
    isp[1] = 0;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (isp[i])
            pri[++cnt] = i;
        for (int j = 1; j <= cnt && i * pri[j] <= n; j++) {
            isp[i * pri[j]] = 0;
            if (i % pri[j] == 0)
                break;
        }
    }
}
int main() {
    cin >> n >> q;
    init(n);
    while (q--) {
        int k;
        cin >> k;
        cout << pri[k] << endl;
    }
//    for (int i = 1; i < 1000; i++) {
//        cout << pri[i] << " ";
//    }
    return 0;
}