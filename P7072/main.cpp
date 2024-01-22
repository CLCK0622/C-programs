#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, w;
int a[100005];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        cin >> x; a[i] = x;
        sort(a, a + i, cmp);
        int p = max(1, p * w / 100);
        cout << a[p] << " ";
    }
    return 0;
}