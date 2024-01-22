#include <iostream>
using namespace std;
int n, m, cnt = 1;
int tmp[10000005];
int pri[100005];
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void init() {
    pri[0] = 2;
    for (int i = 3; i * i <= 10000000; i++) {
        if (isPrime(i)) {
            pri[cnt++] = i;
        }
    }
}
int main() {
    init();
    cin >> n >> m;
    int ans = 0;
    for (int i = n; i <= m; i++) {
        if (tmp[i]) continue;
        int ii = i;
        for (int j = 0; j < cnt; j++) {
            while (ii % pri[j] == 0) {
                tmp[i]++;
                ii /= pri[j];
            }
        }
        for (int j = 0; j < cnt; j++) {
            if (i * pri[j] > m) break;
            tmp[i * pri[j]] = tmp[i] + 1;
        }
    }
    for (int i = n; i <= m; i++) {
        ans = max(ans, tmp[i]);
    }
    cout << ans << endl;
//    for (int i = 0; i < 100; i++) {
//        cout << pri[i] << " ";
//    }
    return 0;
}

//#include <iostream>
//using namespace std;
//int n, m, cnt = 1;
//int tmp[10000005];
//int pri[100005];
//bool isPrime(int x) {
//    for (int i = 2; i * i <= x; i++) {
//        if (x % i == 0) return false;
//    }
//    return true;
//}
//void init() {
//    pri[0] = 2;
//    for (int i = 3; i * i <= 10000000; i++) {
//        if (isPrime(i)) {
//            pri[cnt++] = i;
//        }
//    }
//}
//int main() {
//    init();
//    cin >> n >> m;
//    int ans = 0;
//    for (int i = n; i <= m; i++) {
//        if (tmp[i]) continue;
//        int ii = i;
//        for (int j = 0; j < cnt; j++) {
//            while (ii % pri[j] == 0) {
//                tmp[i]++;
//                ii /= pri[j];
//            }
//        }
//        for (int j = 0; j < cnt; j++) {
//            ii = i;
//            while (ii * pri[j] <= m && !tmp[ii * pri[j]]) {
//                tmp[ii * pri[j]] = tmp[ii] + 1;
//                ii *= pri[j];
//            }
//            if (i * pri[j] > m) break;
//        }
//    }
//    for (int i = n; i <= m; i++) {
//        ans = max(ans, tmp[i]);
//    }
//    cout << ans << endl;
////    for (int i = 0; i < 100; i++) {
////        cout << pri[i] << " ";
////    }
//    return 0;
//}