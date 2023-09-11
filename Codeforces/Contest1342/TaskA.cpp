#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		int u = max(x, y), v = min(x, y);
		cout << v * (min(b, 2 * a)) + (u - v) * a << endl;
	}

	return 0;
}