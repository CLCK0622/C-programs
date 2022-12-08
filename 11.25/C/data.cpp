#include <bits/stdc++.h>
using namespace std;
bool vis[25];
vector<int> rt;
void dfs(int cnt, int n) {
    if (cnt == n) {
        cout << check() << endl;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] || i != n) {

        }
    }
}
int main() {
    freopen();
    for (int n = 1; n <= 20; n++) {
        for (int i = 2; i <= n; i++) {
            vis[i] = 1;
            rt.push_back(i);
            dfs(1, n);
            vis[i] = 0;
            rt.pop_back();
        }
    }
    return 0;
}