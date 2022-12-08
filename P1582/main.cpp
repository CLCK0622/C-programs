#include <iostream>
using namespace std;
int n, k;
int ans;
int main() {
    cin >> n >> k;
    while (__builtin_popcount(n) > k) {
        ans += (n & -n);
        n += (n & -n);
    }
    cout << ans << endl;
    return 0;
}