#include <iostream>
#include <cmath>
using namespace std;
int n;
int ppow(int n, int x) {
    int ans = 1;
    while (x--) {
        ans *= n;
    }
    return ans;
}
int main() {
    cin >> n;
    if (n % 2 != 0) {
        cout << -1 << endl;
    } else {
        while (n != 0) {
            int x = log2(n);
            int ans = ppow(2, x);
            cout << ans << " ";
            n -= ans;
        }
    }
    return 0;
}