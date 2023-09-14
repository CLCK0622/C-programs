#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int a[45];
int f[45][805][805];
int sum[45];
int s(int a, int b, int c) {
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    s *= 100;
    return (int)s;
}
bool able(int k, int i, int j) {
    if (i + j < sum[k] - i - j) return false;
    if (sum[k] - j < j) return false;
    if (sum[k] - i < i) return false;
    if (abs(i - j) >= sum[k] - i - j) return false;
    return true;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < sum[k] / 2; i++) {
            for (int j = 0; j < sum[k] / 2; j++) {
                if (!able(k, i, j)) continue;
                
            }
        }
    }
}