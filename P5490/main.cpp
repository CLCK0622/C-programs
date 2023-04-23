#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int lazy[100000 << 3];
double s[100000 << 3];
int temp = 1, n;
double x1, y1, x2, y2, ans;
struct nd1 {
    double l, r;
    double sum;
} cl[100000 << 3];
struct nd2 {
    double x, y1, y2;
    int flag;
} p[100000 << 3];

bool cmp(nd2 a, nd2 b) {
    return a.x < b.x;
}

void pushup(int rt) {
    if (lazy[rt] > 0) {
        cl[rt].sum = cl[rt].r - cl[rt].l;
    } else {
        cl[rt].sum = cl[rt * 2].sum + cl[rt * 2 + 1].sum;
    }
}

void build(int rt, int l, int r) {
    if (r - l > 1) {
        cl[rt].l = s[l];
        cl[rt].r = s[r];
        build(rt * 2, l, (l + r) / 2);
        build(rt * 2 + 1, (l + r) / 2, r);
        pushup(rt);
    } else {
        cl[rt].l = s[l];
        cl[rt].r = s[r];
        cl[rt].sum = 0;
    }
    return;
}

void update(int rt, double y1, double y2, int flag) {
    if (cl[rt].l == y1 && cl[rt].r == y2) {
        lazy[rt] += flag;
        pushup(rt);
        return;
    } else {
        if (cl[rt * 2].r > y1) {
            update(rt * 2, y1, min(cl[rt * 2].r, y2), flag);
        }
        if (cl[rt * 2 + 1].l < y2) {
            update(rt * 2 + 1, max(cl[rt * 2 + 1].l, y1), y2, flag);
        }
        pushup(rt);
    }
}

int main() {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        p[i].x = x1;
        p[i].y1 = y1;
        p[i].y2 = y2;
        p[i].flag = 1;
        p[i + n].x = x2;
        p[i + n].y1 = y1;
        p[i + n].y2 = y2;
        p[i + n].flag = -1;
        s[i + 1] = y1;
        s[i + n + 1] = y2;
    }
    sort(s + 1, s + n * 2 + 1);
    sort(p, p + n * 2, cmp);
    build(1, 1, n * 2);
    memset(lazy, 0, sizeof(lazy));
    update(1, p[0].y1, p[0].y2, p[0].flag);
    for (int i = 1; i < n * 2; i++) {
        ans += cl[1].sum * (p[i].x - p[i - 1].x);
        update(1, p[i].y1, p[i].y2, p[i].flag);
    }
    cout << ans << endl;
    return 0;
}