#include <bits/stdc++.h>
using namespace std;
int nn = 100000, mm = 100000;
int main() {
	freopen("test.in", "w", stdout); 
    srand((unsigned)time(NULL));
    cout << nn << " " << mm << endl;
    for (int i = 1; i <= nn; i++) {
        cout << rand() % int(1e9 - 5) << " ";
    }
    cout << endl;
    while (mm--) {
        int t = rand() % 3 + 1;
        cout << t << " ";
        if (t == 1) {
            cout << rand() % nn + 1 << " " << rand() % (int(1e9) - 5) + 1 << endl;
        } else if (t == 2) {
            int l = rand() % nn + 1;
            cout << l << " " << l + rand() % (nn - l) + 1 << " " << rand() % nn << endl;
        } else {
            int l = rand() % nn + 1;
            cout << l << " " << l + rand() % (nn - l) + 1 << endl;
        }
    }
    return 0;
}
