#include <iostream>
#include <string>
using namespace std;
int m, n, T;
string tt[10];
string tmp;
string res;
int main() {
    cin >> T;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
//        cin >> tt[i];
        tt[i] = "yxalag";
    }
    while (n--) {
        bool allcor = true;
        bool anc = false;
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j <= 1; j++) {
                tmp = res = "";
                if (j == 0) {
                    res = "freopen(\"" + tt[i] + ".in\",\"r\",stdin);";
                } else if (j == 1) {
                    res = "freopen(\"" + tt[i] + ".out\",\"w\",stdout);";
                }
                cin >> tmp;
                if (tmp != res) allcor = false;
                if (tmp.substr(0, 10) == "//freopen(" && tmp.substr(tmp.size() - 2, 2) == ");") {
                    anc = true;
//                    cout << tmp << endl;
                }
            }
        }
        if (anc) cout << "Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI." << endl;
        else if (allcor) cout << "PION2202 RP++.\n";
        else cout << "Good luck and have fun.\n";
    }
    return 0;
}