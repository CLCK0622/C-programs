#include <iostream>
using namespace std;
int t;
string tmp = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
int main() {
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        if (tmp.find(s) != string::npos) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}