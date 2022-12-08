#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define INF 0x3f3f3f3f
#define mpa make_pair
typedef pair<int, int> PII;
typedef tree<PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update> Tree;
Tree tr;
int n;
int tr_clock;
template<typename T>
int getOrder(T x) {
    return tr.order_of_key(x) + 1;
}

template<typename T>
T getValue(int k) {
    auto it = tr.find_by_order(k - 1);
    if (it != tr.end())
        return *it;
    else
        return mpa(INF, 0);
}
int main() {
    cin >> n;
    int op, x;
    while (n--) {
        cin >> op;
        cin >> x;
        tr_clock++;
        if (op == 1) {
            tr.insert(mpa(x, tr_clock));
        } else if (op == 2) {
            auto it = tr.upper_bound(mpa(x, 0));
            tr.erase(it);
        } else if (op == 3) {
            int k = getOrder<PII>(mpa(x, 0));
            cout << k << endl;
        } else if (op == 4) {
            auto v = getValue<PII>(x);
            cout << v.first << endl;
        } else if (op == 5) {
            auto it = tr.upper_bound(mpa(x, 0));
            --it;
            auto v = *it;
            cout << v.first << endl;
        } else if (op == 6) {
            auto v = *tr.upper_bound(mpa(x, INF));
            cout << v.first << endl;
        }
    }
    return 0;
}