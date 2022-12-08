#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int main() {
    cin >> n >> l >> r;
    if (r / n > l / n) {
        cout << n - 1 << endl;
    } else {
        cout << r % n << endl;
    }
    return 0;
}