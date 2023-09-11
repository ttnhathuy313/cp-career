#include <bits/stdc++.h>

using namespace std;

string show(int a) {
	string s;
	while (a) {
		s += char((a % 2) + '0');
		a /= 2;
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < 32 - s.size(); ++i) s = '0' + s;
	return s;
}

bool check(string s) {
	int cnt = (s[0] == '1');
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '1' && s[i - 1] == '0') cnt++;
		if (cnt == 2) return false;
	}
	if (s[s.size() - 1] == '1') return false;
	return true;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TPOWER.INP", "r", stdin);
	freopen("TPOWER.OUT", "w", stdout);

	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) if (i + j == (1 << 5)) {
			cerr << show(i) << ' ' << show(j) << "	" << show(i ^ j) << endl;
		}
	}
	cerr << endl;
	for (int i = 1; i < (1 << 5); ++i) {
		for (int j = 1; j < (1 << 5); ++j) if (check(show(i ^ j))) {
			cerr << i + j << endl;
		}
	}

	return 0;
}