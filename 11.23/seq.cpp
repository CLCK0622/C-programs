#include <iostream>
#include <cmath>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int t;
int k1, k2, x, y, ax, ay, z;
double pp(double x, int t) {
    double ans = 1;
    while (t--) {
        ans *= x;
        // ans %= mod;
    }
    return ans;
}
int work() {
    k1 *= -1, k2 *= -1;
    int dlt = k1 * k1 - 4 * k2;
    double x1 = (-1.0 * k1 + sqrt(1.0 * dlt)) / 2;
    double x2 = (-1.0 * k1 - sqrt(1.0 * dlt)) / 2;
    double t1 = pp(x1, x);
    double t2 = pp(x2, x);
    double t3 = pp(x1, y);
    double t4 = pp(x2, y);
    double c1 = ((1.0 * t4 / t2) * ax - 1.0 * ay) / (1.0 * t1 * t4 / t2 - 1.0 * t3);
    double c2 = ((1.0 * t1 / t3) * ay - 1.0 * ax) / (1.0 * t1 * t4 / t3 - 1.0 * t2);
    return (long long)((c1 * pp(x1, z)) + (c2 * pp(x2, z))) % mod;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> k1 >> k2 >> x >> y >> ax >> ay >> z;
        cout << work() << endl;
    }
    return 0;
}
