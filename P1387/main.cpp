#include <iostream>
using namespace std;
int n, m;
int mp[105][105];
int sum[105][105];
bool check(int k) {
    for (int i = 1; i <= n - k; i++) {
        for (int j = 1; j <= m - k; j++) {
            if (sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j] == k * k) {
//                cout << sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j] << endl;
                return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 1) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + 1;
            } else {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << sum[i][j] << " ";
//        }
//        cout << endl;
//    }
    for (int k = min(n, m); k >= 1; k--) {
        if (check(k)) {
            cout << k << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}