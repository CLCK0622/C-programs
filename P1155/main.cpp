#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int n;
int a[1005];
int f[1005];
int color[1005];
bool flag;
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
    queue<int> q;
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
            } else {
                color[y] = 3 - color[xx];
                q.push(y);
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(f, 0x3f, sizeof f);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 0; i--) {
        f[i] = min(f[i + 1], a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (f[j + 1] < a[i] && a[i] < a[j]) {
                flag = true;
                add(i, j);
                add(j, i);
                //                cout << i << " " << j << endl;
            }
        }
    }
    //    for (int i = 0; i < n; i++) cout << f[i] << " ";
    //    cout << endl;
    for (int i = 1; i <= n; i++) {
        if (color[i])
            continue;
        if (!bfs(i)) {
            cout << 0 << endl;
            return 0;
        }
    }
    int sum = 1;
    int i = 1;
    int p1 = 1001, p2 = 1001;
    char out[5] = {'0', 'a', 'b', 'c', 'd'};
    int t[2005] = {0};
    int k = 0;
    while (k < 2 * n) {
        if (!s[1].empty())
            p1 = s[1].top();
        if (!s[2].empty())
            p2 = s[2].top();
        if (color[i] == 1 && (a[i] < p1 || s[1].empty()))
            s[1].push(a[i]), t[++k] = 1, ++i;
        else if (p1 == sum)
            ++sum, t[++k] = 2, s[1].pop();
        else if (color[i] == 2 && (a[i] < p2 || s[2].empty()))
            s[2].push(a[i]), t[++k] = 3, ++i;
        else if (p2 == sum)
            ++sum, t[++k] = 4, s[2].pop();
    }
    for (int i = 1; i <= 2 * n; i++) {
        cout << out[t[i]] << " ";
    }
    return 0;
}