#include <iostream>
#include <cstring>
using namespace std;
int n, cnt;
string mp[105];
int tp[105]; // 1 byte 2 short 3 int 4 long
int beg[105], end[105];
int sz[105] = {0, 1, 2, 4, 8};
int def[105] = {0, 1, 2, 4, 8};
int stnm;
int pos;
struct st {
	string name;
	int cnt;
	string mp[105];
	int tp[105];
	int beg[105], end[105];
} st[105];
int main() {
	//freopen("struct.in", "r", stdin);
	//freopen("struct.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int op = 0;
		cin >> op;
		if (op == 1) {
			string lb; cin >> lb;
			st[stnm].name = lb;
			int x; cin >> x;
			st[stnm].cnt = x;
			for (int j = 0; j < x; j++) {
				string t, lbb;
				cin >> t >> lbb;
				mp[i] = lbb;
				if (t == "byte") st[stnm].tp[j] = 1;
				else if (t == "short") st[stnm].tp[j] = 2;
				else if (t == "int") st[stnm].tp[j] = 3;
				else if (t == "long") st[stnm].tp[j] = 4;
				def[stnm + 5] = max(def[stnm + 5], sz[st[stnm].tp[j]]);
			}
			int poss = 0;
			for (int j = 0; j < x; j++) {
				if (poss % sz[st[stnm].tp[j]] != 0) {
					poss = (poss / sz[st[stnm].tp[j]] + 1) * sz[st[cnt].tp[i]];
				}
				st[stnm].beg[j] = poss;
				st[stnm].end[j] = poss + sz[st[cnt].tp[cnt]] - 1;
			}
			if (poss % def[stnm + 5] == 0) sz[stnm + 5] = poss;
			else sz[stnm + 5] = (poss / def[stnm + 5] + 1) * def[stnm + 5];
			stnm++;
		} else if (op == 2) {
			string t; string lb;
			cin >> t >> lb;
			mp[cnt] = lb;
			if (t == "byte") tp[cnt] = 1;
			else if (t == "short") tp[cnt] = 2;
			else if (t == "int") tp[cnt] = 3;
			else if (t == "long") tp[cnt] = 4;
			else {
				for (int j = 0; j < n; j++) {
					if (t == st[j].name) {
						tp[cnt] = j + 5;
					}
				}
			}
			if (pos % def[tp[cnt]] != 0) {
				pos = (pos / def[tp[cnt]] + 1) * def[tp[cnt]];
			}
			beg[cnt] = pos;
			end[cnt] = pos + sz[tp[cnt]] - 1;
			pos = end[cnt] + 1;
			cnt++;
		} else if (op == 3) {
			string s;
			cin >> s;
			int stpos = -1;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == '.') stpos = j;
			}
			if (stpos != -1) {
				string lb1 = s.substr(0, stpos);
				string lb2 = s.substr(stpos + 1, n - stpos - 1);
				for (int j = 0; j < n; j++) {
					if (mp[j] == lb1) {
						for (int k = 0; k < st[tp[j]].cnt; k++) {
							if (st[tp[j]].mp[k] == lb2) {
								cout << beg[j] + st[tp[j]].beg[k] << endl;
								break;
							}
						}
					}
				}
			} else {
				for (int j = 0; j < n; j++) {
					if (mp[j] == s) {
						cout << beg[j] << endl;
						break;
					}
				}
			}
		} else if (op == 4) {
			int addr;
			cin >> addr;
			for (int j = 0; j < n; j++) {
				if (addr >= beg[j] && addr <= end[j]) {
					if (tp[j] <= 4)
						cout << mp[j] << endl;
					else {
						for (int k = 0; k < st[tp[j]].cnt; k++) {
							if (addr >= beg[j] + st[tp[j]].beg[k] && addr <= beg[j] + st[tp[j]].end[k]) {
								cout << mp[j] + '.' + st[tp[j]].mp[k] << endl;
								break;
							} else if (addr < beg[j] + st[tp[j]].end[k] && addr < beg[j] + st[tp[j]].beg[k + 1]) {
								cout << "ERR" << endl;
								break;
							}
						}
					}
					break;
				} else if (addr > end[j] && addr < beg[j + 1]) {
					cout << "ERR" << endl;
					break;
				}
			}
		}
	}
	return 0;
}
