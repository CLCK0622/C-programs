#include <iostream>
#include <cstring>
using namespace std;
int n;
int fa[1005];
int md[1005];
int dep[1005];
int main() {
    cin >> n;
    memset(md, 0x3f, sizeof md);
    for (int i = 1; i <= n; i++) {
        cin >> fa[i];
        md[i] = min(md[i], md[fa[i]] + 1);
        dep[i] = dep[fa[i]] + 1;
    }

}