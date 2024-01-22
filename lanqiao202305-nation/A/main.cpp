#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
bool checkrev(int x) {
    string s;
    while (x != 0) {
        s += (x % 8) + '0';
        x /= 8;
    }
    string ss = s;
    reverse(ss.begin(), ss.end());
    return s == ss;
}
int main() {
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        if (checkrev(i * i)) {
            cout << i * i << " ";
        }
    }
    cout << endl;
    return 0;
}