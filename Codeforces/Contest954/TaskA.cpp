#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n;
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	int l = 1;
	int res = n;
	while (l < n) {
		if (s[l] != s[l + 1]) {
			res--;
			l++;
		}
		l++;
	}
	l = n;
	int t = n;
	while (l > 1) {
		if (s[l] != s[l - 1]) {
			t--;
			l--;
		}
		l--;
	}
	cout << min(t, res) << endl;

	return 0;
}