#include <iostream>
#include <cstring>
using namespace std;
string s;
int pi[1000005];
void count() {
    int n = s.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}
int main() {
    int n; cin >> n;
    cin >> s;
    count();
    cout << n - pi[n - 1] << endl;
    return 0;
}