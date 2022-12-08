#include <bits/stdc++.h>
using namespace std;
int n, m;
struct shop {
    int s, t, p, c;
} d[100005];

bool cmp(shop a, shop b) {
    return a.ls > b.ls;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].s >> d[i].t >> d[i].p >> d[i].c;
    }
}