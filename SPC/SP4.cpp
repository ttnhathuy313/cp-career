#include <bits/stdc++.h>

using namespace std;
#define int long long 

map <string, int> mp;
string s;
int getnum(int i) {
	int num = 0;
	while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
		num = num * 10 + (s[i] - '0');
	}
	return num;
}

void solve() {
	mp.clear();
	cin >> s;
	string cur;
	cur.clear();
	cerr << s << endl;
	for (int i = 0; i < s.size(); ++i) if (s[i] >= 'A' && s[i] <= 'Z') {
		if (i < s.size() - 1 && s[i + 1] >= 'a' && s[i + 1] <= 'z') {
			int cnt = 1;
			string T; T.clear(); T += s[i]; T += s[i + 1];
			cerr << T << endl;
			if (i + 2 >= s.size()) cnt = 1;
			else cnt = getnum(i + 2);
			mp[T] += cnt;
		} else {
			string T; T.clear(); T += s[i];
			int cnt;
			cerr << T << endl;
			if (i + 1 >= s.size()) cnt = 1;
			else cnt = getnum(i + 1);
			mp[T] += cnt;
		}
	}
	int L = -1;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			L = i;
			break;
		}
	}
	if (~L) {
		for (int i = L + 1; i < s.size(); ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z') {
					int cnt = 1;
					string T; T.clear(); T += s[i]; T += s[i + 1];
					if (i + 2 >= s.size()) cnt = 1;
					else cnt = getnum(i + 2);
					mp[T] += cnt;
				} else {
					string T; T.clear(); T += s[i];
					int cnt;
					if (i + 1 >= s.size()) cnt = 1;
					else cnt = getnum(i + 1);
					mp[T] += cnt;
				}
			}
			if (s[i] == ')') break;
		}
	}
	int tot = mp.size();
	int val = 0;
	string f; f.clear();
	for (int i = 1; i <= tot; ++i) {
		string t;
		cin >> t;
		string T = t.substr(0, (int)t.size() - 1);
		int sz;
		cin >> sz;
		if (sz == -1) {
			f = T;
			continue;
		}
		val += sz * mp[T];
	}
	cout << -val / mp[f] << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SPC4.INP", "r", stdin);
	freopen("SPC4.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}