#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 0;
int n, ans;
int num[3005];
int a[3005];
void dfs(int max, int cnt) {
    if (cnt == n) {
        for (int i = 1; i <= n; i++) {
            a[i] += num[i] * num[i] % mod;
            a[i] %= mod;
        }
        return ;
    }
    for (int i = 1; i <= max + 1; i++) {
        if (i <= max) {
            num[i] ++;
            dfs(max, cnt + 1);
            num[i] --;
        } else {
            num[i] ++;
            dfs(max + 1, cnt + 1);
            num[i] --;
        }
    }
}
signed main() {
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> mod;
    num[1] = 1;
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}