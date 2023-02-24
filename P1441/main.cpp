#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, m, ans;
set<int> ansSet;
int a[25];
void dfs(int npos, int ncnt, int nans) { //nans = sum, ncnt = num not added
    if (npos > n) return ;
    if (npos == n && ncnt == m) {
        if (nans != 0 && ansSet.find(nans) == ansSet.end()) {
            ansSet.insert(nans);
            cout << nans << endl;
            ans ++;
        }
        return ;
    }
    dfs(npos + 1, ncnt, nans + a[npos]);
    dfs(npos + 1, ncnt + 1, nans);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}