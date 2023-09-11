#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int n;
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	int l = 0, res = 0, o = 0, c = 0;
	bool bad = false;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == ')') {
			if (o <= c) {
				bad = true;
			}
			c++;
		} else o++;
		if (o == c) {
			if (bad) res += i - l;
			l = i;
			bad = false;
			o = c = 0;
		}
	}
	if (l != n) {
		cout << -1 << endl;
		return 0;
	}
	cout << res << endl;

	return 0;
}