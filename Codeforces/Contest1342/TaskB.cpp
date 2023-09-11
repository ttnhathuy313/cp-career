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
		string s;
		cin >> s;
		bool ok = true;
		for (int i = 0; i < s.size() - 1; ++i) if (s[i] != s[i + 1]) ok = false;
		if (!ok) {
			for (int i = 1; i <= 2 * (s.size()); ++i) if (i & 1) cout << 1; else cout << 0;
			cout << endl;
		} else {
			for (int i = 1; i <= s.size(); ++i) cout << s[0];
			cout << endl;
		}
	}

	return 0;
}