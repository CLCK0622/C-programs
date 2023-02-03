#include <iostream>
using namespace std;
int n, sum;
int a[100005];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ncnt = 0;
    bool nowL = false;
    int npos = 0;
    while (ncnt < sum) {
        if (a[npos] >= 2) {
            cout << 'R';
            a[npos] --; ncnt ++;
            npos++;
        } else if (a[npos - 1] >= 2 || npos == n) {
            cout << 'L';
            a[npos] -= 1;
            ncnt += 1;
            npos--;
        }
    }
//    for (int i = 0; i < n; i++) cout << a[i] << " ";
//    cout << ncnt << " " << sum << endl;
    return 0;
}