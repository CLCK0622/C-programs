#include <iostream>
using namespace std;
int n, m, k;
int a[10];
int mp[105][105];
int calc(int x, int k) {
    int sum = 0;
    for (int i = 0; i <= k; i++) {
        int tmp = 1;
        for (int j = 1; j <= i; j++) {
            tmp *= x;
        }
        sum += a[i] * tmp;
    }
    return sum;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i <= k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        mp[i][calc(i, k)] = 1;
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (mp[j][i]) cout << "*";
            else cout << ".";
        }
        cout << endl;
    }
    return 0;
}