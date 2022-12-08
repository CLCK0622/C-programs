#include <bits/stdc++.h>
using namespace std;
int n;
int maxa, mina, sum;
int num[55];
int a[70];
void dfs(int res, int sum, int tar, int p) {
    if (res == 0) {
        cout << tar << endl;
        exit(0);
    }
    if (sum == tar) {
        dfs(res - 1, 0, tar, maxa);
        return ;
    }
    if (sum >= tar) return ;
    for (int i = p; i >= mina; i--) {
        if (num[i] && sum + i <= tar) {
            num[i]--;
            dfs(res, sum + i, tar, i);
            num[i]++;
            if (sum == 0 || sum + i == tar) break;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
        num[a[i]] ++;
        sum += a[i];
    }
    for (int i = maxa; i <= sum; i++) {
        if (sum % i == 0) {
            dfs(sum / i, 0, i, maxa);
        }
    }
    return 0;
}