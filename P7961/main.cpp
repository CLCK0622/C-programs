#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, k;
int v[105];
int fans = 0;
void dfs(int ls, int ncnt, int nans, int nsum, int ms) {
//    cout << ls << " " << ncnt << " " << nans << " " << nsum << endl;
    if (nsum == ms && ncnt == n) {
        fans += nans;
        return ;
    }
    if (nsum >= ms || ncnt >= n) return ;
    for (int i = 0; i <= min(m, (long long)log2(ms)); i++) {
        dfs(i, ncnt + 1, (nans * v[i]) % mod, nsum + pow(2, i), ms);
    }
}
signed main() {
    cin >> n >> m >> k;
    for (int i = 0; i <= m; i++) {
        cin >> v[i];
    }
    for (int i = n; i <= n * (long long)(pow(2, m)); i++) {
        if (__builtin_popcount(i) > k) continue;
        dfs(0, 0, 1, 0, i);
    }
    cout << fans << endl;
    return 0;
}