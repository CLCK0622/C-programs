#include <cstdio>
#include <iostream>

using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

long long ST[100010][25];
int LG[100010];
int n, m;

void init() {
    for (int i = 1; i <= LG[n]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            ST[j][i] = max(ST[j][i - 1], ST[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int main() {
    LG[1] = 0, LG[2] = 1;
    for (int i = 3; i <= 2000000; i++) {
        LG[i] = LG[i / 2] + 1;
    }
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
        ST[i][0] = read();
    }
    init();
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read();
        int s = r - l + 1;
        long long ans = max(ST[l][LG[s]], ST[r - (1 << LG[s]) + 1][LG[s]]);
        printf("%lld\n", ans);
    }
}