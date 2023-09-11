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
		int a, b;
		cin >> a >> b;

		a = abs(a); b = abs(b);

		if (a == b) {
			cout << a * 2 << endl;
			continue;
		}

		cout << min(a, b) * 2 + 2 * (max(a, b) - min(a, b)) - 1 << endl;
	}

	return 0;
}