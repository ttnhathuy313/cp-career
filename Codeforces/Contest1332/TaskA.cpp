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
		int a, b, c, d, x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
		int ax = x + b - a;
		if (a + b != 0 && x == x1 && x == x2) {
			cout << "No\n";
			continue;
		}
		int ay = y + d - c;
		if (c + d != 0 && y == y1 && y == y2) {
			cout << "No\n";
			continue;
		}
		if (ax >= x1 && ax <= x2 && ay >= y1 && ay <= y2) {
			cout << "Yes\n";
		} else cout << "No\n";
	}

	return 0;
}