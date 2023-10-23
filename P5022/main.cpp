#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> a[5005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}