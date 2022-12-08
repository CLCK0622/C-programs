#include <bits/stdc++.h>
using namespace std;
int n, k, q, cnt;
int lim[500005];
struct stu {
    int tp, sc, fm;
    bool operator> (const stu& a) const {
return sc > a.sc;
}
bool operator< (const stu& a) const {
    return sc < a.sc;
}
} mp[500005];
int num[500005];
priority_queue<stu, vector<stu>, greater<stu> > eve;
priority_queue<stu, vector<stu>, greater<stu> > all, con;
priority_queue<stu, vector<stu>, greater<stu> > s[500005];
void adding(stu tmp) {
    eve.push(tmp);
    if (con.size() < k) {
        con.push(tmp);
    } else {
        if (con.top().sc < tmp.sc) {
            con.pop();
            con.push(tmp);
        }
    }
    priority_queue<stu, vector<stu>, less<stu> > out;
    int ans = 0;
    if (tmp.tp == 0) {
        if (tmp.sc >= con.top().sc) {
            ans++;
            out.push(tmp);
        }
    }
    if (tmp.tp == 1) {
        if (all.size() < k && num[tmp.fm] < k) {
            all.push(tmp);
            num[tmp.fm]++;
            s[tmp.fm].push(tmp);
            ans++;
            out.push(tmp);
        } else if (all.size() >= k) {
            if (all.top().sc < tmp.sc) {
                if (num[tmp.fm] < k) {
                    num[all.top().fm]--;
                    s[all.top().fm].pop();
                    all.pop();
                    all.push(tmp);
                    s[tmp.fm].push(tmp);
                    num[tmp.fm]++;
                    ans++;
                    out.push(tmp);
                } else {
                    if (tmp.sc > s[tmp.fm].top().sc) {
                        s[tmp.fm].pop();
                        s[tmp.fm].push(tmp);
                        ans++;
                        out.push(tmp);
                    }
                }
            }
        }
    }
    while (!out.empty()) {
        cout << out.top().fm << " " << out.top().sc << endl;
        out.pop();
    }
}
void del(stu t) {
    priority_queue<stu, vector<stu>, greater<stu> > add;
    priority_queue<stu, vector<stu>, less<stu> > out;
    priority_queue<stu, vector<stu>, greater<stu> > tmp;
    while (!eve.empty()) {
        if (eve.top().sc != t.sc) {
            tmp.push(eve.top());
        }
        eve.pop();
    }
    eve = tmp;
    while (!tmp.empty()) tmp.pop();
    while (!all.empty()) {
        int cnt = 0;
        bool fg = 0;
        if (all.top().sc != t.sc) {
            tmp.push(all.top()), cnt++;
            if (cnt == k && fg) {
                //add.push(all.top());
            }
        } else fg = 1;
        all.pop();
    }
    all = tmp;
    while (!tmp.empty()) tmp.pop();
    while (!con.empty()) {
        int cnt = 0;
        bool fg = 0;
        if (con.top().sc != t.sc) {
            tmp.push(all.top()), cnt++;
            if (cnt == k && fg && !t.tp) {
                add.push(con.top());
            }
        } else fg = 1;
        con.pop();
    }
    con = tmp;
    while (!tmp.empty()) tmp.pop();
    while (!s[t.fm].empty()) {
        int cnt = 0;
        bool fg = 0;
        if (s[t.fm].top().sc != t.sc) {
            tmp.push(s[t.fm].top()), cnt++;
            if (cnt == k && fg && t.tp) {
                add.push(s[t.fm].top());
            }
        } else fg = 1;
        s[t.fm].pop();
    }
    s[t.fm] = tmp;
    while (!tmp.empty()) tmp.pop();
    while (!add.empty()) {
        adding(add.top());
        add.pop();
    }
}
void print() {
    priority_queue<stu, vector<stu>, greater<stu> > prt = all;
    while (!prt.empty()) {
        cout << prt.top().sc << endl;
        prt.pop();
    }
}
int main() {
    freopen("bjoi.in", "r", stdin);
    freopen("bjoi.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> lim[i];
    }
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> mp[cnt].tp >> mp[cnt].fm >> mp[cnt++].sc;
            stu tmp = mp[cnt - 1];
            adding(tmp);
        } else if (type == -1) {
            stu tmp;
            cin >> tmp.tp >> tmp.fm >> tmp.sc;
            del(tmp);
        }
    }
    print();
    return 0;
}
