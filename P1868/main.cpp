#include <iostream>
using namespace std;
int n, m, k;
int f[1005][205][2];
string a, b;
int main() {
    cin >> n >> m >> k;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                f[i][j][1] = max(f[i][j][1], f[i - 1][j - 1][1]);
            }
            f[i][j] = max(f[i][j])
        }
    }
}