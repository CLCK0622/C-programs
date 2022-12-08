#include <iostream>
using namespace std;
int t;
int n;
string s;
int v[125];
int main() {
    freopen("moon.in", "r", stdin);
    freopen("moon.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        cin >> s;
        cout << s.size() * v[1] << endl;
        return 0;
    }
}