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
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if ((y - x) % (a + b) != 0) {
			cout << -1 << endl;
		} else cout << (y - x) / (a + b) << endl;
	}

	return 0;
}