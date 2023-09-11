#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int tag[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int n;
	cin >> n;
	string s;
	cin >> s;
	n = s.size();
	s = ' ' + s;
	string re = s;
	vector <int> res;
	res.clear();
	if (s[1] == 'W') {
		res.push_back(1);
		if (s[2] == 'W') s[2] = 'B';
		else s[2] = 'W';
		s[1] = 'B';
	}
	bool ok = true;
	for (int i = 2; i <= n; ++i) {
		if (s[i] == 'W') {
			if (tag[i] == 1) continue;
			if (i == n) {
				ok = false;
				break;
			}
			if (s[i + 1] == 'B') {
				int last = i;
				for (int j = i + 1; j <= n; ++j) {
					if (s[j] == 'W') break;
					last++;
				}
				if (last == n) {
					ok = false;
					break;
				}
				for (int j = i; j < last; ++j) {
					res.push_back(j);
				}
				s[last] = 'W';
			} else {
				tag[i + 1]++;
				res.push_back(i);
			}
		}
	}
	memset(tag, 0, sizeof tag);
	if (ok) {
		cout << res.size() << endl;
		for (int d : res) cout << d << ' ';
		return 0;
	}
	s = re;
	res.clear();
	if (s[1] == 'B') {
		res.push_back(1);
		if (s[2] == 'B') s[2] = 'W';
		else s[2] = 'B';
		s[1] = 'W';
	}
	ok = true;
	for (int i = 2; i <= n; ++i) {
		if (s[i] == 'B') {
			if (tag[i] == 1) continue;
			if (i == n) {
				ok = false;
				break;
			}
			if (s[i + 1] == 'W') {
				int last = i;
				for (int j = i + 1; j <= n; ++j) {
					if (s[j] == 'B') break;
					last++;
				}
				if (last == n) {
					ok = false;
					break;
				}
				for (int j = i; j < last; ++j) {
					res.push_back(j);
				}
				s[last] = 'B';
			} else {
				tag[i + 1]++;
				res.push_back(i);
			}
		}
	}
	if (ok) {
		cout << res.size() << endl;
		for (int d : res) cout << d << ' ';
		return 0;
	}
	cout << -1 << endl;

	return 0;
}