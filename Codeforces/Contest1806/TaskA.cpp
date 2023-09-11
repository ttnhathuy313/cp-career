#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (d < b) {
			cout << -1 << endl;
			continue;
		}
		int require = d - b;
		int na = a + require;
		if (na < c) {
			cout << -1 << endl;
			continue;
		}
		int res = require + na - c;
		cout << res << endl;
	}

	return 0;
}