#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[100005];
signed main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    int ta = 0;
    int it = 0;
    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N; i++) {
        int cnt = N - i + 1;
        int ans = cnt * a[i];
        if (ans > ta) {
            ta = ans;
            it = a[i];
        }
    }
    cout << ta << " " << it << endl;
    return 0;
}