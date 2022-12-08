#include <bits/stdc++.h>
using namespace std;
int t;
int cnt1[100005], cnt2[100005];
bool vis[100005];
int lft[100005], rgt[100005];
void init() {
    memset(vis, 0, sizeof(vis));
    memset(lft, 0, sizeof(lft));
    memset(rgt, 0, sizeof(rgt));
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
}
bool check1(int t, string s) {
    int pos;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            pos = i; break;
        }
    }
//    cout << cnt1[pos] << " " << cnt2[pos] << endl;
    return (cnt1[pos] == cnt2[pos] || cnt1[pos] == cnt2[pos] - 1);
}
bool check(int t, string s) {
//    cout << t << " " << cnt1[t] << " " << cnt2[t] << endl;
    if (cnt1[t] == cnt2[t] || cnt1[t] == cnt2[t] - 1) return 1;
    if (cnt1[t] > cnt2[t]) {
        int tpp = 0;
        for (int i = 0; i < t; i++) {
            if (vis[i]) tpp = max(tpp, min(cnt1[i], cnt2[t] - cnt2[i]));
        }
        return (cnt1[t] - cnt2[t] <= tpp * 2);
    }
    if (cnt1[t] < cnt2[t]) {
        int tpp = 0;
        for (int i = t + 1; i < s.size(); i++) {
            if (vis[i]) tpp = max(tpp, min(cnt1[i] - cnt1[t], cnt2[i]));
        }
        return (cnt2[t] - cnt1[t] <= tpp * 2 + rgt[t]);
    }
}
bool work(string s) {
    int tmp, num;
    bool flag;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            num++;
            lft[i] = num;
            vis[i] = 1;
            cnt1[i] = tmp;
        } else {
            tmp++;
        }
    }
    tmp = 0, flag = 0, num = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            num++;
            rgt[i] = num;
            vis[i] = 1;
            cnt2[i] = tmp;
        } else {
            tmp++;
        }
    }
    tmp = 0x3f3f3f3f;
    int bg = 0x3f3f3f3f;
    for (int i = 0; i < s.size(); i++) {
        if (vis[i]) {
            if (abs(cnt1[i] - cnt2[i]) < tmp && (cnt1[i] > cnt2[i] ? lft[i] : (cnt1[i] >= cnt2[i] - 1 || rgt[i]))) {
                bg = i;
                tmp = abs(cnt1[i] - cnt2[i]);
            }
        }
    }
//    cout << endl << bg << endl;
//    cout << cnt1[bg] << " " << cnt2[bg] << endl;
    if (num == 1) return check1(num, s);
    if (num == 0) return false;
    if (bg == 0x3f3f3f3f) return false;
    if (cnt1[bg] == cnt2[bg]) return true;
    return check(bg, s);
}
int main() {
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        init();
        string s;
        cin >> s;
        cout << (work(s) ? "YES" : "NO") << endl;
    }
    return 0;
}