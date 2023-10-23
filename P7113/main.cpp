#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v[100005];
int f[100005];
int d[100005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        for (int j = 1; j <= d[i]; j++) {
            int x; cin >> x;
            if (x) v[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v[i].size(); j++) {
            int t = v[i][j - 1];
        }
    }
}