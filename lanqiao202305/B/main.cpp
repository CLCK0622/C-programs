#include <iostream>
using namespace std;
int n, m;
bool check(int x) {
    int ans = 0;
    int xx = x;
    while (xx) {
        int digit = xx % 10;
        ans += digit * digit * digit * digit;
        xx /= 10;
    }
    return x == ans;
}
int main() {
    cin >> n >> m;
    for (int i = max(n, 1000); i <= min(9999, m); i++) {
        if (check(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}