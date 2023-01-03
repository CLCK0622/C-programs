#include <iostream>
#include <algorithm>
using namespace std;
int T;
int a[105], b[105];
long long sum;
int main() {
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; sum += a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + m, greater<int>());
        for (int i = 0; i < m; i++) {
            sum -= a[i]; sum += b[i];
        }
        cout << sum << endl;
    }
    return 0;
}