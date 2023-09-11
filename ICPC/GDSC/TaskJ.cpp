#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskJ.INP", "r", stdin);
	freopen("TaskJ.OUT", "w", stdout);

	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	int A = 0, B = 0;
	for (int i = 3; i <= n; ++i) {
		A += (s[i] == 'G' && s[i - 1] == 'D' && s[i - 2] == 'G');
		B += (s[i] == 'C' && s[i - 1] == 'S' && s[i - 2] == 'D' && s[i - 3] == 'G');
	}
	cout << A << ' ' << B << endl;

	return 0;
}