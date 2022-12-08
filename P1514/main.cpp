#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int mp[505][505];
bool vis[505][505];
bool ed[505][505];
bool edd[505][505];
struct area {
    int l = 0x3f3f3f3f, r = 0;
} p[505];
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
struct point {
    int x, y;
};
bool in(point t) {
    return t.x > 0 && t.x <= n && t.y > 0 && t.y <= m;
}
bool cmp(area a, area b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}
inline void bfs(point beg) {
    if (edd[beg.x][beg.y]) return ;
    queue<point> q;
    q.push(beg);
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) {
        point npos = q.front();
        vis[npos.x][npos.y] = true;
        if (npos.x == n) ed[npos.x][npos.y] = true;
        if (npos.x == 1) edd[npos.x][npos.y] = true;
        q.pop();
        for (int i = 0; i < 4; i++) {
            point pp = npos;
            pp.x += dir[i][0];
            pp.y += dir[i][1];
            if (in(pp) && !vis[pp.x][pp.y] && mp[pp.x][pp.y] < mp[npos.x][npos.y]) {
                vis[pp.x][pp.y] = true;
                if (pp.x == n) ed[pp.x][pp.y] = true;
                if (pp.x == 1) edd[pp.x][pp.y] = true;
                q.push(pp);
//                cout << pp.x << " " << pp.y << " " << mp[pp.x][pp.y] << endl;
//                cout << vis[pp.x][pp.y] << endl;
//                cout << npos.x << " " << npos.y << " " << mp[npos.x][npos.y] << endl << endl;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (vis[n][i]) {
            p[beg.y].l = min(p[beg.y].l, i);
            p[beg.y].r = max(p[beg.y].r, i);
        }
    }
}
inline int work() {
    int i1 = 1, t12 = 1, ans = 0;
    while (t12 <= m) {
        int t123 = 0;
        while (p[i1].l <= t12) {
            t123 = max(t123, p[i1].r);
            i1++;
        }
        t12 = t123 + 1;
        ans++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        bfs(point{1, i});
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (ed[n][i]) cnt++;
    }
    if (cnt < m) {
        cout << 0 << endl << m - cnt << endl;
        return 0;
    } else {
        cout << 1 << endl;
        sort(p + 1, p + m + 1, cmp);
        cout << work() << endl;
//        for (int i = 1; i <= m; i++) {
//            cout << p[i].l << " " << p[i].r << endl;
//        }
    }
    return 0;
}