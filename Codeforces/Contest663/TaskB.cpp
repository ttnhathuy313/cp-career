#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);
	freopen("TaskB.out", "w", stdout);

	map<string, string> mp;
	for (int i = 1989; i <= 100000; i++) {
		string s; s.clear();
		int d = i;
		while (d) {
			char c = char('0' + d % 10);
			d /= 10;
			s = c + s;
		}
		for (int j = 1; j <= s.size(); j++) {
			string t = s.substr(s.size() - j, j);
			if (mp.count(t) == 0) {
				mp[t] = s;
				break;
			}
		}
	}
	int tc;
	cin >> tc;
	while (tc--) {
		string f;
		cin >> f;
		string s; s.clear();
		for (int i = 4; i < f.size(); ++i) s += f[i];
		if (mp.count(s)) {
			cout << mp[s] << endl;
		} else {
			if (s.size() == 5 && "00000" <= s && s <= "13098") {
				s = "1" + s;
			} else if (s.size() == 6 && "000000" <= s && s <= "113098") {
				s = "1" + s;
			} else if (s.size() == 7 && "0000000" <= s && s <= "1113098") {
				s = "1" + s;
			} else if (s.size() == 8 && "00000000" <= s && s <= "11113098") {
				s = "1" + s;
			} else if (s.size() == 9 && "000000000" <= s && s <= "111113098") {
				s = "1" + s;
			} else if (s.size() == 10 && "0000000000" <= s && s <= "1111113098") {
				s = "1" + s;
			}
			cout << s << endl;
		}
	}
 	return 0;
}