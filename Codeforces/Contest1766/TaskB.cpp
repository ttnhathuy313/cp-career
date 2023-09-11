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
		string s;
		cin >> n;
		cin >> s;
		set <string> S;
		S.clear();
		s = ' ' + s;
		bool ok = false;
		for (int i = 3; i <= n; ++i) {
			string t = "";
			t += s[i - 3];
			t += s[i - 2];
			S.insert(t);
			string compare = "";
			compare += s[i - 1];
			compare += s[i];
			if (S.find(compare) != S.end()) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}