#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int n;
int a[1005];
int f[1005];
int color[1005];
bool flag;
queue<int> q;
int head[1005];
stack<int> s[3];
struct node {
    int to, nxt;
} e[1005];
int tot;
void add(int a, int b) {
    e[++tot].to = b;
    e[tot].nxt = head[a];
    head[a] = tot;
}
bool bfs(int x) {
    q.push(x);
    color[x] = 1;
    while (!q.empty()) {
        int xx = q.front();
        q.pop();
        for (int i = head[xx]; i; i = e[i].nxt) {
            int y = e[i].to;
            if (color[y]) {
                if (color[y] != 3 - color[xx])
                    return false;
            }
            color[y] = 3 - color[xx];
            q.push(y);
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(f, 0x3f, sizeof f);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        f[i] = min(f[i + 1], a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (f[j + 1] < a[i] && a[i] < a[j]) {
                flag = true;
                add(i, j); add(j, i);
//                cout << i << " " << j << endl;
            }
        }
    }
//    for (int i = 0; i < n; i++) cout << f[i] << " ";
//    cout << endl;
    for (int i = 0; i < n; i++) {
        if (!flag) break;
        if (color[i]) continue;
        if (!bfs(i)) {
            cout << 0 << endl;
            return 0;
        }
    }
    int cnt = 0;
    int sum = 1;
    int i = 0;
    while (cnt < n) {
        if (color[i] == 1 && (a[i] < s[1].top() || s[1].empty())) {
            s[1].push(a[i + 1]);
            cout << "a ";
            i++; cnt ++;
        } else {
            if (s[1].top() == sum) {
                sum ++;
                cout << "b ";
                s[1].pop();
            }
        }
        if (color[i] == 2 && (a[i] < s[2].top() || s[2].empty())) {
            s[2].push(a[i + 1]);
            cout << "c ";
            i++; cnt ++;
        } else {
            if (s[2].top() == sum) {
                sum ++;
                cout << "d ";
                s[2].pop();
            }
        }
    }
    return 0;
}