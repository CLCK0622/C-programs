#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
const int maxn = 100005;
int ans[4 * maxn], a[maxn];
inline void build(int id, int l, int r) {
    if (l == r) {
        ans[id] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    ans[id] = max(ans[id << 1], ans[id << 1 | 1]);
}
inline void pushup(int id) {
    ans[id] = max(ans[id << 1], ans[id << 1 | 1]);
}
inline void update(int id, int l, int r, int x, int y, int v) {
    if (l == r) {
        ans[id] %= v;
        return ;
    }
    if (x <= l && r <= y) {
    	if (ans[id] < v) return ;
	}
    int mid = (l + r) >> 1;
    if (x <= mid) {
        update(id << 1, l, mid, x, y, v);
    }
	if (y > mid) {
        update(id << 1 | 1, mid + 1, r, x, y, v);
    }
    pushup(id);
}
inline void change(int id, int l, int r, int x, int v) {
	if (l == r) {
		ans[id] = v;
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) {
		change(id << 1, l, mid, x, v);
	} else {
		change(id << 1 | 1, mid + 1, r, x, v);
	}
	pushup(id);
}
inline int query(int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return ans[id];
    }
    int mid = (l + r) >> 1;
    int ans = 0;
    if (x <= mid) {
        ans = max(ans, query(id << 1, l, mid, x, y));
    }
    if (y > mid) {
        ans = max(ans, query(id << 1 | 1, mid + 1, r, x, y));
    }
    return ans;
}
signed main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, k;
            cin >> x >> k;
            change(1, 1, n, x, k);
        } else if (t == 3) {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        } else if (t == 2) {
            int x, y, k;
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }
    }
    return 0;
}
