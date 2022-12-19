#include <iostream>
#include <cstdio>
using namespace std;
int a, b;
int t;
int main() {
    cin >> t;
    while (t--) {
        scanf("%d+%d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}
