#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
int f[2505];
vector<int> a[2505];
int main() {
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}