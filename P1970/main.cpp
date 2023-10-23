#include <iostream>
using namespace std;
int n;
int h[100005];
int f[100005][2] = {0};
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (h[i] > h[i - 1]) f[i][0] = f[i - 1][1] + 1;
        else f[i][0] = f[i - 1][0];
        if (h[i] < h[i - 1]) f[i][1] = f[i - 1][0] + 1;
        else f[i][1] = f[i - 1][1];
    }
    cout << max(f[n][0], f[n][1]) << endl;
    return 0;
}