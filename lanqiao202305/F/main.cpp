#include <iostream>
#include <vector>
using namespace std;
int n;
int fa[100005];
vector<int> son[100005];
int num[100005];
int ans = 0, sum = 0;
bool vis[100005];
void dfs(int nn, int sum) {
    if (nn >= n) { ans = max(ans, sum); return; }
    if (!vis[fa[nn + 1]]) {
        vis[nn + 1] = true;
        dfs(nn + 1, sum + num[nn + 1]);
        vis[nn + 1] = false;
    }
    dfs(nn + 1, sum);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int f, s, c;
        cin >> f >> s >> c;
        fa[s] = f; num[s] = c;
        son[f].push_back(s);
    }
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j < son[i].size(); j++) {
//            cout << son[i][j] << "-" << num[son[i][j]] << " ";
//        }
//        cout << endl;
//    }
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}