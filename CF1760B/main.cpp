#include <iostream>
using namespace std;
int t;
int main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt = max(cnt, s[i] - 'a' + 1);
        }
        cout << cnt << endl;
    }
    return 0;
}