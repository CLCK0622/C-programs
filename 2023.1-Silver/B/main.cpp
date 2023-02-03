#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct pos {
    bool isPost;
    int cost;
    char dir;
    pos(bool b, int i) {
        isPost = b;
        cost = i;
        dir = 'N';
    }
    pos(bool b, char i) {
        isPost = b;
        dir = i;
        cost = 0;
    }
    pos() {
        isPost = false;
        cost = 0;
        dir = 'N';
    }
    void flip() {
        if (dir == 'D') dir = 'R';
        else if (dir == 'R') dir = 'D';
    }
} poss[1505][1505];
int N;
void cost() {
    queue<pair<int, int> > bfs_queue;
    for (int j = 1; j <= N; j++) {
        if (poss[j][N].dir == 'R') {
            bfs_queue.push({j, N});
        }
    }
    for (int j = 1; j <= N; j++) {
        if (poss[N][j].dir == 'D') {
            bfs_queue.push({N, j});
        }
    }
    while (!bfs_queue.empty()) {
        pair<int, int> beg = bfs_queue.front();
        bfs_queue.pop();
        if (poss[beg.first][beg.second].dir == 'D') {
            poss[beg.first][beg.second].cost = poss[beg.first + 1][beg.second].cost;
        } else {
            poss[beg.first][beg.second].cost = poss[beg.first][beg.second + 1].cost;
        }
        if (poss[beg.first - 1][beg.second].dir == 'D') {
            bfs_queue.push({beg.first - 1, beg.second});
        }
        if (poss[beg.first][beg.second - 1].dir == 'R') {
            bfs_queue.push({beg.first, beg.second - 1});
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += poss[i][j].cost;
        }
    }
    cout << ans << endl;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j <= N + 1; j++) {
            if (i == N + 1 && j == N + 1) continue;
            if (i == N + 1 || j == N + 1) {
                int num;
                cin >> num;
                poss[i][j] = pos(false, num);
            } else {
                char dir;
                cin >> dir;
                poss[i][j] = pos(true, dir);
            }
        }
    }
    cost();
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        poss[x][y].flip();
        cost();
    }
    return 0;
}
