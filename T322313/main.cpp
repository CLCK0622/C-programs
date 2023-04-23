#include <iostream>
using namespace std;
int N;
char keyboard[4][8] = {
        {'*', '*', '*', 'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'},
        {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z', '*', '*', '*'}
};
int exist[400000];
int nex[100000][300], cnt;
void insert(string s, int l) {
    int p = 0;
    for (int i = 0; i < l; i++) {
        int c = s[i] - 'a';
        if (!nex[p][c]) nex[p][c] = ++cnt;
        p = nex[p][c];
        exist[p] += 1;
    }
    exist[p] += 1;
}
bool find(string s, int l) {
    int p = 0;
    for (int i = 0; i < l; i++) {
        int c = s[i] - 'a';
        if (!nex[p][c]) return false;
        p = nex[p][c];
    }
    return exist[p];
}
int main() {
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        insert(s, s.length());
    }
    string prompt;
    cin >> prompt;
    for (int i = 0; i < 32; i++) {
        char tmp = keyboard[i / 8][i % 8];
        if (!find(prompt + tmp, prompt.length() + 1) || tmp == '*') {
            cout << '*';
        } else {
            cout << tmp;
        }
        if (i % 8 == 7) cout << endl;
    }
    return 0;
}