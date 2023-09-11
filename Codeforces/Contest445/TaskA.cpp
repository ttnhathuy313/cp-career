#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		s = ' ' + s;
		for (int j = 1; j <= m; ++j) {
			if (s[j] == '-') {
				cout << '-';
				continue;
			}
			if (i & 1) {
				if (j & 1) cout << 'W';
				else cout << "B";
			} else {
				if (j & 1) cout << "B";
				else cout << "W";
			}
		}
		cout << endl;
	}

	return 0;
}