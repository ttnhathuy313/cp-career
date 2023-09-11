#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		s = ' ' + s;
		int isB = true, id = -1;
		for (int i = 1; i <= n; ++i) if (s[i] != '?') {
			if (s[i] == 'R') isB = false;
			id = i;
			break;
		}
		if (id == -1) {
			for (int i = 1; i <= n; ++i) {
				if (i & 1) cout << 'B';
				else cout << 'R';
			}
			cout << endl;
			continue;
		}
		int pre = isB ^ (id & 1);
		for (int i = 1; i <= n; ++i) {
			if (s[i] != '?') {
				cout << s[i];
				if (s[i] == 'B') pre = 1;
				else pre = 0;
			} else {
				if (pre == 0) {
					cout << 'B';
					pre = 1;
				} else {
					pre = 0;
					cout << 'R';
				}
			}
		}
		cout << endl;
	}

	return 0;
}