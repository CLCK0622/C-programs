#include <iostream>
#include <cstdio>
using namespace std;
const int mn = 100005;
int T, n, k, ct;
char s[mn], as[mn];
int main() {
    cin >> T;
    while (T--) {
        ct = 0;
        cin >> n >> k;
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++)
            as[i] = '.';
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'G') {
                as[min(k + i, n)] = 'G';
                i = min(k + i, n) + k;
                ct++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'H') {
                if (as[min(k + i, n)] == 'G') {
                    as[min(k + i, n) - 1] = 'H';
                } else {
                    as[min(k + i, n)] = 'H';
                }
                i = min(k + i, n) + k;
                ct++;
            }
        }
        cout << ct << endl;
        for (int i = 1; i <= n; i++)
            cout << as[i];
        cout << endl;
    }
    return 0;
}
